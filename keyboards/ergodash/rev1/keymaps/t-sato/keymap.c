#include QMK_KEYBOARD_H
#include "action_layer.h"
#include "eeconfig.h"

extern keymap_config_t keymap_config;

#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _ADJUST 16

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST,
  MCR_EN8KANA,
  MCR_RCOPY,
  MCR_LCOPY,
  MCR_RWMOVE,
  MCR_LWMOVE,
};

enum {
  TD_EXT1 = 0,
  TD_EXT2,
};

#define EISU LALT(KC_GRV)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* Qwerty
   * ,----------------------------------------------------------------------------------------------------------------------.
   * | EQL  |  1   |  2   |  3   |  4   |  5   |      |                    |      |  6   |  7   |  8   |  9   |  0   | MINS |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * | TAB  |  Q   |  W   |  E   |  R   |  T   | ESC  |                    |MCR_LC|  Y   |  U   |  I   |  O   |  P   | BSLS |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * | LCTL |  A   |  S   |  D   |  F   |  G   |MCR_EN|                    |MCR_RC|  H   |  J   |  K   |  L   | SCLN | QUOT |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * | LSFT |  Z   |  X   |  C   |  V   |  B   | LGUI |                    | RGUI |  N   |  M   | COMM | DOT  | SLSH | RSFT |
   * |-------------+------+------+------+------+------+------+------+------+------+------+------+------+------+-------------|
   * |LOWER | GRV  | LEFT | RGHT |||||||| SPC  | BSPC | LCTL |||||||| RALT | ENT  |  UP  |||||||| DOWN | LBRC | RBRC |RAISE |
   * ,----------------------------------------------------------------------------------------------------------------------.
   */
  [_QWERTY] = LAYOUT( \
    KC_EQL,     KC_1,   KC_2,    KC_3,    KC_4,    KC_5,    KC_NO,          KC_NO,     KC_6,   KC_7,  KC_8,    KC_9,    KC_0,    KC_MINS,  \
    KC_TAB,     KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,    KC_ESC,         TD(TD_EXT1), KC_Y,   KC_U,  KC_I,    KC_O,    KC_P,    KC_BSLS,  \
    KC_LCTL,    KC_A,   KC_S,    KC_D,    KC_F,    KC_G,    MCR_EN8KANA,    TD(TD_EXT2), KC_H,   KC_J,  KC_K,    KC_L,    KC_SCLN, KC_QUOT,  \
    KC_LSFT,    KC_Z,   KC_X,    KC_C,    KC_V,    KC_B,    KC_LGUI,        KC_RGUI,   KC_N,   KC_M,  KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,  \
    OSL(_LOWER),  KC_GRV, KC_LEFT, KC_RGHT, KC_SPC,  KC_BSPC, KC_LCTL,      KC_RALT,   KC_ENT, KC_UP, KC_DOWN, KC_LBRC, KC_RBRC, TG(_RAISE)     \
  ),

  /* Lower
   * ,----------------------------------------------------------------------------------------------------------------------.
   * | F11  |  F1  |  F2  |  F3  |  F4  |  F5  |      |                    |      |  F6  |  F7  |  F8  |  F9  | F10  | F12  |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |                    |      |      |      |      |      |      |      |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |                    |      |      |      |      |      |      |      |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |                    |      |      |      |      |      |      |      |
   * |-------------+------+------+------+------+------+------+------+------+------+------+------+------+------+-------------|
   * |      |      |      |      ||||||||      |      |      ||||||||      |      |      ||||||||      |      |      |      |
   * ,----------------------------------------------------------------------------------------------------------------------.
   */
  [_LOWER] = LAYOUT( \
    KC_F11,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   _______,        _______, KC_F6,   KC_F7,   KC_F8,   KC_F9, KC_F10, KC_F12,  \
    _______, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   _______,        _______, KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_NO,  KC_NO,   \
    _______, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   _______,        _______, KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_NO,  KC_NO,   \
    _______, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   _______,        _______, KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_NO,  _______, \
    KC_TRNS, KC_NO,   _______, _______, _______, _______, _______,        _______, _______, _______, _______, KC_NO, KC_NO,  KC_TRNS\
  ),

  /* Raise
   * ,----------------------------------------------------------------------------------------------------------------------.
   * |      |      |      |      |      |      |      |                    |      |      | PEQL | PSLS | PAST |      |      |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |                    |      |  P7  |  P8  |  P9  | PMNS |      |      |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |                    |      |  P4  |  P5  |  P6  | PPLS |      |      |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |                    |      |  P1  |  P2  |  P3  | PENT |      |      |
   * |-------------+------+------+------+------+------+------+------+------+------+------+------+------+------+-------------|
   * |      |      |      |      ||||||||      |      |      ||||||||      |      |      ||||||||      |      |      |      |
   * ,----------------------------------------------------------------------------------------------------------------------.
   */
  [_RAISE] = LAYOUT(
    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   _______,        _______, KC_NO,   KC_PEQL, KC_PSLS, KC_PAST, KC_NO,  KC_NO,   \
    _______, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   _______,        _______, KC_P7,   KC_P8,   KC_P9,   KC_PMNS, KC_NO,  KC_NO,   \
    _______, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   _______,        _______, KC_P4,   KC_P5,   KC_P6,   KC_PPLS, KC_NO,  KC_NO,   \
    _______, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   _______,        _______, KC_P1,   KC_P2,   KC_P3,   KC_PENT, KC_NO,  _______, \
    KC_TRNS, KC_NO,   _______, _______, _______, _______, _______,        _______, _______, _______, _______, KC_NO,   KC_NO,  KC_TRNS\
  ),

  /* Adjust
   * ,----------------------------------------------------------------------------------------------------------------------.
   * |      |      |      |      |      |      |      |                    |      |      |      |      |      |      |      |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |                    |      |      |      |      |      |      |      |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |                    |      |      |      |      |      |      |      |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |                    |      |      |      |      |      |      |      |
   * |-------------+------+------+------+------+------+------+------+------+------+------+------+------+------+-------------|
   * |      |      |      |      ||||||||      |      |      ||||||||      |      |      ||||||||      |      |      |      |
   * ,----------------------------------------------------------------------------------------------------------------------.
   */
  [_ADJUST] = LAYOUT(
      _______, _______, _______, _______, _______, _______, _______,         _______, _______, _______, _______, _______, _______, _______, \
      _______, _______, _______, _______, _______, _______, _______,         _______, _______, _______, _______, _______, _______, _______, \
      _______, _______, _______, _______, _______, _______, _______,         _______, _______, _______, _______, _______, _______, _______, \
      _______, _______, _______, _______, _______, _______, _______,         _______, _______, _______, _______, _______, _______, _______, \
      _______, _______, _______, _______, _______, _______, _______,         _______, _______, _______, _______, _______, _______, _______  \
    )
};

/*
 * Macros
 * https://beta.docs.qmk.fm/features/feature_macros
 */

void copy_to_r(void) {
  SEND_STRING(
    SS_DOWN(X_LALT)
    SS_DOWN(X_LSHIFT)
    SS_TAP(X_RIGHT)
    SS_UP(X_LSHIFT)
    SS_UP(X_LALT)
    SS_LGUI(SS_TAP(X_C))
  );
}

void copy_to_l(void) {
  SEND_STRING(
    SS_DOWN(X_LALT)
    SS_DOWN(X_LSHIFT)
    SS_TAP(X_LEFT)
    SS_UP(X_LSHIFT)
    SS_UP(X_LALT)
    SS_LGUI(SS_TAP(X_C))
  );
}

void move_to_window_r(void) {
  SEND_STRING(SS_LCTRL(SS_TAP(X_RIGHT)));
}

void move_to_window_l(void) {
  SEND_STRING(SS_LCTRL(SS_TAP(X_LEFT)));
}

/*
 * Tap Dance
 * https://docs.qmk.fm/#/feature_tap_dance?id=example-1-send-on-single-tap-on-double-tap
 */

void dance_ext_key1(qk_tap_dance_state_t *state, void *user_data) {
  if (state->count > 1) {
    copy_to_l();

    reset_tap_dance(state);
  } else {
    move_to_window_l();
  }
}

void dance_ext_key2(qk_tap_dance_state_t *state, void *user_data) {
  if (state->count > 1) {
    copy_to_r();

    reset_tap_dance(state);
  } else {
    move_to_window_r();
  }
}

qk_tap_dance_action_t tap_dance_actions[] = {
  [TD_EXT1] = ACTION_TAP_DANCE_FN(dance_ext_key1),
  [TD_EXT2] = ACTION_TAP_DANCE_FN(dance_ext_key2),
};



#ifdef AUDIO_ENABLE
float tone_qwerty[][2]     = SONG(QWERTY_SOUND);
#endif

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    /*
     * Macros
     * https://beta.docs.qmk.fm/features/feature_macros
     */
    case MCR_EN8KANA:
      if (record->event.pressed) {
        // when keycode pressed
        SEND_STRING(SS_LGUI(SS_TAP(X_SPACE)));
      } else {
        // when keycode released
      }
      break;
    case MCR_RCOPY:
      if (record->event.pressed) {
        // when keycode pressed
        copy_to_r();
      } else {
        // when keycode released
      }
      break;
    case MCR_LCOPY:
      if (record->event.pressed) {
        // when keycode pressed
        copy_to_l();
     } else {
        // when keycode released
      }
      break;
    case MCR_RWMOVE:
      if (record->event.pressed) {
        // when keycode pressed
        move_to_window_r();
      } else {
        // when keycode released
      }
      break;
    case MCR_LWMOVE:
      if (record->event.pressed) {
        // when keycode pressed
        move_to_window_l();
      } else {
        // when keycode released
      }
      break;

    // case QWERTY:
    //   if (record->event.pressed) {
    //     // print("mode just switched to qwerty and this is a huge string\n");
    //     set_single_persistent_default_layer(_QWERTY);
    //   }
    //   return false;
    //   break;
    // case LOWER:
    //   if (record->event.pressed) {
    //     layer_on(_LOWER);
    //     update_tri_layer(_LOWER, _RAISE, _ADJUST);
    //   } else {
    //     layer_off(_LOWER);
    //     update_tri_layer(_LOWER, _RAISE, _ADJUST);
    //   }
    //   return false;
    //   break;
    // case RAISE:
    //   if (record->event.pressed) {
    //     layer_on(_RAISE);
    //     update_tri_layer(_LOWER, _RAISE, _ADJUST);
    //   } else {
    //     layer_off(_RAISE);
    //     update_tri_layer(_LOWER, _RAISE, _ADJUST);
    //   }
    //   return false;
    //   break;
    // case ADJUST:
    //   if (record->event.pressed) {
    //     layer_on(_ADJUST);
    //   } else {
    //     layer_off(_ADJUST);
    //   }
    //   return false;
    //   break;
  }
  return true;
}

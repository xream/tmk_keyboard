#include "keymap_common.h"
#include "macro_str.h"
/*
,-----------------------------------------------------------.
|ESC|  1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|    Bsp|
|-----------------------------------------------------------|
|Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|  \  |
|-----------------------------------------------------------|
|CapsL |  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  '|  Return|
|-----------------------------------------------------------|
|Shift   |  Z|  X|  C|  V|  B|  N|  M|  ,|  ,|Shift| Up |  /|
|-----------------------------------------------------------|
|Ctl|Gui|Alt|           Space           |PgU|PgD|Lef|Dow|Rig|
`-----------------------------------------------------------'
*/
#define KEYMAP_XREAM( \
  K29,K1E,K1F,K20,K21,K22,K23,K24,K25,K26,K27,K2D,K2E,K2A, \
  K2B,K14,K1A,K08,K15,K17,K1C,K18,K0C,K12,K13,K2F,K30,K31, \
  K39,K04,K16,K07,K09,K0A,K0B,K0D,K0E,K0F,K33,K34,    K28, \
  KE1,K1D,K1B,K06,K19,K05,K11,K10,K36,K37,    KE5,K52,K38, \
  KE0,KE3,KE2,        K2C,            K4E,K4B,K50,K51,K4F  \
) KEYMAP_ALL( \
          NO ,NO ,NO ,NO ,NO ,NO ,NO ,NO ,NO ,NO ,NO ,NO ,                                             \
  K29,    NO ,NO ,NO ,NO ,NO ,NO ,NO ,NO ,NO ,NO ,NO ,NO ,      NO ,NO ,NO ,  NO ,NO ,NO ,NO , NO,     \
  NO ,K1E,K1F,K20,K21,K22,K23,K24,K25,K26,K27,K2D,K2E,NO ,K2A,  NO ,NO ,K4B,  NO ,NO ,NO ,NO , NO, NO, \
  K2B,K14,K1A,K08,K15,K17,K1C,K18,K0C,K12,K13,K2F,K30,    K31,  NO ,NO ,K4E,  NO ,NO ,NO ,NO , NO, NO, \
  K39,K04,K16,K07,K09,K0A,K0B,K0D,K0E,K0F,K33,K34,    NO ,K28,                NO ,NO ,NO ,NO , NO, NO, \
  KE1,NO ,K1D,K1B,K06,K19,K05,K11,K10,K36,K37,K38,    NO ,KE5,      K52,      NO ,NO ,NO ,NO , NO, NO, \
  KE0,KE3,KE2,NO ,NO ,    K2C,    NO ,NO ,NO ,NO ,NO ,NO ,NO ,  K50,K51,K4F,  NO ,    NO ,NO , NO, NO  \
)

const uint8_t keymaps[][MATRIX_ROWS][MATRIX_COLS] PROGMEM = {
  KEYMAP_XREAM(
    GRV , 1  ,   2,   3,   4,   5,   6,   7,   8   ,9  , 0   ,MINS,EQL ,BSPC, \
    FN0 , Q  ,   W,   E,   R,   T,   Y,   U,   I   ,O  , P   ,LBRC,RBRC,FN1 , \
    FN2 , A  ,   S,   D,   F,   G,   H,   J,   K   ,L  , SCLN,QUOT,     ENT , \
    FN3 , Z  ,   X,   C,   V,   B,   N,   M,   COMM,DOT, FN4 ,     UP  ,F15 , \
    FN5 , FN6, FN7,           FN8,                  F13, F14 ,LEFT,DOWN,RGHT  \
  ),
  KEYMAP_XREAM(
    FN20, F1  , F2  , F3  , F4  , F5  , F6  , F7  , F8  , F9  , F10 , F11 , F12 , DEL , \
    TRNS, FN9 , FN10, FN11, FN12, FN13, FN14, MRWD, MPLY, MFFD, MUTE, VOLD, VOLU, FN15, \
    TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, LEFT, DOWN, UP  , RGHT, TRNS,TRNS ,       TRNS, \
    TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, HOME, PGDN, PGUP, END , TRNS,       TRNS, TRNS, \
    TRNS, TRNS, TRNS,             TRNS,                   TRNS, TRNS, TRNS, TRNS, TRNS  \
  ),
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {
  switch (id) {
    case 0:
      return (record->event.pressed ?
        S_SYSPWD :
        MACRO_NONE );
  }
  return MACRO_NONE;
}

const action_t fn_actions[] PROGMEM = {

  [0]  = ACTION_LAYER_TAP_KEY(1, KC_TAB),
  [1]  = ACTION_LAYER_TAP_KEY(1, KC_BSLS),
  [2]  = ACTION_MODS_TAP_KEY(MOD_LCTL, KC_ESC),
  [3]  = ACTION_MODS_TAP_KEY(MOD_LSFT, KC_F19),
  [4]  = ACTION_MODS_TAP_KEY(MOD_LSFT | MOD_LCTL | MOD_LALT | MOD_LGUI, KC_SLSH),
  [5]  = ACTION_MODS_TAP_KEY(MOD_LCTL, KC_F18),
  [6]  = ACTION_MODS_TAP_KEY(MOD_LALT, KC_F17),
  [7]  = ACTION_MODS_TAP_KEY(MOD_LGUI, KC_F16),
  [8]  = ACTION_MODS_TAP_KEY(MOD_LCTL | MOD_LALT | MOD_LGUI, KC_SPC),
  [9]  = ACTION_MODS_KEY(MOD_LGUI | MOD_LALT | MOD_LCTL | MOD_LSFT, KC_F19),
  [10] = ACTION_MODS_KEY(MOD_LGUI | MOD_LALT | MOD_LSFT, KC_F19),
  [11] = ACTION_MODS_KEY(MOD_LGUI | MOD_LCTL | MOD_LSFT, KC_F19),
  [12] = ACTION_MODS_KEY(MOD_LALT | MOD_LCTL | MOD_LSFT, KC_F19),
  [13] = ACTION_MODS_KEY(MOD_LGUI | MOD_LALT | MOD_LCTL, KC_F19),
  [14] = ACTION_MODS_KEY(MOD_LGUI | MOD_LALT, KC_F19),
  [15] = ACTION_MODS_KEY(MOD_LGUI | MOD_LCTL, KC_F19),

  [20] = ACTION_MACRO(0),
};

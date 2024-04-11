#include <bits/stdc++.h>

using namespace std;

int xp, yp, xv, yv;

int main() {
  cin >> xp >> yp >> xv >> yv;
  if (xv >= xp && yv >= yp) {
    cout << "Polycarp" << endl;
    return 0;
  }
  if (xv <= xp && yv <= yp) {
    cout << "Vasiliy" << endl;
    return 0;
  }
  int t = 0;
  if (xv > xp) {
    t = xv - xp;
    if (xv - xp > yv) {
      if (yp <= t) {
        cout << "Polycarp";
      } else {
        cout << "Vasiliy";
      }
    } else {
      if (yp <= yv) {
        cout << "Polycarp";
      } else {
        cout << "Vasiliy";
      }
    }
  } else {
    t = (yv - yp);
    if (yv - yp > xv) {
      if (xp <= t) {
        cout << "Polycarp";
      } else {
        cout << "Vasiliy";
      }
    } else {
      if (xp <= xv) {
        cout << "Polycarp";
      } else {
        cout << "Vasiliy";
      }
    }
  }
  return 0;
}
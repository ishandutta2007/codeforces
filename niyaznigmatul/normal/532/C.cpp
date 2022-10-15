#include <bits/stdc++.h>

using namespace std;

int main() {
  int xp, yp, xv, yv;
  cin >> xp >> yp >> xv >> yv;
  int mp = xp + yp;
  int mv = max(xv, yv);
  if ((xv >= xp && yv >= yp) || mv >= mp) {
    puts("Polycarp");
  } else {
    puts("Vasiliy");
  }
  return 0;
}
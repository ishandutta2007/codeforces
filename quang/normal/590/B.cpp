#include <bits/stdc++.h>

using namespace std;

int X1, Y1, X2, Y2, vmax;
int vx, vy, wx, wy, t;

long double sqr(long double x) {
  return x * x;
}

bool check(long double val) {
  long double curx, cury;
  if (val < t) {
    curx = X1 + vx * val;
    cury = Y1 + vy * val;
  } else {
    curx = X1 + vx * t + wx * (val - t);
    cury = Y1 + vy * t + wy * (val - t);
  }
  long double dis = sqrt(sqr(X2 - curx) + sqr(Y2 - cury));
  return vmax * val >= dis;
}

int main() {
  cin >> X1 >> Y1 >> X2 >> Y2;
  cin >> vmax >> t;
  cin >> vx >> vy >> wx >> wy;
  long double l = 0, r = 1e9;
  for (int i = 1; i <= 100000; i++) {
    long double m = (l + r) * 0.5;
    if (check(m)) {
      r = m;
    } else {
      l = m;
    }
  }
  printf("%0.17f", (double)(l + r) * 0.5);
    return 0;
}
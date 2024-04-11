#include <bits/stdc++.h>

using namespace std;

double x, y, z;

char ss[][100] = {
  "x^y^z", "x^z^y", "(x^y)^z", "(x^z)^y",
  "y^x^z", "y^z^x", "(y^x)^z", "(y^z)^x",
  "z^x^y", "z^y^x", "(z^x)^y", "(z^y)^x"
};

long double get(double x, double y, double z, int f) {
  if (x <= 1.0000000000000001) {
    return -100000000000.0;
  }
  if (f) {
    return log(y) + log(z) + log(log(x));
  }
  return log(y) * z + log(log(x));
}

void findmin() {
  long double a[12], res = 1000000000.0;
  a[0] = get(1.0 / x, y, z, 0);
  a[1] = get(1.0 / x, z, y, 0);
  a[2] = get(1.0 / x, y, z, 1);
  a[3] = get(1.0 / x, z, y, 1);
  a[4] = get(1.0 / y, x, z, 0);
  a[5] = get(1.0 / y, z, x, 0);
  a[6] = get(1.0 / y, x, z, 1);
  a[7] = get(1.0 / y, z, x, 1);
  a[8] = get(1.0 / z, x, y, 0);
  a[9] = get(1.0 / z, y, x, 0);
  a[10] = get(1.0 / z, x, y, 1);
  a[11] = get(1.0 / z, y, x, 1);
  for (int i = 0; i < 12; i++) {
    res = min(res, a[i]);
  }
  int ans = -1;
  for (int i = 0; i < 12; i++) {
    if (abs(res - a[i]) < 1e-15) {
      ans = i;
      break;
    }
  }
  cout << ss[ans];
}

int main() {
  scanf("%lf %lf %lf", &x, &y, &z);
  if (x <= 1.0 && y <= 1.0 && z <= 1.0) {
    findmin();
  }
  long double a[12], res = -1000000000.0;
  a[0] = get(x, y, z, 0);
  a[1] = get(x, z, y, 0);
  a[2] = get(x, y, z, 1);
  a[3] = get(x, z, y, 1);
  a[4] = get(y, x, z, 0);
  a[5] = get(y, z, x, 0);
  a[6] = get(y, x, z, 1);
  a[7] = get(y, z, x, 1);
  a[8] = get(z, x, y, 0);
  a[9] = get(z, y, x, 0);
  a[10] = get(z, x, y, 1);
  a[11] = get(z, y, x, 1);
  for (int i = 0; i < 12; i++) {
    res = max(res, a[i]);
  }
  int ans = -1;
  for (int i = 0; i < 12; i++) {
    if (abs(res - a[i]) < 1e-15) {
      ans = i;
      break;
    }
  }
  cout << ss[ans];
  return 0;
}
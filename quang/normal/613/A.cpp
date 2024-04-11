#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

struct point {
  double x, y;

  point (int xx = 0, int yy = 0) {
    x = xx;
    y = yy;
  }

  void read() {
    scanf("%lf %lf", &x, &y);
  }

  point operator - (const point &u) const {
    return point(x - u.x, y - u.y);
  }
};

int n;
point A, a[N];

double dis(point u) {
  return sqrt(u.x * u.x + u.y * u.y);
}

double dot(point u, point v) {
  return u.x * v.x + u.y * v.y;
}

double cross(point u, point v) {
  return u.x * v.y - u.y * v.x;
}

int sign(double x) {
  double e = 1e-9;
  return x < -e ? -1 : x > e;
}

int main() {
  scanf("%d", &n);
  A.read();
  for (int i = 1; i <= n; i++) {
    a[i].read();
  }
  a[n + 1] = a[1];
  double maxval = -1e18 - 1;
  double minval = -maxval;
  for (int i = 1; i <= n; i++) {
    maxval = max(maxval, dis(a[i] - A));
    minval = min(minval, dis(a[i] - A));
    if (sign(dot(a[i + 1] - a[i], A - a[i])) >= 0 && sign(dot(a[i] - a[i + 1], A - a[i + 1])) >= 0 && sign(cross(a[i] - A, a[i + 1] - A)) != 0) {
      minval = min(minval, fabs(cross(a[i] - A, a[i + 1] - A)) / dis(a[i] - a[i + 1]));
    }
  }
  double pi = acos(-1);
  printf("%0.17f", pi * (maxval * maxval - minval * minval));
  return 0;
}
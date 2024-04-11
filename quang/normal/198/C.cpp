#include <bits/stdc++.h>

using namespace std;

const double PI = acos(-1);

typedef long double ld;

int xp, yp, vp, x, y, v, r;
ld rad;

inline ld sqr(ld u) {
  return u * u;
}

inline ld dis(pair<ld, ld> u, pair<ld, ld> v) {
  return sqrt(sqr(u.first - v.first) + sqr(u.second - v.second));
}

inline ld dot(pair<ld, ld> u, pair<ld, ld> v) {
  return u.first * v.first + u.second * v.second;
}

inline ld cross(pair<ld, ld> u, pair<ld, ld> v) {
  return u.first * v.second - u.second * v.first;
}

bool crossCir(pair<ld, ld> u, pair<ld, ld> v) {
  if (dot(make_pair(u.first - v.first, u.second - v.second), make_pair(-v.first, -v.second)) < 0) {
    return 0;
  }
  if (dot(make_pair(v.first - u.first, v.second - u.second), make_pair(-u.first, -u.second)) < 0) {
    return 0;
  }
  ld d = dis(u, v);
  ld area = abs(cross(u, v));
  return area / d <= r;
}

ld getDis(ld u) {
  ld angle = (ld)u * vp / rad;
  ld nx = cos(angle) * xp - sin(angle) * yp;
  ld ny = sin(angle) * xp + cos(angle) * yp;
  if (!crossCir(make_pair(nx, ny), make_pair(x, y))) {
    return dis(make_pair(nx, ny), make_pair(x, y));
  }
  ld res = 0.;
  ld d1 = dis(make_pair(x, y), make_pair(0, 0));
  ld d2 = dis(make_pair(nx, ny), make_pair(0, 0));
  ld a1 = acos(r / d1);
  ld a2 = acos(r / d2);
  ld tota = acos(dot(make_pair(x, y), make_pair(nx, ny)) / d1 / d2);
  tota -= a1;
  tota -= a2;
  res = tan(a1) * r;
  res += tan(a2) * r;
  res += tota * r;
  return res;
}

int main() {
  cin >> xp >> yp >> vp >> x >> y >> v >> r;
  rad = sqrt(sqr(xp) + sqr(yp));
  ld low = 0., high = 1e9;
  for (int i = 1; i <= 100000; i++) {
    ld mid = (low + high) * 0.5;
    if (getDis(mid) / v <= mid) {
      high = mid;
    } else {
      low = mid;
    }
  }
  printf("%0.17f", (double)low);
  return 0;
}
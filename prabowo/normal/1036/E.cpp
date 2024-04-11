#include <bits/stdc++.h>
using namespace std;

const int N = 1005;
const int INF = 1e9;
pair<int, int> NULLPOINT = make_pair(INF, INF);

int n;

int gcd(int x, int y) {
  while (y) {
    int t = x;
    x = y;
    y = t % y;
  }
  return x;
}

struct Line {
  int x, y, xx, yy;

  pair<int, int> slope() {
    pair<int, int> ret = {x - xx, y - yy};
    if (ret.second < 0) {
      ret.first *= -1; ret.second *= -1;
    }
    int g = gcd(abs(ret.first), ret.second);
    ret.first /= g, ret.second /= g;
    return ret;
  }

  pair<int, int> intersect(const Line &l) const {
    long long den = 1LL * (x - xx) * (l.y - l.yy) - 1LL * (y - yy) * (l.x - l.xx);
    if (den == 0) return NULLPOINT;

    long long c1 = 1LL * x * yy - 1LL * y * xx;
    long long c2 = 1LL * l.x * l.yy - 1LL * l.y * l.xx;

    long long ix = c1 * (l.x - l.xx) - (x - xx) * c2;
    long long iy = c1 * (l.y - l.yy) - (y - yy) * c2;
    if (ix % den != 0) return NULLPOINT;
    if (iy % den != 0) return NULLPOINT;
    ix /= den; iy /= den;

    if (ix < min(x, xx) || ix > max(x, xx) || ix < min(l.x, l.xx) || ix > max(l.x, l.xx)) return NULLPOINT;
    if (iy < min(y, yy) || iy > max(y, yy) || iy < min(l.y, l.yy) || iy > max(l.y, l.yy)) return NULLPOINT;
    return pair<int, int>(ix, iy);
  }
};

Line lines[N];

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d %d %d %d", &lines[i].x, &lines[i].y, &lines[i].xx, &lines[i].yy);
  }

  long long ans = 0;
  for (int i = 0; i < n; ++i) {
    pair<int, int> slope = lines[i].slope();
    if (slope.first == 0) ans += abs((lines[i].y - lines[i].yy) / slope.second) + 1;
    else ans += abs((lines[i].x - lines[i].xx) / slope.first) + 1;
  }

  set<pair<int, int>> intersects;
  intersects.insert(NULLPOINT);
  for (int i = 0; i < n; ++i) {
    set<pair<int, int>> lineIntersects;
    lineIntersects.insert(NULLPOINT);
    for (int j = 0; j < n; ++j) {
      pair<int, int> p = lines[i].intersect(lines[j]);
      lineIntersects.insert(p);
      intersects.insert(p);
    }

    ans -= lineIntersects.size() - 1;
  }
  ans += intersects.size() - 1;

  printf("%lld\n", ans);
  return 0;
}
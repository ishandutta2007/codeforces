#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define FOR(i, a, b) for (int (i) = (a); (i) <= (b); (i)++)
#define ROF(i, a, b) for (int (i) = (a); (i) >= (b); (i)--)
#define REP(i, n) FOR(i, 0, (n)-1)
#define sqr(x) ((x) * (x))
#define all(x) (x).begin(), (x).end()
#define reset(x, y) memset(x, y, sizeof(x))
#define uni(x) (x).erase(unique(all(x)), (x).end());
#define BUG(x) cerr << #x << " = " << (x) << endl
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define _1 first
#define _2 second
#define chkmin(a, b) a = min(a, b)
#define chkmax(a, b) a = max(a, b)

const double eps = 1e-9;

int n, d1, d2, ans;
bool good = true;

inline int dcmp(double x) {
  if (abs(x) <= eps) return 0;
  return x > 0 ? 1 : -1;
}

inline double get(int x1, int x2, int x3, int x4, double t) {
  return (x2 - x1) * t + (x4 - x3) * (1 - t);
}

void check(double dis2) {
  if (dcmp(dis2 - sqr(d1)) <= 0 && good) ans++, good = false;
  else if (dcmp(dis2 - sqr(d2)) > 0) good = true;
}

int main() {
  scanf("%d%d%d", &n, &d1, &d2);
  int px1, py1, px2, py2;
  REP(i, n) {
    int x1, y1, x2, y2;
    scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
    if (i) {
      double lo = 0, hi = 1;
      REP(_, 70) {
        double m1 = (lo * 2 + hi) / 3, m2 = (lo + hi * 2) / 3;
        double xm1 = get(px1, px2, x1, x2, m1), ym1 = get(py1, py2, y1, y2, m1);
        double xm2 = get(px1, px2, x1, x2, m2), ym2 = get(py1, py2, y1, y2, m2);
        if (sqr(xm1) + sqr(ym1) > sqr(xm2) + sqr(ym2)) lo = m1;
        else hi = m2;
      }
      double xm = get(px1, px2, x1, x2, lo), ym = get(py1, py2, y1, y2, lo);
      check(sqr(xm) + sqr(ym));
    }
    int dis2 = sqr(x1 - x2) + sqr(y1 - y2);
    check(dis2);
    px1 = x1, px2 = x2, py1 = y1, py2 = y2;
  }
  printf("%d", ans);
}
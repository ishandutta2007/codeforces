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
#define uni(x) (x).erase(unique(all(x)), (x).end())
#define BUG(x) cerr << #x << " = " << (x) << endl
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define _1 first
#define _2 second
#define chkmin(a, b) a = min(a, b)
#define chkmax(a, b) a = max(a, b)

const int maxn = 1123;
const double eps = 1e-9;
const double pi = acos(-1);

struct Point {
  double x, y;

  Point operator+(const Point &rhs) const {
    return {x + rhs.x, y + rhs.y};
  }

  Point operator-(const Point &rhs) const {
    return {x - rhs.x, y - rhs.y};
  }

  double norm() {
    return hypot(x, y);
  }
} p[maxn];

int w, h, n;

bool check(double rad, int idx) {
  vector<pair<double, int>> v;
  v.eb(-pi, 0);
  auto push = [&](double l, double r, int cnt) {
    if (l < -pi) {
      l += 2 * pi;
      r += 2 * pi;
    }
    if (r < pi) {
      v.eb(l, cnt);
      v.eb(r, -cnt);
    } else {
      v.eb(-pi - eps, cnt);
      v.eb(r - 2 * pi, -cnt);
      v.eb(l, cnt);
    }
  };
  FOR(i, 1, n) if ((p[i] - p[idx]).norm() > eps) {
    double d = (p[i] - p[idx]).norm();
    if (d > 2 * rad - eps) continue;
    double x = acos(d / 2 / rad), y = atan2((p[i] - p[idx]).y, (p[i] - p[idx]).x);
    push(y - x, y + x, 1);
  }
  if (p[idx].x < rad) push(pi - acos(p[idx].x / rad), pi + acos(p[idx].x / rad), 2);
  if (p[idx].y < rad) push(-pi / 2 - acos(p[idx].y / rad), -pi / 2 + acos(p[idx].y / rad), 2);
  if (w - p[idx].x < rad) push(-acos((w - p[idx].x) / rad), acos((w - p[idx].x) / rad), 2);
  if (h - p[idx].y < rad) push(pi / 2 - acos((h - p[idx].y) / rad), pi / 2 + acos((h - p[idx].y) / rad), 2);
  sort(all(v));
  int cnt = 0;
  REP(i, int(v.size())) {
    cnt += v[i]._2;
    if (cnt <= 1 && (i + 1 == v.size() || v[i + 1]._1 - v[i]._1 > eps)) return true;
  }
  return false;
}

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  cin >> w >> h >> n;
  FOR(i, 1, n) cin >> p[i].x >> p[i].y;
  mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  shuffle(p + 1, p + n + 1, rng);
  double ans = 0;
  FOR(i, 1, n) if (check(ans + eps, i)) {
    double lo = ans, hi = 1e7;
    REP(_, 70) {
      double mi = (lo + hi) / 2;
      if (check(mi, i)) lo = mi;
      else hi = mi;
    }
    ans = lo;
  }
  cout << fixed << setprecision(15) << ans;
}
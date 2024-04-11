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

const int maxn = 112345;
const double eps = 1e-9;
const double pi = acos(-1);

struct Point {
  double x, y;
} pts[maxn];

int lowbit(int x) {
  return x & -x;
}

int dcmp(double x) {
  if (abs(x) < eps) return 0;
  return x > 0 ? 1 : -1;
}

double work(double theta) {
  while (dcmp(theta + pi) < 0) theta += 2 * pi;
  while (dcmp(theta - pi) > 0) theta -= 2 * pi;
  return theta;
}

int n;
ll k;

ll check(double r) {
  vector<pair<double, int>> v;
  FOR(i, 1, n) {
    double d = sqrt(sqr(pts[i].x) + sqr(pts[i].y));
    if (dcmp(d - r) <= 0) continue;
    double theta = atan2(pts[i].y, pts[i].x), half = acos(r / d);
    double s = work(theta - half), t = work(theta + half);
    v.eb(s, i); v.eb(t, i);
  }
  sort(all(v));
  int m = v.size();
  vector<int> cnt(n + 1);
  vector<vector<int>> pos(n + 1, vector<int>(2));
  REP(i, m) pos[v[i]._2][cnt[v[i]._2]++] = i + 1;
  vector<int> fen(m + 1);
  ll ret = n * ll(n - 1) / 2;
  REP(i, m) {
    int id = v[i]._2;
    auto query = [&](int x) {
      int ret = 0;
      while (x) {
        ret += fen[x];
        x -= lowbit(x);
      }
      return ret;
    };
    auto inc = [&](int x) {
      while (x <= m) {
        fen[x]++;
        x += lowbit(x);
      }
    };
    if (pos[id][0] == i + 1) {
      ret -= query(pos[id][1]) - query(i);
      inc(pos[id][1]);
    }
  }
  return ret;
}

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  cin >> n >> k;
  FOR(i, 1, n) cin >> pts[i].x >> pts[i].y;
  double lo = 0, hi = 2e4;
  REP(i, 100) {
    double mi = (lo + hi) / 2;
    if (check(mi) >= k) hi = mi;
    else lo = mi;
  }
  cout << fixed << setprecision(20) << lo;
}
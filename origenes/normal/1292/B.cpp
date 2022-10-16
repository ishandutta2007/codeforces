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

ll dis(pair<ll, ll> a, pair<ll, ll> b) {
  return abs(a._1 - b._1) + abs(a._2 - b._2);
}

int main() {
  ll X, Y, t;
  ll x0, y0, ax, ay, bx, by;
  cin >> x0 >> y0 >> ax >> ay >> bx >> by;
  cin >> X >> Y >> t;
  vector<ll> x, y;
  x.eb(x0), y.eb(y0);
  while (true) {
    ll px = x.back(), py = y.back();
    double nx = double(px) * ax + bx, ny = double(py) * ay + by;
    if (nx > 1e18 || ny > 1e18) break;
    ll xx = px * ax + bx, yy = py * ay + by;
    x.eb(xx), y.eb(yy);
  }
  assert(x.size() < 100);
  int ans = 0, n = x.size();
  REP(i, n) {
    if (dis(mp(x[i], y[i]), mp(X, Y)) > t) continue;
    int now = 1;
    ll rem = t - dis(mp(x[i], y[i]), mp(X, Y));
    ROF(j, i - 1, 0) {
      if (rem < dis(mp(x[j + 1], y[j + 1]), mp(x[j], y[j]))) break;
      rem -= dis(mp(x[j + 1], y[j + 1]), mp(x[j], y[j]));
      now++;
    }
    chkmax(ans, now);
    now = 1;
    rem = t - dis(mp(x[i], y[i]), mp(X, Y));
    FOR(j, i + 1, n - 1) {
      if (rem < dis(mp(x[j], y[j]), mp(x[j - 1], y[j - 1]))) break;
      rem -= dis(mp(x[j], y[j]), mp(x[j - 1], y[j - 1]));
      now++;
    }
    chkmax(ans, now);
  }
  printf("%d", ans);
}
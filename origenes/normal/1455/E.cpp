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

void solve() {
  vector<pii> pts;
  vector<int> X, Y;
  REP(i, 4) {
    int x, y; cin >> x >> y;
    pts.eb(x, y);
    X.eb(x); Y.eb(y);
  }
  sort(all(X)); sort(all(Y));
  ll ans = 1e18;
  vector<int> id(4);
  iota(all(id), 0);
  do {
    vector<pii> cur(4);
    REP(i, 4) cur[i] = pts[id[i]];
    auto f = [&](ll x1, ll x2, ll y1, ll y2) {
      ll ret = 0;
      ret += abs(cur[0]._1 - x1) + abs(cur[0]._2 - y1);
      ret += abs(cur[1]._1 - x1) + abs(cur[1]._2 - y2);
      ret += abs(cur[2]._1 - x2) + abs(cur[2]._2 - y1);
      ret += abs(cur[3]._1 - x2) + abs(cur[3]._2 - y2);
      return ret;
    };
    REP(i, 4) FOR(j, i + 1, 3) REP(k, 4) {
      int s = X[j] - X[i];
      chkmin(ans, f(X[i], X[j], Y[k], Y[k] + s));
      chkmin(ans, f(X[i], X[j], Y[k] - s, Y[k]));
      s = Y[j] - Y[i];
      chkmin(ans, f(X[k], X[k] + s, Y[i], Y[j]));
      chkmin(ans, f(X[k] - s, X[k], Y[i], Y[j]));
    }
  } while (next_permutation(all(id)));
  cout << ans << '\n';
}

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  int T; cin >> T;
  while (T--) solve();
}
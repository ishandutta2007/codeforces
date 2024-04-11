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
  int n; cin >> n;
  vector<vector<int>> a(2, vector<int>(n));
  REP(i, 2) REP(j, n) {
    cin >> a[i][j];
    if (a[i][j] > 0) a[i][j]++;
  }
  map<int, int> u, d;
  REP(j, n) u[a[0][j] - j]++;
  REP(j, n) u[a[1][j] - n - (n - j - 1)]++;
  FOR(j, 1, n - 1) d[a[1][j] - j - 1]++;
  FOR(j, 1, n - 1) d[a[0][j] - n - (n - j)]++;
  int now = 0, ans = 1e9, clk = 0, ou = 0, od = 0;
  REP(i, n) {
    if (i % 2 == 0) chkmin(ans, max(now, u.rbegin()->_1 - ou));
    else chkmin(ans, max(now, d.rbegin()->_1 - od));
    if (i % 2 == 0) {
      if (!--u[a[0][i] - i]) u.erase(a[0][i] - i);
      chkmax(now, a[0][i] - clk);
      clk++;
      if (!--u[a[1][i] - n - (n - 1 - i)]) u.erase(a[1][i] - n - (n - 1 - i));
      chkmax(now, a[1][i] - clk);
      clk++;
      ou += 2;
    } else {
      if (!--d[a[1][i] - i - 1]) d.erase(a[1][i] - i - 1);
      chkmax(now, a[1][i] - clk);
      clk++;
      if (!--d[a[0][i] - n - (n - i)]) d.erase(a[0][i] - n - (n - i));
      chkmax(now, a[0][i] - clk);
      clk++;
      od += 2;
    }
  }
  cout << ans + 2 * n - 1 << '\n';
}

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  int T; cin >> T;
  while (T--) solve();
}
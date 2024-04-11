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
  vector<vector<int>> c(2 * n, vector<int> (2 * n));
  REP(i, 2 * n) REP(j, 2 * n) cin >> c[i][j];
  ll ans = 0;
  FOR(i, n, 2 * n - 1) FOR(j, n, 2 * n - 1) ans += c[i][j];
  int best = min({
    c[n][0], c[2 * n - 1][0],
    c[n][n - 1], c[2 * n - 1][n - 1],
    c[0][n], c[n - 1][n],
    c[0][2 * n - 1], c[n - 1][2 * n - 1]
  });
  cout << ans + best << '\n';
}

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  int T; cin >> T;
  while (T--) solve();
}
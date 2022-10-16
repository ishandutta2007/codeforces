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
  vector<int> p(n + 1);
  FOR(i, 1, n) cin >> p[i];
  vector<vector<int>> pre(n + 1, vector<int>(n + 1)), suf(n + 1, vector<int>(n + 1));
  FOR(i, 1, n) FOR(j, 1, i - 1) {
    if (p[j] < p[i]) pre[i][j] = 1;
    pre[i][j] += pre[i][j - 1];
  }
  FOR(i, 1, n) ROF(j, n, i + 1) {
    if (p[i] > p[j]) suf[i][j] = 1;
    if (j != n) suf[i][j] += suf[i][j + 1];
  }
  ll ans = 0;
  FOR(b, 2, n - 1) FOR(c, b + 1, n - 1) ans += suf[b][c + 1] * ll(pre[c][b - 1]);
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
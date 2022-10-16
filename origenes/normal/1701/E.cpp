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
  int n, m;
  cin >> n >> m;
  string s, t;
  cin >> s >> t;
  vector<vector<int>> f(n + 1, vector<int>(m + 1));
  vector<int> pre(n + 1), suf(n + 1);
  int p = 0;
  FOR(i, 1, n) {
    if (p < m && s[i - 1] == t[p]) p++;
    pre[i] = p;
  }
  if (pre[n] != m) {
    cout << "-1\n";
    return;
  }
  p = m - 1;
  ROF(i, n, 1) {
    if (p >= 0 && s[i - 1] == t[p]) p--;
    suf[i] = m - 1 - p;
  }
  int ans = n;
  FOR(i, 1, n) FOR(j, 1, m) if (s[i - 1] == t[j - 1]) {
    f[i][j] = f[i - 1][j - 1] + 1;
    if (pre[i] < j || suf[i] < m - j + 1) continue;
    if (f[i][j] == i) chkmin(ans, n - f[i][j]);
    else chkmin(ans, n - i + 2 * (i - f[i][j]) - j + f[i][j] + 1);
  }
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
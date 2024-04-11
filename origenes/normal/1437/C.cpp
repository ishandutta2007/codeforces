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

const int maxn = 213;

int n;
int t[maxn], f[maxn * 2][maxn];

void solve() {
  cin >> n;
  FOR(i, 1, n) cin >> t[i];
  sort(t + 1, t + n + 1);
  REP(i, 2 * n + 1) REP(j, n + 1) f[i][j] = 1e9;
  f[0][0] = 0;
  REP(i, 2 * n) REP(j, n) {
    chkmin(f[i + 1][j], f[i][j]);
    chkmin(f[i + 1][j + 1], f[i][j] + abs(i + 1 - t[j + 1]));
  }
  int ans = 1e9;
  FOR(i, 1, 2 * n) chkmin(ans, f[i][n]);
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
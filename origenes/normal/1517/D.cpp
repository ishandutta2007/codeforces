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

const int maxn = 512;

int n, m, k;
int f[maxn][maxn][11], h[maxn][maxn], v[maxn][maxn];

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  cin >> n >> m >> k;
  if (k % 2 == 1) {
    FOR(i, 1, n) {
      FOR(j, 1, m) cout << -1 << ' ';
      cout << '\n';
    }
    return 0;
  }
  FOR(i, 1, n) FOR(j, 1, m - 1) cin >> h[i][j];
  FOR(i, 1, n - 1) FOR(j, 1, m) cin >> v[i][j];
  k /= 2;
  FOR(step, 1, k) FOR(i, 1, n) FOR(j, 1, m) {
    f[i][j][step] = 1e9;
    if (i > 1) chkmin(f[i][j][step], f[i - 1][j][step - 1] + v[i - 1][j]);
    if (i < n) chkmin(f[i][j][step], f[i + 1][j][step - 1] + v[i][j]);
    if (j > 1) chkmin(f[i][j][step], f[i][j - 1][step - 1] + h[i][j - 1]);
    if (j < m) chkmin(f[i][j][step], f[i][j + 1][step - 1] + h[i][j]);
  }
  FOR(i, 1, n) {
    FOR(j, 1, m) cout << f[i][j][k] * 2 << ' ';
    cout << '\n';
  }
}
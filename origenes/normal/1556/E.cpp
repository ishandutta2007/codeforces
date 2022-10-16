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

int n, q;
ll a[maxn], b[maxn], d[maxn];
ll f[maxn][17], g[maxn][17];

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  cin >> n >> q;
  FOR(i, 1, n) cin >> a[i];
  FOR(i, 1, n) cin >> b[i];
  FOR(i, 1, n) d[i] = a[i] - b[i];
  FOR(i, 1, n) f[i][0] = f[i - 1][0] + d[i];
  FOR(j, 1, 16) FOR(i, 1, n - (1 << j) + 1) f[i][j] = max(f[i][j - 1], f[i + (1 << j - 1)][j - 1]);
  FOR(i, 1, n) g[i][0] = f[i][0];
  FOR(j, 1, 16) FOR(i, 1, n - (1 << j) + 1) g[i][j] = min(g[i][j - 1], g[i + (1 << j - 1)][j - 1]);
  while (q--) {
    int l, r;
    cin >> l >> r;
    if (f[r][0] - f[l - 1][0] != 0) {
      cout << "-1\n";
      continue;
    }
    int k = 0;
    while ((1 << k + 1) <= r - l + 1) k++;
    ll mx = max(f[l][k], f[r - (1 << k) + 1][k]), mn = min(g[l][k], g[r - (1 << k) + 1][k]);
    if (mx > f[l - 1][0]) {
      cout << "-1\n";
      continue;
    }
    cout << f[l - 1][0] - mn << '\n';
  }
}
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

const int maxn = 3123;

int n;
int a[maxn], f[maxn][maxn], g[maxn];

void solve() {
  cin >> n;
  FOR(i, 1, n) cin >> a[i];
  FOR(i, 1, n + 1) {
    g[i] = n + 1;
    FOR(j, 1, n + 1) f[i][j] = n + 1;
  }
  f[1][1] = g[1] = 0;
  FOR(i, 2, n) {
    FOR(j, 1, n) chkmin(g[j], f[j][i]);
    int cost = 0;
    ROF(j, i - 1, 1) if (j + a[j] >= i) {
      chkmin(f[i][j + a[j] + 1], g[j] + cost);
      cost++;
    }
  }
  FOR(i, 1, n) chkmin(g[i], f[i][n + 1]);
  cout << g[n] << '\n';
}

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  int T; cin >> T;
  while (T--) solve();
}
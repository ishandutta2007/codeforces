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

vector<int> G[maxn];
int n, k;
int a[maxn], f[maxn][40];
int ans[maxn];

void dfs(int u, int par) {
  f[u][0] = a[u];
  for (auto v : G[u]) if (v != par) {
    dfs(v, u);
    REP(i, 2 * k) f[u][(i + 1) % (2 * k)] ^= f[v][i];
  }
}

void dfs2(int u, int par) {
  FOR(i, k, 2 * k - 1) ans[u] ^= f[u][i];
  ans[u] = ans[u] != 0;
  for (auto v : G[u]) if (v != par) {
    vector<int> diff(2 * k);
    REP(i, 2 * k) diff[i] = f[u][i] ^ f[v][(i - 1 + 2 * k) % (2 * k)];
    REP(i, 2 * k) f[v][(i + 1) % (2 * k)] ^= diff[i];
    dfs2(v, u);
    REP(i, 2 * k) f[v][(i + 1) % (2 * k)] ^= diff[i];
  }
}

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  cin >> n >> k;
  REP(i, n - 1) {
    int u, v;
    cin >> u >> v;
    G[u].eb(v); G[v].eb(u);
  }
  FOR(i, 1, n) cin >> a[i];
  dfs(1, 0);
  dfs2(1, 0);
  FOR(i, 1, n) cout << ans[i] << ' ';
}
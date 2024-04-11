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

int n;
ll f[maxn][2], l[maxn], r[maxn];
vector<int> G[maxn];

void dfs(int u, int par) {
  f[u][0] = f[u][1] = 0;
  for (auto v : G[u]) if (v != par) {
    dfs(v, u);
    ll g[2] = {};
    chkmax(g[0], abs(l[u] - l[v]) + f[v][0]);
    chkmax(g[0], abs(l[u] - r[v]) + f[v][1]);
    chkmax(g[1], abs(r[u] - l[v]) + f[v][0]);
    chkmax(g[1], abs(r[u] - r[v]) + f[v][1]);
    f[u][0] += g[0], f[u][1] += g[1];
  }
}

void solve() {
  cin >> n;
  FOR(i, 1, n) G[i].clear();
  FOR(i, 1, n) cin >> l[i] >> r[i];
  REP(i, n - 1) {
    int u, v;
    cin >> u >> v;
    G[u].eb(v);
    G[v].eb(u);
  }
  dfs(1, 0);
  cout << max(f[1][0], f[1][1]) << '\n';
}

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  int T; cin >> T;
  while (T--) solve();
}
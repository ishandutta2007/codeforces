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

const int maxn = 1123456;

int n;
int f[maxn], g[maxn], sz[maxn];
vector<pii> G[maxn];
vector<int> c[maxn];

void dfs(int u, int par) {
  sz[u] = 1;
  for (auto [v, w] : G[u]) if (v != par) {
    f[v] = c[w].back();
    c[w].eb(v);
    dfs(v, u);
    sz[u] += sz[v];
    g[v] += sz[v];
    g[f[v]] -= sz[v];
    c[w].pop_back();
  }
}

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  cin >> n;
  REP(i, n - 1) {
    int u, v, w;
    cin >> u >> v >> w;
    G[u].eb(v, w);
    G[v].eb(u, w);
  }
  FOR(i, 1, n) {
    c[i] = {n + i};
    g[n + i] = n;
  }
  dfs(1, 0);
  ll ans = 0;
  FOR(i, 2, n) ans += ll(g[i]) * g[f[i]];
  cout << ans;
}
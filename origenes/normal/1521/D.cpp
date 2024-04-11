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
int f[maxn][2], deg[maxn];
vector<int> G[maxn], adj[maxn];
set<int> keep[maxn][2];
bool vis[maxn];
vector<pii> del, segs;

void dfs(int u, int par) {
  int g[3] = {};
  set<int> kg[3] = {};
  for (auto v : G[u]) if (v != par) {
    dfs(v, u);
    if (g[1] + f[v][0] < g[2] + f[v][1] + 1) {
      kg[2] = kg[1];
      kg[2].emplace(v);
    }
    g[2] = min(g[2] + f[v][1] + 1, g[1] + f[v][0]);
    if (g[0] + f[v][0] < g[1] + f[v][1] + 1) kg[1] = {v};
    g[1] = min(g[1] + f[v][1] + 1, g[0] + f[v][0]);
    g[0] += f[v][1] + 1;
  }
  f[u][0] = min(g[0], g[1]);
  if (g[1] < g[0]) keep[u][0] = kg[1];
  f[u][1] = min({g[0], g[1], g[2]});
  if (g[1] == f[u][1]) keep[u][1] = kg[1];
  else if (g[2] == f[u][1]) keep[u][1] = kg[2];
}

void dfs(int u, int i, int par) {
  for (auto v : G[u]) if (v != par) {
    if (keep[u][i].count(v)) {
      adj[u].eb(v);
      adj[v].eb(u);
      deg[u]++, deg[v]++;
      dfs(v, 0, u);
    } else {
      del.eb(u, v);
      dfs(v, 1, u);
    }
  }
}

int dfs3(int u, int par) {
  vis[u] = true;
  for (auto v : adj[u]) if (v != par) return dfs3(v, u);
  return u;
}

void solve() {
  cin >> n;
  FOR(i, 1, n) {
    G[i].clear();
    REP(j, 2) keep[i][j].clear();
    adj[i].clear();
    deg[i] = 0;
    vis[i] = false;
  }
  del.clear(); segs.clear();
  REP(i, n - 1) {
    int u, v;
    cin >> u >> v;
    G[u].eb(v);
    G[v].eb(u);
  }
  dfs(1, 0);
  dfs(1, f[1][0] > f[1][1], 0);
  FOR(i, 1, n) if (deg[i] <= 1 && !vis[i]) {
    int j = dfs3(i, 0);
    segs.eb(i, j);
  }
  cout << min(f[1][0], f[1][1]) << '\n';
  auto [_, t] = segs[0];
  FOR(i, 1, int(segs.size()) - 1) {
    auto [hh, tt] = segs[i];
    cout << del[i - 1]._1 << ' ' << del[i - 1]._2 << ' ' << t << ' ' << hh << '\n';
    t = tt;
  }
}

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  int T; cin >> T;
  while (T--) solve();
}
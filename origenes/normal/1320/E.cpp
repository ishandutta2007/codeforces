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

const int maxn = 212345;

vector<int> G[maxn];
vector<pii> adj[maxn];
int n, clk, q;
int dep[maxn], dfn[maxn], anc[maxn][18], g[maxn];
pii f[maxn];

void dfs(int u, int par) {
  dfn[u] = ++clk;
  dep[u] = dep[par] + 1;
  anc[u][0] = par;
  FOR(i, 1, 17) anc[u][i] = anc[anc[u][i - 1]][i - 1];
  for (auto v : G[u]) if (v != par) dfs(v, u);
}

int lca(int u, int v) {
  if (dep[u] > dep[v]) swap(u, v);
  ROF(i, 17, 0) if (dep[anc[v][i]] >= dep[u]) v = anc[v][i];
  if (u == v) return u;
  ROF(i, 17, 0) if (anc[u][i] != anc[v][i]) u = anc[u][i], v = anc[v][i];
  return anc[u][0];
}

int dis(int u, int v) {
  if (dep[u] > dep[v]) swap(u, v);
  return dep[v] - dep[u];
}

int main() {
  scanf("%d", &n);
  REP(i, n - 1) {
    int u, v; scanf("%d%d", &u, &v);
    G[u].eb(v); G[v].eb(u);
  }
  dfs(1, 0);
  scanf("%d", &q);
  while (q--) {
    int k, m; scanf("%d%d", &k, &m);
    vector<pii> virus(k);
    vector<int> victims(m);
    REP(i, k) scanf("%d%d", &virus[i]._1, &virus[i]._2);
    REP(i, m) scanf("%d", &victims[i]);
    vector<int> consider(k + m);
    REP(i, k) consider[i] = virus[i]._1;
    REP(i, m) consider[i + k] = victims[i];
    sort(all(consider), [](int x, int y) { return dfn[x] < dfn[y]; });
    uni(consider);
    int sz = consider.size();
    for (int i = 1; i < sz; i++) consider.eb(lca(consider[i], consider[i - 1]));
    sort(all(consider), [](int x, int y) { return dfn[x] < dfn[y]; });
    uni(consider);
    stack<int> s;
    s.emplace(1); adj[1].clear();
    for (auto u : consider) {
      if (u == s.top()) continue;
      while (lca(u, s.top()) != s.top()) {
        int v = s.top(); s.pop();
        adj[s.top()].eb(v, dis(v, s.top()));
        adj[v].eb(s.top(), dis(v, s.top()));
      }
      adj[u].clear(); s.emplace(u);
    }
    while (s.size() > 1) {
      int u = s.top(); s.pop();
      adj[s.top()].eb(u, dis(u, s.top()));
      adj[u].eb(s.top(), dis(u, s.top()));
    }
    set<tuple<int, int, int>> Q;
    for (auto u : consider) f[u] = {1e9, -1};
    REP(i, int(virus.size())) {
      auto [u, speed] = virus[i];
      f[u] = {0, i};
      g[u] = 0;
      Q.emplace(0, i, u);
    }
    while (!Q.empty()) {
      auto [d, i, u] = *Q.begin(); Q.erase(Q.begin());
      if (mp(d, i) > f[u]) continue;
      for (auto [v, dist] : adj[u]) {
        dist = g[u] + dist;
        int nd = (dist + virus[i]._2 - 1) / virus[i]._2;
        if (mp(nd, i) < f[v]) {
          f[v] = {nd, i};
          g[v] = dist;
          Q.emplace(nd, i, v);
        }
      }
    }
    for (auto u : victims) printf("%d ", f[u]._2 + 1);
    putchar('\n');
  }
}
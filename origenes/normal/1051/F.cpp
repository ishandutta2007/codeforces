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
#define uni(x) (x).erase(unique(all(x)), (x).end());
#define BUG(x) cerr << #x << " = " << (x) << endl
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define _1 first
#define _2 second
#define chkmin(a, b) a = min(a, b)
#define chkmax(a, b) a = max(a, b)

const int maxn = 112345;

struct Edge {
  int u, v, w;
} e[maxn];

vector<int> G[maxn];
vector<pii> adj[maxn];
int n, m, q, dep[maxn], p[maxn], st[maxn][17], bit[17];
ll dis[maxn], dij[42][maxn];

int Find(int x) {
  return p[x] == x ? x : p[x] = Find(p[x]);
}

void dfs(int u, int par, ll down) {
  dep[u] = dep[par] + 1;
  dis[u] = dis[par] + down;
  st[u][0] = par;
  FOR(i, 1, 16) st[u][i] = st[st[u][i - 1]][i - 1];
  for (auto _ : adj[u]) {
    ll nd = _._2;
    int v = _._1;
    if (v != par) dfs(v, u, nd);
  }
}

int main() {
  scanf("%d%d", &n, &m);
  FOR(i, 1, m) {
    scanf("%d%d%d", &e[i].u, &e[i].v, &e[i].w);
    G[e[i].u].eb(i);
    G[e[i].v].eb(i);
  }
  FOR(i, 1, n) p[i] = i;
  set<int> bad;
  FOR(i, 1, m) {
    int pu = Find(e[i].u), pv = Find(e[i].v);
    if (pu != pv) {
      adj[e[i].u].eb(e[i].v, e[i].w);
      adj[e[i].v].eb(e[i].u, e[i].w);
      p[pu] = pv;
    } else {
      bad.emplace(e[i].u);
      bad.emplace(e[i].v);
    }
  }
  vector<int> lis(all(bad));
  REP(i, int(lis.size())) {
    reset(dij[i], 0x3f);
    dij[i][lis[i]] = 0;
    set<pair<ll, int>> que;
    que.emplace(0, lis[i]);
    while (!que.empty()) {
      auto now = *que.begin(); que.erase(que.begin());
      ll d = now._1;
      int u = now._2;
      if (dij[i][u] < d) continue;
      for (auto _ : G[u]) {
        int v = u == e[_].u ? e[_].v : e[_].u, to = e[_].w;
        if (d + to >= dij[i][v]) continue;
        dij[i][v] = d + to;
        que.emplace(dij[i][v], v);
      }
    }
  }
  REP(i, 17) bit[i] = 1 << i;
  dfs(1, 0, 0);
  scanf("%d", &q);
  while (q--) {
    int u, v;
    scanf("%d%d", &u, &v);
    if (dep[u] > dep[v]) swap(u, v);
    int x = u, y = v;
    ROF(i, 16, 0) if (dep[v] - dep[u] >= bit[i]) v = st[v][i];
    ROF(i, 16, 0) if (st[u][i] != st[v][i]) u = st[u][i], v = st[v][i];
    if (u != v) u = st[u][0];
    ll ans = dis[x] + dis[y] - 2 * dis[u];
    REP(i, int(lis.size())) chkmin(ans, dij[i][x] + dij[i][y]);
    printf("%lld\n", ans);
  }
}
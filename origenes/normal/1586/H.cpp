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

int n, q;
int e[maxn], par[maxn], mx[maxn], idx[maxn], cost[maxn], dep[maxn];
pii ans[maxn];
int anc[maxn][18], toll[maxn][18];
vector<pii> G[maxn];

int Find(int x) {
  return par[x] == x ? x : par[x] = Find(par[x]);
}

int check(int u, int v) {
  if (dep[u] > dep[v]) swap(u, v);
  int ret = 0;
  ROF(i, 17, 0) if (dep[anc[v][i]] >= dep[u]) {
    chkmax(ret, toll[v][i]);
    v = anc[v][i];
  }
  if (u == v) return ret;
  ROF(i, 17, 0) if (anc[u][i] != anc[v][i]) {
    chkmax(ret, toll[u][i]); chkmax(ret, toll[v][i]);
    u = anc[u][i], v = anc[v][i];
  }
  return max(ret, max(toll[u][0], toll[v][0]));
}

void Union(int u, int v) {
  u = Find(u), v = Find(v);
  if (u == v) return;
  if (mx[u] != mx[v]) {
    if (mx[u] < mx[v]) swap(u, v);
    par[v] = u;
    return;
  }
  par[v] = u;
  int x = idx[u], y = idx[v];
  chkmax(cost[u], cost[v]);
  chkmax(cost[u], check(x, y));
}

void dfs(int u, int p) {
  anc[u][0] = p;
  dep[u] = dep[p] + 1;
  FOR(i, 1, 17) {
    anc[u][i] = anc[anc[u][i - 1]][i - 1];
    toll[u][i] = max(toll[u][i - 1], toll[anc[u][i - 1]][i - 1]);
  }
  for (auto [w, v] : G[u]) if (v != p) {
    toll[v][0] = w;
    dfs(v, u);
  }
}

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  cin >> n >> q;
  FOR(i, 1, n) cin >> e[i];
  vector<tuple<int, int, int>> edges(n - 1);
  REP(i, n - 1) {
    int a, b, c, t;
    cin >> a >> b >> c >> t;
    G[a].eb(t, b);
    G[b].eb(t, a);
    edges[i] = {c, a, b};
  }
  dfs(1, 0);
  sort(all(edges), greater<>());
  FOR(i, 1, n) {
    par[i] = idx[i] = i;
    mx[i] = e[i];
  }
  vector<tuple<int, int, int>> queries(q);
  REP(i, q) {
    int v, x;
    cin >> v >> x;
    queries[i] = {v, x, i};
  }
  sort(all(queries), greater<>());
  int j = 0;
  for (auto [cap, x, id] : queries) {
    while (j < edges.size() && get<0>(edges[j]) >= cap) {
      auto [_, u, v] = edges[j];
      Union(u, v);
      j++;
    }
    int r = Find(x);
    ans[id] = {mx[r], max(cost[r], check(x, idx[r]))};
  }
  REP(i, q) cout << ans[i]._1 << ' ' << ans[i]._2 << '\n';
}
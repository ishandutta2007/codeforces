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

const int maxn = 312345;
const int maxq = 512345;

int n, q, clk;
vector<pii> G[maxn];
int par[maxn], dep[maxn], f[maxn], anc[maxn][19], fen[maxn], in[maxn], out[maxn];
bool ans[maxq];

int Find(int x) {
  return par[x] == x ? x : par[x] = Find(par[x]);
}

void dfs(int u, int p) {
  dep[u] = dep[p] + 1;
  in[u] = ++clk;
  anc[u][0] = p;
  FOR(i, 1, 18) anc[u][i] = anc[anc[u][i - 1]][i - 1];
  for (auto [v, x] : G[u]) if (v != p) {
    f[v] = f[u] ^ x;
    dfs(v, u);
  }
  out[u] = clk;
}

int lca(int u, int v) {
  if (dep[u] > dep[v]) swap(u, v);
  ROF(i, 18, 0) if (dep[anc[v][i]] >= dep[u]) v = anc[v][i];
  if (u == v) return u;
  ROF(i, 18, 0) if (anc[v][i] != anc[u][i]) v = anc[v][i], u = anc[u][i];
  return anc[u][0];
}

void add(int x, int v) {
  while (x <= n + 1) {
    fen[x] += v;
    x += x & -x;
  }
}

void inc(int u, int o) {
  while (u != o) {
    add(in[u], 1);
    add(out[u] + 1, -1);
    u = anc[u][0];
  }
}

int query(int x) {
  int ret = 0;
  while (x > 0) {
    ret += fen[x];
    x -= x & -x;
  }
  return ret;
}

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  cin >> n >> q;
  iota(par + 1, par + n + 1, 1);
  vector<tuple<int, int, int, int>> queries;
  FOR(i, 1, q) {
    int u, v, x;
    cin >> u >> v >> x;
    int pu = Find(u), pv = Find(v);
    if (pu != pv) {
      par[pu] = pv;
      G[u].eb(v, x);
      G[v].eb(u, x);
      ans[i] = true;
    } else queries.eb(u, v, x, i);
  }
  FOR(i, 1, n) if (!dep[i]) dfs(i, 0);
  for (auto [u, v, x, id] : queries) {
    if ((f[u] ^ f[v] ^ x) != 1) continue;
    int o = lca(u, v);
    if (query(in[u]) + query(in[v]) - 2 * query(in[o]) == 0) {
      ans[id] = true;
      inc(u, o); inc(v, o);
    }
  }
  FOR(i, 1, q) {
    if (ans[i]) cout << "YES\n";
    else cout << "NO\n";
  }
}
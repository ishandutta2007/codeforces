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

struct Seg {
  int l, r;
  int mx, lzy;
} T[maxn << 2];

int n, m, clk;
int dep[maxn], in[maxn], out[maxn], seq[maxn], ans[maxn], anc[maxn][17];
vector<int> G[maxn];
vector<tuple<int, int, int>> q[maxn];

void dfs(int u, int par) {
  dep[u] = dep[par] + 1;
  anc[u][0] = par;
  FOR(i, 1, 16) anc[u][i] = anc[anc[u][i - 1]][i - 1];
  in[u] = ++clk;
  seq[clk] = u;
  for (auto v : G[u]) if (v != par) dfs(v, u);
  out[u] = clk;
}

int lca(int u, int v) {
  ROF(i, 16, 0) if (dep[anc[v][i]] >= dep[u]) v = anc[v][i];
  if (u == v) return u;
  ROF(i, 16, 0) if (anc[u][i] != anc[v][i]) u = anc[u][i], v = anc[v][i];
  return anc[u][0];
}

void push_down(int o) {
  T[o << 1].mx += T[o].lzy; T[o << 1].lzy += T[o].lzy;
  T[o << 1 | 1].mx += T[o].lzy; T[o << 1 | 1].lzy += T[o].lzy;
  T[o].lzy = 0;
}

void push_up(int o) {
  T[o].mx = max(T[o << 1].mx, T[o << 1 | 1].mx);
}

void build(int o, int l, int r) {
  T[o].l = l, T[o].r = r;
  if (l < r) {
    int mi = l + r >> 1;
    build(o << 1, l, mi);
    build(o << 1 | 1, mi + 1, r);
    push_up(o);
  } else T[o].mx = dep[seq[l]] - 1;
}

void add(int o, int l, int r, int v) {
  if (l <= T[o].l && T[o].r <= r) {
    T[o].mx += v;
    T[o].lzy += v;
    return;
  }
  int mi = T[o].l + T[o].r >> 1;
  push_down(o);
  if (l <= mi) add(o << 1, l, r, v);
  if (r > mi) add(o << 1 | 1, l, r, v);
  push_up(o);
}

int query(int o, int l, int r) {
  if (l <= T[o].l && T[o].r <= r) return T[o].mx;
  int mi = T[o].l + T[o].r >> 1, res = 0;
  push_down(o);
  if (l <= mi) chkmax(res, query(o << 1, l, r));
  if (r > mi) chkmax(res, query(o << 1 | 1, l, r));
  return res;
}

void dfs2(int u, int par) {
  for (auto [id, l, r] : q[u]) {
    int res = query(1, l, r);
    chkmax(ans[id], res);
  }
  add(1, 1, n, 1);
  for (auto v : G[u]) if (v != par) {
    add(1, in[v], out[v], -2);
    dfs2(v, u);
    add(1, in[v], out[v], 2);
  }
  add(1, 1, n, -1);
}

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  cin >> n;
  REP(i, n - 1) {
    int u, v;
    cin >> u >> v;
    G[u].eb(v);
    G[v].eb(u);
  }
  dfs(1, 0);
  cin >> m;
  FOR(i, 1, m) {
    int u, v;
    cin >> u >> v;
    if (dep[u] > dep[v]) swap(u, v);
    int a = lca(u, v);
    int w = v;
    ROF(j, 16, 0) if (dep[anc[w][j]] >= dep[a] && dep[v] - dep[anc[w][j]] < dep[u] + dep[anc[w][j]] - 2 * dep[a]) w = anc[w][j];
    q[v].eb(i, in[w], out[w]);
    if (in[w] != 1) q[u].eb(i, 1, in[w] - 1);
    if (out[w] != n) q[u].eb(i, out[w] + 1, n);
  }
  build(1, 1, n);
  dfs2(1, 0);
  FOR(i, 1, m) cout << ans[i] << '\n';
}
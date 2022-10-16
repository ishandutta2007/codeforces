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

struct Seg {
  int l, r;
  int cnt, mmax, lzy;
} T[maxn << 2];

int n, q, clk;
vector<int> G[maxn];
int dep[maxn], in[maxn], out[maxn], st[maxn][19];

void dfs(int u, int par) {
  in[u] = ++clk;
  st[u][0] = par;
  for (int j = 1; (1 << j) <= dep[u]; j++) st[u][j] = st[st[u][j - 1]][j - 1];
  for (auto v : G[u]) if (v != par) {
      dep[v] = dep[u] + 1;
      dfs(v, u);
    }
  out[u] = clk;
}

void build(int o, int l, int r) {
  T[o].l = l, T[o].r = r;
  T[o].cnt = r - l + 1;
  if (l < r) {
    int mi = l + r >> 1;
    build(o << 1, l, mi);
    build(o << 1 | 1, mi + 1, r);
  }
}

int anc(int u, int dis) {
  ROF(j, 18, 0) if (dis & (1 << j)) u = st[u][j];
  return u;
}

void add(int o, int l, int r, int d) {
  if (l > r || T[o].r < l || T[o].l > r) return;
  if (l <= T[o].l && T[o].r <= r) {
    T[o].lzy += d;
    T[o].mmax += d;
    return;
  }
  add(o << 1, l, r, d);
  add(o << 1 | 1, l, r, d);
  T[o].mmax = max(T[o << 1].mmax, T[o << 1 | 1].mmax);
  T[o].cnt = 0;
  if (T[o].mmax == T[o << 1].mmax) T[o].cnt += T[o << 1].cnt;
  if (T[o].mmax == T[o << 1 | 1].mmax) T[o].cnt += T[o << 1 | 1].cnt;
  T[o].mmax += T[o].lzy;
}

int main() {
  scanf("%d%d", &n, &q);
  FOR(i, 1, n - 1) {
    int u, v;
    scanf("%d%d", &u, &v);
    G[u].eb(v);
    G[v].eb(u);
  }
  dfs(1, -1);
  build(1, 1, n);
  set<pii> edges;
  while (q--) {
    int u, v;
    scanf("%d%d", &u, &v);
    if (dep[u] > dep[v]) swap(u, v);
    int diff = 0;
    if (edges.count({u, v}) || edges.count({v, u})) {
      diff--;
      edges.erase({u, v});
      edges.erase({v, u});
    } else {
      diff++;
      edges.emplace(u, v);
    }
    if (anc(v, dep[v] - dep[u]) == u) {
      u = anc(v, dep[v] - dep[u] - 1);
      add(1, 1, in[u] - 1, diff);
      add(1, out[u] + 1, n, diff);
      add(1, in[v], out[v], diff);
    } else {
      add(1, in[u], out[u], diff);
      add(1, in[v], out[v], diff);
    }
    int ans = 0;
    if (T[1].mmax == edges.size()) ans = T[1].cnt;
    printf("%d\n", ans);
  }
}
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

const int maxn = 512345;

struct Seg {
  int l, r;
  int mx, u;
} T[maxn << 2];

int n, m, q, clk;
int p[maxn], a[maxn], b[maxn], in[maxn], out[maxn], par[maxn];
bool mark[maxn];
int op[maxn], x[maxn];
vector<int> G[maxn];

int Find(int u) {
  return par[u] == u ? u : par[u] = Find(par[u]);
}

void Union(int u, int v) {
  u = Find(u), v = Find(v);
  if (u == v) return;
  n++;
  par[n] = par[u] = par[v] = n;
  G[n].eb(u); G[n].eb(v);
}

void dfs(int u) {
  in[u] = ++clk;
  for (auto v : G[u]) dfs(v);
  out[u] = clk;
}

void push_up(int o) {
  int f = T[o << 1].mx < T[o << 1 | 1].mx;
  T[o].mx = T[o << 1 | f].mx;
  T[o].u = T[o << 1 | f].u;
}

void build(int o, int l, int r) {
  T[o].l = l, T[o].r = r;
  if (l < r) {
    int mi = l + r >> 1;
    build(o << 1, l, mi);
    build(o << 1 | 1, mi + 1, r);
  }
}

void update(int o, int u, int v, int i = 0) {
  if (T[o].l == T[o].r) {
    T[o].mx = v;
    T[o].u = i;
    return;
  }
  int mi = T[o].l + T[o].r >> 1;
  if (u <= mi) update(o << 1, u, v, i);
  else update(o << 1 | 1, u, v, i);
  push_up(o);
}

pii query(int o, int l, int r) {
  if (l <= T[o].l && T[o].r <= r) return mp(T[o].mx, T[o].u);
  int mi = T[o].l + T[o].r >> 1;
  pii ret = {0, 0};
  if (l <= mi) chkmax(ret, query(o << 1, l, r));
  if (r > mi) chkmax(ret, query(o << 1 | 1, l, r));
  return ret;
}

int main() {
  scanf("%d%d%d", &n, &m, &q);
  FOR(i, 1, n) scanf("%d", p + i);
  FOR(i, 1, m) scanf("%d%d", a + i, b + i);
  FOR(i, 1, q) {
    scanf("%d%d", op + i, x + i);
    if (op[i] == 2) mark[x[i]] = true;
  }
  iota(par + 1, par + n + 1, 1);
  FOR(i, 1, m) if (!mark[i]) Union(a[i], b[i]);
  ROF(i, q, 1) {
    if (op[i] == 2) Union(a[x[i]], b[x[i]]);
    else x[i] = Find(x[i]);
  }
  FOR(i, 1, n) if (Find(i) == i) dfs(i);
  build(1, 1, n);
  FOR(i, 1, n) update(1, in[i], p[i], i);
  FOR(i, 1, q) if (op[i] == 1) {
    auto [val, u] = query(1, in[x[i]], out[x[i]]);
    if (!val) {
      puts("0");
      continue;
    }
    printf("%d\n", val);
    update(1, in[u], 0);
  }
}
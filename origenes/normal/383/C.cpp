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
  int l, r, v;
} T[maxn << 2];

vector<int> G[maxn];
int n, m, clk;
int a[maxn], in[maxn], out[maxn], ver[maxn], dep[maxn];

void dfs(int u, int par) {
  in[u] = ++clk;
  ver[clk] = u;
  dep[u] = dep[par] + 1;
  for (auto v : G[u]) if (v != par) dfs(v, u);
  out[u] = clk;
}

void build(int o, int l, int r) {
  T[o].l = l, T[o].r = r;
  if (l < r) {
    int mi = l + r >> 1;
    build(o << 1, l, mi);
    build(o << 1 | 1, mi + 1, r);
  } else {
    T[o].v = a[ver[l]];
    if (dep[ver[l]] & 1) T[o].v = -T[o].v;
  }
}

void add(int o, int l, int r, int val) {
  if (l <= T[o].l && T[o].r <= r) {
    T[o].v += val;
    return;
  }
  int mi = T[o].l + T[o].r >> 1;
  if (l <= mi) add(o << 1, l, r, val);
  if (r > mi) add(o << 1 | 1, l, r, val);
}

int query(int o, int x, int even) {
  if (T[o].l == T[o].r) return T[o].v * even;
  int mi = T[o].l + T[o].r >> 1;
  return T[o].v * even + query(o << 1 | (x > mi), x, even);
}

int main() {
  scanf("%d%d", &n, &m);
  FOR(i, 1, n) scanf("%d", a + i);
  REP(i, n - 1) {
    int u, v;
    scanf("%d%d", &u, &v);
    G[u].eb(v); G[v].eb(u);
  }
  dfs(1, 0);
  build(1, 1, n);
  while (m--) {
    int op;
    scanf("%d", &op);
    if (op == 1) {
      int u, val;
      scanf("%d%d", &u, &val);
      if (dep[u] & 1) val = -val;
      add(1, in[u], out[u], val);
    } else {
      int u;
      scanf("%d", &u);
      printf("%d\n", query(1, in[u], (dep[u] & 1) ? -1 : 1));
    }
  }
}
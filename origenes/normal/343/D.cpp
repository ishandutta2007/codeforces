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
  int l, r, val;

  int width() {
    return r - l + 1;
  }
} T[maxn << 2];

int n, q, clk, in[maxn], out[maxn], p[maxn];
vector<int> G[maxn];

void dfs(int u, int par) {
  p[u] = par;
  in[u] = ++clk;
  for (auto v : G[u]) if (v != par) dfs(v, u);
  out[u] = clk;
}

void build(int o, int l, int r) {
  T[o].l = l, T[o].r = r;
  if (l < r) {
    int mi = l + r >> 1;
    build(o << 1, l, mi);
    build(o << 1 | 1, mi + 1, r);
  }
}

inline void push_down(int o) {
  if (T[o].val == T[o].width()) {
    T[o << 1].val = T[o << 1].width();
    T[o << 1 | 1].val = T[o << 1 | 1].width();
  } else if (!T[o].val)
    T[o << 1].val = T[o << 1 | 1].val = 0;
}

inline void push_up(int o) {
  T[o].val = T[o << 1].val + T[o << 1 | 1].val;
}

void update(int o, int l, int r, int val) {
  if (l <= T[o].l && T[o].r <= r) {
    T[o].val = val * T[o].width();
    return;
  }
  int mi = T[o].l + T[o].r >> 1;
  push_down(o);
  if (l <= mi) update(o << 1, l, r, val);
  if (r > mi) update(o << 1 | 1, l, r, val);
  push_up(o);
}

int query(int o, int l, int r) {
  if (l <= T[o].l && T[o].r <= r) return T[o].val;
  int mi = T[o].l + T[o].r >> 1, ret = 0;
  push_down(o);
  if (l <= mi) ret += query(o << 1, l, r);
  if (r > mi) ret += query(o << 1 | 1, l, r);
  return ret;
}

int main() {
  scanf("%d", &n);
  REP(i, n - 1) {
    int u, v;
    scanf("%d%d", &u, &v);
    G[u].eb(v);
    G[v].eb(u);
  }
  dfs(1, 0);
  build(1, 1, n);
  scanf("%d", &q);
  while (q--) {
    int c, v;
    scanf("%d%d", &c, &v);
    if (c == 1) {
      int now = query(1, in[v], out[v]);
      if (now != out[v] - in[v] + 1) update(1, in[p[v]], in[p[v]], 0);
      update(1, in[v], out[v], 1);
    } else if (c == 2) {
      update(1, in[v], in[v], 0);
    } else {
      printf("%d\n", query(1, in[v], out[v]) == out[v] - in[v] + 1);
    }
  }
}
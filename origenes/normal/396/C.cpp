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

namespace modular_arithmetic {
  int MOD;
  vector<int> fac, ifac;

  inline void set(int m) { MOD = m; }

  inline int add(int a, int b) {
    a += b;
    if (a >= MOD) a -= MOD;
    return a;
  }

  inline int mul(int a, int b) {
    return ll(a) * b % MOD;
  }

  int pow_mod(int a, int pw) {
    int ret = 1;
    while (pw) {
      if (pw & 1) ret = mul(ret, a);
      a = mul(a, a);
      pw >>= 1;
    }
    return ret;
  }

  int inv(int a) {
    return pow_mod(a, MOD - 2);
  }

  void get_fac(int n) {
    fac.resize(n + 1), ifac.resize(n + 1);
    fac[0] = 1;
    FOR(i, 1, n) fac[i] = mul(fac[i - 1], i);
    ifac[n] = inv(fac[n]);
    ROF(i, n - 1, 0) ifac[i] = mul(ifac[i + 1], i + 1);
  }

  int C(int n, int m) {
    if (m < 0 || m > n) return 0;
    return mul(fac[n], mul(ifac[m], ifac[n - m]));
  }
}

struct Seg {
  int l, r;
  int v, lv, k, lk;
} T[maxn << 2];

int n, q, clk;
int dfn[maxn], out[maxn], seq[maxn], dep[maxn];
vector<int> G[maxn];

void dfs(int u) {
  dfn[u] = ++clk;
  seq[clk] = u;
  for (auto v : G[u]) {
    dep[v] = dep[u] + 1;
    dfs(v);
  }
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
  T[o << 1].v = modular_arithmetic::add(T[o << 1].v, T[o].lv);
  T[o << 1].lv = modular_arithmetic::add(T[o << 1].lv, T[o].lv);
  T[o << 1 | 1].v = modular_arithmetic::add(T[o << 1 | 1].v, T[o].lv);
  T[o << 1 | 1].lv = modular_arithmetic::add(T[o << 1 | 1].lv, T[o].lv);
  T[o].lv = 0;
  T[o << 1].k = modular_arithmetic::add(T[o << 1].k, T[o].lk);
  T[o << 1].lk = modular_arithmetic::add(T[o << 1].lk, T[o].lk);
  T[o << 1 | 1].k = modular_arithmetic::add(T[o << 1 | 1].k, T[o].lk);
  T[o << 1 | 1].lk = modular_arithmetic::add(T[o << 1 | 1].lk, T[o].lk);
  T[o].lk = 0;
}

void add(int o, int l, int r, int x, int k) {
  if (l <= T[o].l && T[o].r <= r) {
    T[o].v = modular_arithmetic::add(T[o].v, x);
    T[o].lv = modular_arithmetic::add(T[o].lv, x);
    T[o].k = modular_arithmetic::add(T[o].k, k);
    T[o].lk = modular_arithmetic::add(T[o].lk, k);
    return;
  }
  int mi = T[o].l + T[o].r >> 1;
  push_down(o);
  if (l <= mi) add(o << 1, l, r, x, k);
  if (r > mi) add(o << 1 | 1, l, r, x, k);
}

pii query(int o, int x) {
  if (T[o].l == T[o].r) return {T[o].v, T[o].k};
  push_down(o);
  int mi = T[o].l + T[o].r >> 1;
  return query(o << 1 | (x > mi), x);
}

int main() {
  modular_arithmetic::set(1e9 + 7);
  scanf("%d", &n);
  FOR(i, 2, n) {
    int p; scanf("%d", &p);
    G[p].eb(i);
  }
  dfs(1);
  build(1, 1, clk);
  scanf("%d", &q);
  while (q--) {
    int op; scanf("%d", &op);
    if (op == 1) {
      int v, x, k; scanf("%d%d%d", &v, &x, &k);
      add(1, dfn[v], out[v], modular_arithmetic::add(x, modular_arithmetic::mul(dep[v], k)), k);
    } else {
      int v; scanf("%d", &v);
      int x, k;
      tie(x, k) = query(1, dfn[v]);
      printf("%d\n", modular_arithmetic::add(x, modular_arithmetic::MOD - modular_arithmetic::mul(dep[v], k)));
    }
  }
}
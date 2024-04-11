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

ll calc(int n, int other, const vector<int> *G, int &clk, int *in, int *out, int *sz, int *dep, ll *f, ll &one, int *seq) {
  auto dfs = [&](auto &&self, int u, int par) -> void {
    in[u] = ++clk;
    seq[clk] = u;
    dep[u] = dep[par] + 1;
    sz[u] = 1;
    for (auto v : G[u]) if (v != par) {
      self(self, v, u);
      sz[u] += sz[v];
    }
    out[u] = clk;
  };
  dfs(dfs, 1, 0);
  ll ret = 0;
  FOR(i, 1, n) f[0] += dep[i];
  auto dfs2 = [&](auto &&self, int u, int par) -> void {
    f[u] = f[par] + n - 2 * sz[u];
    ret += f[u];
    for (auto v : G[u]) if (v != par) self(self, v, u);
  };
  dfs2(dfs2, 1, 0);
  int best = 1;
  FOR(i, 2, n) if (f[i] > f[best]) best = i;
  one = f[best] * other;
  return ret;
}

struct Seg {
  int l, r;
  ll mx, lzy;
} T[maxn << 2];

void push_up(int o) {
  T[o].mx = max(T[o << 1].mx, T[o << 1 | 1].mx);
}

void push_down(int o) {
  T[o << 1].mx += T[o].lzy; T[o << 1].lzy += T[o].lzy;
  T[o << 1 | 1].mx += T[o].lzy; T[o << 1 | 1].lzy += T[o].lzy;
  T[o].lzy = 0;
}

void add(int o, int l, int r, ll x) {
  if (l <= T[o].l && T[o].r <= r) {
    T[o].mx += x; T[o].lzy += x;
    return;
  }
  push_down(o);
  int mi = T[o].l + T[o].r >> 1;
  if (l <= mi) add(o << 1, l, r, x);
  if (r > mi) add(o << 1 | 1, l, r, x);
  push_up(o);
}

ll fix(int n, int k1, int k2, const vector<int> *G, int clk, const int *in, const int *out, const int *dep, const ll *f, const int *seq) {
  auto build = [&](auto &&self, int o, int l, int r) -> void {
    T[o].l = l, T[o].r = r;
    T[o].lzy = 0;
    if (l < r) {
      int mi = l + r >> 1;
      self(self, o << 1, l, mi);
      self(self, o << 1 | 1, mi + 1, r);
      push_up(o);
    } else {
      T[o].mx = k1 * f[seq[l]] + ll(k1) * k2 * (dep[seq[l]] - 1);
    }
  };
  build(build, 1, 1, clk);
  ll ret = 0;
  auto dfs = [&](auto &&self, int u, int par) -> void {
    chkmax(ret, k2 * f[u] + T[1].mx);
    for (auto v : G[u]) if (v != par) {
      add(1, in[1], out[1], ll(k1) * k2);
      add(1, in[v], out[v], -2 * ll(k1) * k2);
      self(self, v, u);
      add(1, in[v], out[v], 2 * ll(k1) * k2);
      add(1, in[1], out[1], -ll(k1) * k2);
    }
  };
  dfs(dfs, 1, 0);
  return ret + ll(n) * k1 + ll(n) * k2 + ll(k1) * k2 * 2;
}

int n[3], clk[3];
ll f[3][maxn], one[3];
vector<int> G[3][maxn];
int in[3][maxn], seq[3][maxn], out[3][maxn], sz[3][maxn], dep[3][maxn];

int main() {
  REP(i, 3) scanf("%d", n + i);
  auto get = [](int n, vector<int> *G) {
    REP(i, n - 1) {
      int u, v; scanf("%d%d", &u, &v);
      G[u].eb(v); G[v].eb(u);
    }
  };
  REP(i, 3) get(n[i], G[i]);
  ll ans = 0;
  REP(i, 3) ans += calc(n[i], n[0] + n[1] + n[2] - n[i], G[i], clk[i], in[i], out[i], sz[i], dep[i], f[i], one[i], seq[i]);
  ans /= 2;
  ll best = 0;
  REP(i, 3) {
    ll now = one[0] + one[1] + one[2] - one[i];
    vector<int> tmp; REP(j, 3) if (j != i) tmp.eb(n[j]);
    chkmax(best, now + fix(n[i], tmp[0], tmp[1], G[i], clk[i], in[i], out[i], dep[i], f[i], seq[i]));
  }
  printf("%lld", ans + best);
}
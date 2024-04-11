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

int n, q, clk, st[maxn << 1][18], in[maxn], dep[maxn];

vector<int> G[maxn];

void dfs(int u, int par) {
  in[u] = ++clk;
  st[clk][0] = u;
  for (int v : G[u]) if (v != par) {
    dep[v] = dep[u] + 1;
    dfs(v, u);
    st[++clk][0] = u;
  }
}

void rmq_init() {
  FOR(i, 1, clk) FOR(j, 1, 17) {
    st[i][j] = st[i][j - 1];
    int val = i - (1 << j - 1);
    if (val > 0 && dep[st[val][j - 1]] < dep[st[i][j]])
      st[i][j] = st[val][j - 1];
  }
}

inline int rmq(int l, int r) {
  int val = floor(log(r - l + 1) / log(2));
  int u = st[l + (1 << val) - 1][val], v = st[r][val];
  return dep[u] < dep[v] ? u : v;
}

inline int lca(int u, int v) {
  if (in[u] > in[v]) swap(u, v);
  return rmq(in[u], in[v]);
}

struct Seg {
  int l, r, lca, mmin, mmax;
} T[maxn << 2];

void build(int o, int l, int r) {
  T[o].l = l, T[o].r = r;
  if (l == r) {
    T[o].lca = T[o].mmin = T[o].mmax = l;
    return;
  }
  int mi = l + r >> 1;
  build(o << 1, l, mi);
  build(o << 1 | 1, mi + 1, r);
  T[o].lca = lca(T[o << 1].lca, T[o << 1 | 1].lca);
  T[o].mmin = in[T[o << 1].mmin] < in[T[o << 1 | 1].mmin] ? T[o << 1].mmin : T[o << 1 | 1].mmin;
  T[o].mmax = in[T[o << 1].mmax] > in[T[o << 1 | 1].mmax] ? T[o << 1].mmax : T[o << 1 | 1].mmax;
}

pii get_pts(int o, int l, int r) {
  if (l <= T[o].l && T[o].r <= r) return {T[o].mmin, T[o].mmax};
  int mi = T[o].l + T[o].r >> 1;
  int mmin = -1, mmax = -1;
  if (l <= mi) {
    auto tmp = get_pts(o << 1, l, r);
    mmin = tmp._1, mmax = tmp._2;
  }
  if (r > mi) {
    auto tmp = get_pts(o << 1 | 1, l, r);
    if (mmin == -1) mmin = tmp._1, mmax = tmp._2;
    else {
      if (in[tmp._1] < in[mmin]) mmin = tmp._1;
      if (in[tmp._2] > in[mmax]) mmax = tmp._2;
    }
  }
  return {mmin, mmax};
}

int get_lca(int o, int l, int r) {
  if (l <= T[o].l && T[o].r <= r) return T[o].lca;
  int mi = T[o].l + T[o].r >> 1, ret = -1;
  if (l <= mi) ret = get_lca(o << 1, l, r);
  if (r > mi) {
    if (ret == -1) ret = get_lca(o << 1 | 1, l, r);
    else ret = lca(ret, get_lca(o << 1 | 1, l, r));
  }
  return ret;
}

int main() {
  scanf("%d%d", &n, &q);
  FOR(i, 2, n) {
    int p;
    scanf("%d", &p);
    G[p].eb(i);
    G[i].eb(p);
  }
  dfs(1, 0);
  rmq_init();
  build(1, 1, n);
  while (q--) {
    int l, r;
    scanf("%d%d", &l, &r);
    auto now = get_pts(1, l, r);
    int r1 = -1, r2 = -1, ans, rec = now._1;
    if (now._1 > l) r1 = get_lca(1, l, now._1 - 1);
    if (now._1 < r) r2 = get_lca(1, now._1 + 1, r);
    assert(r1 != -1 || r2 != -1);
    if (r1 == -1) ans = dep[r2];
    else if (r2 == -1) ans = dep[r1];
    else ans = dep[lca(r1, r2)];
    r1 = r2 = -1;
    if (now._2 > l) r1 = get_lca(1, l, now._2 - 1);
    if (now._2 < r) r2 = get_lca(1, now._2 + 1, r);
    assert(r1 != -1 || r2 != -1);
    if (r1 == -1) {
      if (ans < dep[r2]) {
        ans = dep[r2];
        rec = now._2;
      }
    }
    else if (r2 == -1) {
      if (ans < dep[r1]) {
        ans = dep[r1];
        rec = now._2;
      }
    }
    else {
      int a = lca(r1, r2);
      if (ans < dep[a]) {
        ans = dep[a];
        rec = now._2;
      }
    }
    printf("%d %d\n", rec, ans);
  }
}
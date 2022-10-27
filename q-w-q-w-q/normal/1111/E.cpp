#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
const int mod = 1e9 + 7, N = 100005, K = 305;
int n, q, d[N], l[N], r[N], cnt;
int sz[N], son[N], fa[N], top[N];
int f[N][K];
vector<int> to[N];
inline int add(int x, int y) { return x + y < mod ? x + y : x + y - mod; }
namespace bits {
int s[N];
inline int lb(int x) { return x & (-x); }
inline void add(int x, int v) {
  while (x <= n) s[x] += v, x += lb(x);
}
inline int query(int x) {
  int ans = 0;
  while (x) ans += s[x], x -= lb(x);
  return ans;
}
}  // namespace bits
struct p {
  int x, d, lca;
  bool operator<(const p &j) const { return d < j.d; }
} a[N];
void dfs1(int i) {
  l[i] = ++cnt, sz[i] = 1;
  for (int j : to[i]) {
    to[j].erase(find(to[j].begin(), to[j].end(), i));
    d[j] = d[i] + 1, fa[j] = i, dfs1(j);
    sz[i] += sz[j];
    if (sz[son[i]] < sz[j]) son[i] = j;
  }
  r[i] = cnt;
}
void dfs2(int i, int tp) {
  top[i] = tp;
  if (son[i]) dfs2(son[i], tp);
  for (int j : to[i])
    if (j != son[i]) dfs2(j, j);
}
inline int lca(int x, int y) {
  while (top[x] != top[y]) {
    if (d[top[x]] < d[top[y]]) swap(x, y);
    x = fa[top[x]];
  }
  return d[x] < d[y] ? x : y;
}
int main() {
  cin >> n >> q;
  for (int i = 1; i < n; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    to[x].push_back(y), to[y].push_back(x);
  }
  dfs1(1), dfs2(1, 1);
  while (q--) {
    int k, m, rt;
    scanf("%d%d%d", &k, &m, &rt);
    for (int i = 1; i <= k; i++) {
      scanf("%d", &a[i].x), a[i].lca = lca(a[i].x, rt);
      a[i].d = d[a[i].x] + d[rt] - 2 * d[a[i].lca];
    }
    sort(a + 1, a + k + 1);
    f[0][0] = 1;
    for (int i = 1; i <= k; i++) {
      int x = a[i].x, y = a[i].lca;
      int s = bits::query(l[x]) + bits::query(l[rt]) - bits::query(l[y]) - bits::query(l[fa[y]]);
      for (int j = s + 1; j <= i && j <= m; j++) f[i][j] = (f[i - 1][j - 1] + 1ll * f[i - 1][j] * (j - s)) % mod;
      bits::add(l[x], 1), bits::add(r[x] + 1, -1);
    }
    int ans = 0;
    for (int i = 1; i <= m; i++) ans = add(ans, f[k][i]);
    printf("%d\n", ans);
    for (int i = 1; i <= k; i++) {
      memset(f[i], 0, sizeof f[i]);
      int x = a[i].x;
      bits::add(l[x], -1), bits::add(r[x] + 1, 1);
    }
  }
}
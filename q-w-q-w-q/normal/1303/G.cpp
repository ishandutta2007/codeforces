#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
const int N = 150005;
int n, x, y, a[N];
int sz[N], son[N];
ll ans;
bool u[N];
vector<int> to[N];
struct sgt {
  int cnt, rt, lc[N << 6], rc[N << 6];
  ll k[N << 6], b[N << 6];
  inline ll get(ll k, ll b, ll x) { return k * x + b; }
  inline void clear() {
    memset(lc, 0, (cnt + 1) << 2), memset(rc, 0, (cnt + 1) << 2);
    memset(k, 0, (cnt + 1) << 3), memset(b, 0, (cnt + 1) << 3);
    rt = cnt = 0;
  }
  inline void ins(int &i, ll l, ll r, ll tk, ll tb) {
    if (l > r) return;
    if (!i) i = ++cnt;
    if (!k[i]) {
      k[i] = tk, b[i] = tb;
      return;
    }
    ll mid = (l + r) >> 1;
    if (get(tk, tb, l) >= get(k[i], b[i], l)) swap(tk, k[i]), swap(tb, b[i]);
    if (get(k[i], b[i], r) >= get(tk, tb, r)) return;
    if (get(k[i], b[i], mid) >= get(tk, tb, mid))
      ins(rc[i], mid + 1, r, tk, tb);
    else {
      swap(tk, k[i]), swap(tb, b[i]);
      ins(lc[i], l, mid, tk, tb);
    }
  }
  inline ll query(int i, ll l, ll r, ll x) {
    if (!i) return 0;
    ll ans = get(k[i], b[i], x), mid = (l + r) >> 1;
    if (l == r) return ans;
    if (x <= mid) return max(ans, query(lc[i], l, mid, x));
    return max(ans, query(rc[i], mid + 1, r, x));
  }
} t1, t2;
inline void dfs1(int i, int fa, int d, ll s1, ll s2, ll s3) {
  ll tp = ans;
  ans = max({ans, s2 + t1.query(t1.rt, 1, 1e12, s1), s3 + t2.query(t2.rt, 1, n, d)});
  if (tp < 55 && ans == 55) cout << i << ' ' << fa << ' ' << t2.query(t2.rt, 1, n, d) << ' ' << d << endl;
  for (int j : to[i])
    if (j != fa && !u[j]) dfs1(j, i, d + 1, s1 + a[j], s2 + 1ll * a[j] * (d + 1), s3 + a[j] + s1);
}
inline void dfs2(int i, int fa, int d, ll s1, ll s2, ll s3) {
  t1.ins(t1.rt, 1, 1e12, d, s3), t2.ins(t2.rt, 1, n, s1, s2);
  sz[i] = 1, son[i] = 0;
  for (int j : to[i]) {
    if (j == fa || u[j]) continue;
    dfs2(j, i, d + 1, s1 + a[j], s2 + 1ll * a[j] * (d + 1), s3 + a[j] + s1);
    sz[i] += sz[j];
    if (sz[son[i]] < sz[j]) son[i] = j;
  }
}
inline int centroid(int x) {
  for (int i = x;; i = son[i])
    if (sz[son[i]] * 2 <= sz[x]) return i;
}
inline void solve(int x) {
  u[x] = 1, t1.ins(t1.rt, 1, 1e12, 1, a[x]), t2.ins(t2.rt, 1, n, a[x], a[x]);
  for (int j : to[x])
    if (!u[j])
      dfs1(j, x, 1, a[j], a[j], a[j]), dfs2(j, x, 2, a[x] + a[j], 2 * a[j] + a[x], a[j] + 2 * a[x]);
  t1.clear(), t2.clear();
  for (int j : to[x])
    if (!u[j]) solve(centroid(j));
}
int main() {
  cin >> n;
  for (int i = 1; i < n; i++) {
    scanf("%d%d", &x, &y);
    to[x].push_back(y), to[y].push_back(x);
  }
  for (int i = 1; i <= n; i++) scanf("%d", a + i);
  solve(1);
  cout << ans;
}
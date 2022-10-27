#include <cstdio>
#include <ctime>
#include <iostream>
#include <random>
using namespace std;
const int N = 200005, mod = 998244353;
int t, n, m, rt, lt;
int fac[2 * N], ifac[2 * N];
inline int power(int a, int n) {
  int tp = 1;
  while (n) {
    if (n & 1) tp = 1ll * tp * a % mod;
    a = 1ll * a * a % mod, n >>= 1;
  }
  return tp;
}
namespace fhq {
mt19937 rnd(time(0));
int cnt, l[N], r[N], w[N], sz[N], lc[N], rc[N];
inline int newnode(int x, int y) {
  cnt++;
  l[cnt] = x, r[cnt] = y, sz[cnt] = y - x + 1;
  lc[cnt] = rc[cnt] = 0;
  w[cnt] = rnd();
  return cnt;
}
inline void update(int i) { sz[i] = sz[lc[i]] + sz[rc[i]] + r[i] - l[i] + 1; }
void split(int i, int t, int &x, int &y) {
  if (!i) {
    x = y = 0;
    return;
  }
  if (sz[lc[i]] + r[i] - l[i] + 1 > t)
    y = i, split(lc[i], t, x, lc[y]);
  else
    x = i, split(rc[i], t - (sz[lc[i]] + r[i] - l[i] + 1), rc[x], y);
  update(i);
}
int merge(int i, int j) {
  if (!i || !j) return i | j;
  if (w[i] < w[j]) {
    rc[i] = merge(rc[i], j), update(i);
    return i;
  }
  lc[j] = merge(i, lc[j]), update(j);
  return j;
}
inline int lmodify(int i, int x) {
  while (lc[i]) sz[i] -= x, i = lc[i];
  sz[i] -= x;
  int k = l[i];
  l[i] += x;
  return k;
}
inline void _split(int i, int t, int &x, int &y) {
  split(i, t, x, y);
  if (sz[x] < t) {
    int tp = t - sz[x], z = lmodify(y, tp);
    int p = newnode(z, z + tp - 1);
    x = merge(x, p);
  }
}
int query(int i) {
  int ans = 0;
  if (lc[i]) ans = query(lc[i]);
  if (l[i] < lt) ans++;
  lt = r[i];
  if (rc[i]) ans += query(rc[i]);
  return ans;
}
}  // namespace fhq
inline int c(int n, int m) { return 1ll * fac[n] * ifac[m] % mod * ifac[n - m] % mod; }
int main() {
  n = 399999;
  fac[0] = 1;
  for (int i = 1; i <= n; i++) fac[i] = 1ll * fac[i - 1] * i % mod;
  ifac[n] = power(fac[n], mod - 2);
  for (int i = n - 1; ~i; i--) ifac[i] = 1ll * ifac[i + 1] * (i + 1) % mod;
  cin >> t;
  while (t--) {
    scanf("%d%d", &n, &m);
    int lp = 0;
    while (m--) {
      int x, y;
      scanf("%d%d", &x, &y);
      if (lp < x - 1) {
        int tp = fhq::newnode(lp + 1, x - 1);
        rt = fhq::merge(rt, tp);
      }
      int z = fhq::newnode(x, x);
      int t1, t2;
      fhq::_split(rt, y - 1, t1, t2);
      rt = fhq::merge(t1, fhq::merge(z, t2));
      lp = x;
    }
    lt = 0;
    printf("%d\n", c(n - 1 - fhq::query(rt) + n, n));
    fhq::cnt = rt = 0;
  }
}
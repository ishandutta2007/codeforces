#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
typedef unsigned long long ull;
const int N = 100005, mod = 998244353, o = 17, len = 1 << o, i2 = (mod + 1) >> 1;
int n, a[N], cnt, ans, tot, f[N], fac[N];
bool op[N];
inline int add(int x, int y) {return x + y < mod ? x + y : x + y - mod;}
inline int sub(int x, int y) {return x < y ? x + mod - y : x - y;}
inline int power(int a, int n) {
  int tp = 1;
  while (n) {
    if (n & 1)tp = 1ll * tp * a % mod;
    a = 1ll * a * a % mod, n >>= 1;
  }
  return tp;
}
namespace poly {
int w[len], r[len], up, l;
void init() {
  const int w0 = power(3, (mod - 1) >> o);
  w[len >> 1] = 1;
  for (int i = (len >> 1) + 1; i < len; i++) w[i] = 1ll * w[i - 1] * w0 % mod;
  for (int i = (len >> 1) - 1; i; i--) w[i] = w[i << 1];
}
inline void pre(int n) {
  up = 2, l = 1;
  while (up <= n) up <<= 1, l++;
  for (int i = 0; i < up; i++) r[i] = (r[i >> 1] >> 1) | ((i & 1) << (l - 1));
}
void ntt(int *a, int n, bool op) {
  static ull t[len], x, y;
  for (int i = 0; i < n ; i++) t[i] = a[r[i]];
  for (int l = 1; l < n; l <<= 1) {
    int *k = w + l;
    for (ull *f = t; f != t + n; f += l)
      for (int *j = k; j != k + l; j++, f++) {
        x = *f, y = f[l]**j % mod;
        f[l] = x + mod - y, *f += y;
      }
  }
  if (op) {
    for (int i = 0, x = mod - ((mod - 1) >> l); i < n; i++) a[i] = t[i] * x % mod;
    reverse(a + 1, a + n);
  } else for (int i = 0; i < n; i++) a[i] = t[i] % mod;
}
}
namespace cdq {
using namespace poly;
int tot, vf[2][2][len << 5];
int *f[len << 1][2][2];
void solve(int i, int l, int r) {
  static int a[8][len], b[len], c[len];
  for (int o1 = 0; o1 < 2; o1++)
    for (int o2 = 0; o2 < 2; o2++)
      f[i][o1][o2] = vf[o1][o2] + tot;
  tot += r - l + 1;
  if (r - l == 1) {
    if (op[l]) {
      if (op[r]) f[i][0][0][0] = 1, f[i][1][1][1] = 4;
      else f[i][0][1][0] = 1, f[i][1][1][1] = 2;
    } else {
      if (op[r]) f[i][1][0][0] = 1, f[i][1][1][1] = 2;
      else f[i][1][1][0] = f[i][1][1][1] = 1;
    }
    return;
  }
  if (r - l == 2) {
    if (op[l]) {
      if (op[r]) {
        if (op[l + 1]) f[i][0][0][0] = 1, f[i][1][0][1] = f[i][0][1][1] = 4, f[i][1][1][2] = 8;
        else f[i][0][0][0] = 1, f[i][1][0][1] = f[i][0][1][1] = 2, f[i][1][1][2] = 4;
      } else {
        if (op[l + 1]) f[i][0][1][0] = 1, f[i][1][1][1] = 4, f[i][0][1][1] = 2, f[i][1][1][2] = 4;
        else f[i][0][1][0] = 1, f[i][1][1][1] = 2, f[i][0][1][1] = 1, f[i][1][1][2] = 2;
      }
    } else {
      if (op[r]) {
        if (op[l + 1]) f[i][1][0][0] = 1, f[i][1][0][1] = 2, f[i][1][1][1] = 4, f[i][1][1][2] = 4;
        else f[i][1][0][0] = 1, f[i][1][0][1] = 1, f[i][1][1][1] = 2, f[i][1][1][2] = 2;
      } else {
        if (op[l + 1]) f[i][1][1][0] = 1, f[i][1][1][1] = 4, f[i][1][1][2] = 2;
        else f[i][1][1][0] = 1, f[i][1][1][1] = 2, f[i][1][1][2] = 1;
      }
    }
    return;
  }
  int mid = (l + r) >> 1, l1 = mid - l, l2 = r - mid - 1;
  solve(i << 1, l, mid), solve(i << 1 | 1, mid + 1, r);
  pre(r - l - 1);
  memcpy(a[0], f[i << 1][0][0], (l1 + 1) << 2);
  memcpy(a[1], f[i << 1][0][1], (l1 + 1) << 2);
  memcpy(a[2], f[i << 1][1][0], (l1 + 1) << 2);
  memcpy(a[3], f[i << 1][1][1], (l1 + 1) << 2);
  memcpy(a[4], f[i << 1 | 1][0][0], (l2 + 1) << 2);
  memcpy(a[5], f[i << 1 | 1][0][1], (l2 + 1) << 2);
  memcpy(a[6], f[i << 1 | 1][1][0], (l2 + 1) << 2);
  memcpy(a[7], f[i << 1 | 1][1][1], (l2 + 1) << 2);
  for (int j = 0; j < 8; j++) ntt(a[j], up, 0);
  for (int o1 = 0; o1 < 2; o1++)
    for (int o2 = 0; o2 < 2; o2++) {
      for (int j = 0; j < up; j++) {
        b[j] = (b[j] + 1ll * a[o1 * 2][j] * a[4 + o2][j] + 1ll * a[o1 * 2][j] * a[6 + o2][j] + 1ll * a[o1 * 2 + 1][j] * a[4 + o2][j] + 1ll * a[o1 * 2 + 1][j] * a[6 + o2][j]) % mod;
        c[j] = (c[j] + 4ll * a[o1 * 2][j] * a[4 + o2][j] + 2ll * a[o1 * 2][j] * a[6 + o2][j] + 2ll * a[o1 * 2 + 1][j] * a[4 + o2][j] + 1ll * a[o1 * 2 + 1][j] * a[6 + o2][j]) % mod;
      }
      ntt(b, up, 1), ntt(c, up, 1);
      memcpy(f[i][o1][o2], b, (r - l) << 2);
      for (int j = 1; j <= r - l; j++) f[i][o1][o2][j] = add(f[i][o1][o2][j], c[j - 1]);
      memset(b, 0, up << 2), memset(c, 0, up << 2);
    }
  for (int j = 0; j < 8; j++) memset(a[j], 0, up << 2);
}
}
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) scanf("%d", a + i);
  for (int i = 1; i <= n; i += a[i]) {
    for (int k = i; k < i + a[i]; k++)
      if (a[k] != a[i]) {
        cout << 0;
        return 0;
      }
    cnt++;
    if (a[i] == 1) op[cnt] = 1, tot++;
  }
  if (cnt == 1) {
    cout << 2 - op[1];
    return 0;
  }
  fac[0] = 1;
  for (int i = 1; i <= cnt; i++) fac[i] = 1ll * fac[i - 1] * i % mod;
  poly::init(), cdq::solve(1, 1, cnt);
  for (int i = 0, x = power(2, cnt - tot); i < cnt; i++, x = 1ll * x * i2 % mod) {
    int s = 0;
    for (int o1 = 0; o1 < 2; o1++)
      for (int o2 = 0; o2 < 2; o2++)
        s = add(s, cdq::f[1][o1][o2][i]);
    if (i & 1) ans = sub(ans, 1ll * x * s % mod * fac[cnt - i] % mod);
    else ans = (ans + 1ll * x * s % mod * fac[cnt - i]) % mod;
  }
  cout << ans;
}
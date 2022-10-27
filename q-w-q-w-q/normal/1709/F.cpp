#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

const int o = 19, len = 1 << o, mod = 998244353;
int n, k, m, f[len];

int add(int x, int y) { return x + y < mod ? x + y : x + y - mod; }

int power(int a, int n) {
  int tp = 1;
  while (n) {
    if (n & 1)
      tp = 1ll * tp * a % mod;
    a = 1ll * a * a % mod, n >>= 1;
  }
  return tp;
}

namespace poly {
typedef unsigned long long u64;
int w[len], r[len], up, l;

void init() {
  const int w0 = power(3, (mod - 1) >> o);
  w[len >> 1] = 1;
  for (int i = (len >> 1) + 1; i != len; i++)
    w[i] = 1ll * w[i - 1] * w0 % mod;
  for (int i = (len >> 1) - 1; i; i--)
    w[i] = w[i << 1];
  for (int i = 0; i != len; i++)
    r[i] = (r[i >> 1] >> 1) | ((i & 1) << (o - 1));
}

void ntt(int *a, int n, bool op) {
  static u64 t[len], x, y;
  for (int i = 0; i != n; i += 2) {
    x = a[r[i] >> (o - l)], y = a[r[i + 1] >> (o - l)];
    t[i] = x + y, t[i + 1] = x + mod - y;
  }
  for (int l = 2; l != n; l <<= 1) {
    if (l == (1 << 18))
      for (u64 *f = t; f != t + n; f++)
        *f %= mod;
    int *k = w + l;
    for (u64 *f = t; f != t + n; f += l)
      for (int *j = k; j != k + l; j++, f++) {
        u64 x = *f, y = f[l] * *j % mod;
        f[l] = x + mod - y, *f += y;
      }
  }
  if (op) {
    if (n == (1 << 18))
      for (u64 *f = t; f != t + n; f++)
        *f %= mod;
    for (int i = 0, x = mod - (mod >> l); i != n; i++)
      a[i] = t[i] * x % mod;
    reverse(a + 1, a + n);
  } else
    for (int i = 0; i != n; i++)
      a[i] = t[i] % mod;
}

int pre(int n) {
  l = 32 - __builtin_clz(n);
  return up = 1 << l;
}
}  // namespace poly

int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  poly::init();
  cin >> n >> k >> m;
  int up = poly::pre(2 * k);
  fill(f, f + k + 1, 1);
  while (--n) {
    poly::ntt(f, up, 0);
    for (int i = 0; i != up; i++)
      f[i] = 1ll * f[i] * f[i] % mod;
    poly::ntt(f, up, 1);

    for (int i = 2 * k, s = 0; i != -1; i--) {
      if (i > k) {
        s = add(s, f[i]);
        f[i] = 0;
        continue;
      }
      int x = (s + 1ll * f[i] * (k - i + 1)) % mod;
      s = add(s, f[i]);
      f[i] = x;
    }
  }

  int ans = 0;
  for (int i = 0; i <= m; i++)
    ans = (ans + 1ll * f[i] * f[m - i]) % mod;
  cout << ans;
}
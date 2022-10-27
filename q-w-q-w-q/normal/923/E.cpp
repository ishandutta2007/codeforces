#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

const int mod = 998244353, o = 18, len = 1 << o;
int n, a[len], b[len], piv[len];
int fac[len], ifac[len];
long long m;

int power(int a, int n) {
  int tp = 1;
  while (n) {
    if (n & 1)
      tp = 1ll * tp * a % mod;
    a = 1ll * a * a % mod, n >>= 1;
  }
  return tp;
}

void prep(int n) {
  fac[0] = 1;
  for (int i = 1; i <= n; i++)
    fac[i] = 1ll * fac[i - 1] * i % mod;
  ifac[n] = power(fac[n], mod - 2);
  for (int i = n - 1; i != -1; i--)
    ifac[i] = 1ll * ifac[i + 1] * (i + 1) % mod;

  n++, piv[1] = 1;
  for (int i = 2; i <= n; i++)
    if (!piv[i]) {
      piv[i] = power(i, mod - 1 - m);
      for (int j = 2; i * j <= n; j++)
        piv[i * j] = 1ll * piv[i] * piv[j] % mod;
    }
}

namespace poly {
typedef unsigned long long u64;
int w[len], r[len], up, l;

void init() {
  const int w1 = power(3, (mod - 1) >> o);
  w[len >> 1] = 1;
  for (int i = (len >> 1) + 1; i != len; i++)
    w[i] = 1ll * w[i - 1] * w1 % mod;
  for (int i = (len >> 1) - 1; i; i--)
    w[i] = w[i << 1];
  for (int i = 0; i != len; i++)
    r[i] = (r[i >> 1] >> 1) | ((i & 1) << (o - 1));
}

void ntt(int *a, int n, bool op) {
  static u64 t[len];
  for (int i = 0; i != n; i += 2) {
    int x = a[r[i] >> (o - l)], y = a[r[i + 1] >> (o - l)];
    t[i] = x + y, t[i + 1] = x + mod - y;
  }
  for (int l = 2; l != n; l <<= 1) {
    int *k = w + l;
    for (u64 *f = t; f != t + n; f += l)
      for (int *j = k; j != k + l; j++, f++) {
        u64 x = *f, y = f[l] * *j % mod;
        f[l] = x + mod - y, *f += y;
      }
  }

  if (op) {
    for (int i = 0, x = mod - (mod >> l); i != n; i++)
      a[i] = t[i] * x % mod;
    reverse(a + 1, a + n);
  } else
    for (int i = 0; i != n; i++)
      a[i] = t[i] % mod;
}

int pre(int n) {
  l = __lg(n) + 1;
  return up = 1 << l;
}
}  // namespace poly

int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  cin >> n >> m, m %= mod - 1;
  poly::init(), prep(n);
  for (int i = 0; i <= n; i++)
    cin >> a[i], a[i] = 1ll * a[i] * fac[i] % mod;

  int up = poly::pre(2 * n);
  memcpy(b, ifac, (n + 1) << 2);
  poly::ntt(a, up, 1), poly::ntt(b, up, 0);
  for (int i = 0; i != up; i++)
    a[i] = 1ll * a[i] * b[i] % mod;
  poly::ntt(a, up, 0);
  for (int i = 0; i <= n; i++)
    a[i] = 1ll * a[i] * piv[i + 1] % mod;
  for (int i = n + 1; i != up; i++)
    a[i] = 0;
  for (int i = 0; i != up / 2; i++)
    swap(b[i], b[up / 2 + i]);
  poly::ntt(a, up, 1);
  for (int i = 0; i != up; i++)
    a[i] = 1ll * a[i] * b[i] % mod;
  poly::ntt(a, up, 0);
  for (int i = 0; i <= n; i++)
    cout << 1ll * a[i] * ifac[i] % mod << " \n"[i == n];
}
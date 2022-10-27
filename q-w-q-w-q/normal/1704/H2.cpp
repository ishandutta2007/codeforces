#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

typedef unsigned long long u64;
typedef __uint128_t u128;

const int o = 18, len = 1 << o, B = 16;
int n, fac[len], ifac[len], iv[len], mod;
int f[len], ef[len], xef[len], a[len], b[len], h[len];

struct fastmod {
  u64 b;
  int m;

  fastmod(int mod) : b(((u128)1 << 64) / mod), m(mod) {}
  int reduce(u64 a) { return a % m; }
} z(998244353);

int add(int x, int y) { return x + y < mod ? x + y : x + y - mod; }
int sub(int x, int y) { return x < y ? x + mod - y : x - y; }

int power(int a, int n) {
  int tp = 1;
  while (n) {
    if (n & 1)
      tp = z.reduce(1ll * tp * a);
    a = z.reduce(1ll * a * a), n >>= 1;
  }
  return tp;
}

void prep(int n) {
  fac[0] = 1;
  for (int i = 1; i <= n; i++)
    fac[i] = z.reduce(1ll * fac[i - 1] * i);
  ifac[n] = power(fac[n], mod - 2);
  for (int i = n - 1; i != -1; i--)
    ifac[i] = z.reduce(1ll * ifac[i + 1] * (i + 1));
  for (int i = 1; i <= n; i++)
    iv[i] = z.reduce(1ll * ifac[i] * fac[i - 1]);
  iv[0] = 1;
}

namespace poly {
int I[len], w[len], r[len], up, l;

int findg(int n) {
  static int a[101];
  int cnt = 0, x = n - 1;
  for (int i = 2; i * i <= x; i++)
    if (x % i == 0) {
      a[++cnt] = i;
      while (x % i == 0)
        x /= i;
    }
  if (x > 1)
    a[++cnt] = x;

  for (int g = 2;; g++) {
    bool ok = 1;
    for (int i = 1; i <= cnt; i++)
      if (power(g, (n - 1) / a[i]) == 1) {
        ok = 0;
        break;
      }
    if (ok)
      return g;
  }
}

void init() {
  I[0] = 1;
  const int w0 = power(findg(mod), (mod - 1) >> o);
  w[len >> 1] = 1;
  for (int i = (len >> 1) + 1; i != len; i++)
    w[i] = z.reduce(1ll * w[i - 1] * w0);
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
    int *k = w + l;
    for (u64 *f = t; f != t + n; f += l)
      for (int *j = k; j != k + l; j++, f++) {
        u64 x = *f, y = z.reduce(f[l] * *j);
        f[l] = x + mod - y, *f += y;
      }
  }
  if (op) {
    for (int i = 0, x = mod - (mod >> l); i != n; i++)
      a[i] = z.reduce(t[i] * x);
    reverse(a + 1, a + n);
  } else
    for (int i = 0; i != n; i++)
      a[i] = z.reduce(t[i]);
}

void pre(int n) { l = 32 - __builtin_clz(n), up = 1 << l; }

void mul(int *f, int n, int *g, int m, int *h, int q) {
  static int x[len], y[len];
  memcpy(x, f, (n + 1) << 2), memcpy(y, g, (m + 1) << 2);
  pre(n + m), ntt(x, up, 0), ntt(y, up, 0);
  for (int i = 0; i < up; i++)
    h[i] = z.reduce(1ll * x[i] * y[i]);
  ntt(h, up, 1);
  memset(x, 0, up << 2), memset(y, 0, up << 2), fill(h + q + 1, h + up, 0);
}

void div(int *a, int *b, int n, int *f) {
  static int iv[len], x[len], tmp[len];
  static int nb[len << 2], nf[len << 2];
  static u64 s0[len], s1[len];
  if (n <= 16) {
    int x = power(b[0], mod - 2);
    for (int i = 0; i <= n; i++) {
      u64 s = 0;
      for (int j = 0; j != i; j++)
        s += 1ll * f[j] * b[i - j];
      f[i] = z.reduce(1ll * x * (a[i] + mod - z.reduce(s)));
    }
    return;
  }

  int m = 1 << (32 - __builtin_clz(n));
  int k = m >> 4, z = k << 1;
  div(I, b, k - 1, tmp), memcpy(x, a, k << 2);
  memcpy(iv, tmp, k << 2), memset(tmp, 0, k << 2);
  pre(z - 1);
  ntt(iv, up, 0), ntt(x, up, 0);
  for (int i = 0; i != up; i++)
    x[i] = ::z.reduce(1ll * x[i] * iv[i]);
  ntt(x, up, 1);
  memcpy(f, x, k << 2);
  memset(x, 0, up << 2);
  memcpy(nb, b, k << 2);
  ntt(nb, up, 0);
  for (int i = 1;; i++) {
    if (i * k > n) {
      memset(iv, 0, up << 2);
      memset(nb, 0, i * z * 4);
      memset(nf, 0, (i - 1) * z * 4);
      fill(f + n + 1, f + i * k, 0);
      break;
    }
    memcpy(nb + i * z, b + i * k, k << 2);
    memcpy(nf + (i - 1) * z, f + (i - 1) * k, k << 2);
    ntt(nb + i * z, up, 0), ntt(nf + (i - 1) * z, up, 0);
    for (int l1 = 0; l1 != i; l1++)
      for (int j = 0; j != up; j++)
        s0[j] += 1ll * nf[l1 * z + j] * nb[(i - l1) * z + j];
    for (int l1 = 0; l1 != i; l1++)
      for (int j = 0; j != up; j++)
        s1[j] += 1ll * nf[l1 * z + j] * nb[(i - l1 - 1) * z + j];
    for (int j = 0; j != up; j += 2) {
      x[j] = ::z.reduce(s0[j] + ::z.reduce(s1[j]));
      x[j + 1] = ::z.reduce(s0[j + 1] + mod - ::z.reduce(s1[j + 1]));
      s0[j] = s1[j] = s0[j + 1] = s1[j + 1] = 0;
    }
    ntt(x, up, 1);
    memset(x + k, 0, k << 2);
    for (int j = 0; j != k; j++)
      x[j] = sub(a[i * k + j], x[j]);
    ntt(x, up, 0);
    for (int j = 0; j != up; j++)
      x[j] = ::z.reduce(1ll * x[j] * iv[j]);
    ntt(x, up, 1);
    memcpy(f + i * k, x, k << 2);
    memset(x, 0, up << 2);
  }
}

void dcexp(int *a, int l, int r, int n, int *f, int *g, int *h) {
  static u64 s[len];
  static int tp[len];
  if (r - l + 1 <= 32) {
    for (int i = l; i <= r && i <= n; i++) {
      u64 s = 0;
      for (int j = l; j < i; j++) {
        s += 1ll * f[j] * a[i - j];
        if (!(j & 15))
          s = z.reduce(s);
      }
      f[i] = z.reduce(((u64)f[i] + z.reduce(s)) * iv[i]);
    }
    return;
  }
  int *tg[B], *th[B];
  int len = (r - l + 1) / B, k = 2 * len;
  for (int i = 0; i < B - 1; i++)
    tg[i] = g + i * k, th[i] = h + i * k;
  if (!l) {
    pre(k - 1);
    for (int i = 0; i < B - 1; i++) {
      if ((i + 1) * len > n)
        break;
      memcpy(th[i], a + i * len, k << 2);
      ntt(th[i], k, 0);
    }
  }
  for (int i = 0; i < B; i++) {
    if (l + i * len > n)
      break;
    memset(s, 0, k << 3);
    for (int j = 0; j != i; j++)
      for (int t = 0; t != k; t++)
        s[t] += 1ll * tg[j][t] * th[i - j - 1][t];
    for (int t = 0; t != k; t++)
      tp[t] = z.reduce(s[t]);
    pre(k - 1), ntt(tp, k, 1);
    for (int t = 0; t < len; t++)
      f[l + i * len + t] = add(f[l + i * len + t], tp[t + len]);
    dcexp(a, l + i * len, l + (i + 1) * len - 1, n, f, g + k * B, h + k * B);
    if (i != B - 1) {
      memcpy(tg[i], f + l + i * len, len << 2);
      pre(k - 1), ntt(tg[i], k, 0);
    }
  }
  memset(tg[0], 0, (k * B) << 2);
}

void exp(int *a, int n, int *f) {
  static int x[len << 1], v1[len << 2], v2[len << 2];
  for (int i = 1; i <= n; i++)
    x[i] = z.reduce(1ll * a[i] * i);
  f[0] = 1, fill(f + 1, f + n + 1, 0);
  int m = 1 << (32 - __builtin_clz(n));
  dcexp(x, 0, m - 1, n, f, v1, v2);
  memset(x, 0, (n + 1) << 2), fill(f + n + 1, f + m, 0);
}
} // namespace poly

void calc(int n) {
  static int xef[len], eef[len], a[len], b[len], c[len];
  if (n == 2) {
    f[2] = 1;
    return;
  }

  calc((n + 1) / 2);
  poly::exp(f, n - 1, xef);
  for (int i = n; i; i--)
    xef[i] = xef[i - 1];
  xef[0] = 0;
  for (int i = 1; i <= n; i++)
    a[i] = add(xef[i], f[i]);
  poly::exp(a, n - 1, eef);
  for (int i = n; i; i--)
    eef[i] = eef[i - 1];
  eef[0] = 0;
  poly::pre(2 * n);
  int up = poly::up;
  poly::ntt(a, up, 0), poly::ntt(eef, up, 0);
  for (int i = 0; i != up; i++)
    c[i] = z.reduce(1ll * a[i] * eef[i]);
  poly::ntt(c, up, 1), fill(c + n + 1, c + up, 0);
  for (int i = 1; i <= n; i++)
    c[i] = sub(f[i], c[i]);
  xef[0] = 1;
  poly::ntt(xef, up, 0);
  for (int i = 0; i != up; i++)
    b[i] = z.reduce(1ll * xef[i] * (a[i] + 1));
  poly::ntt(b, up, 1);
  fill(b + n + 1, b + up, 0);
  poly::ntt(b, up, 0);
  for (int i = 0; i != up; i++)
    b[i] = z.reduce(1ll * b[i] * eef[i]);
  poly::ntt(b, up, 1);
  fill(b + n + 1, b + up, 0);
  b[0] = 1;
  for (int i = 1; i <= n; i++)
    b[i] = sub(0, b[i]);
  memset(a, 0, up << 2);
  poly::div(c, b, n, a);
  for (int i = 2; i <= n; i++)
    f[i] = sub(f[i], a[i]);

  memset(xef, 0, up << 2), memset(eef, 0, up << 2);
  memset(a, 0, (n + 1) << 2), memset(b, 0, (n + 1) << 2), memset(c, 0, (n + 1) << 2);
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  cin >> n >> mod, z = fastmod(mod);
  if (n == 1) {
    cout << 0;
    return 0;
  }
  poly::init(), prep(n);

  calc(n);

  poly::exp(f, n, ef);
  for (int i = n; i; i--)
    a[i] = add(f[i], ef[i - 1]);
  poly::exp(a, n, h);
  for (int i = n; i; i--)
    h[i] = h[i - 1];
  h[0] = 0;
  for (int i = 1; i <= n; i++)
    a[i] = add(f[i], h[i]);
  for (int i = n; i; i--)
    xef[i] = ef[i - 1];
  xef[0] = 1;
  poly::mul(a, n, xef, n, a, n);
  a[0] = 1;
  for (int i = 1; i <= n; i++)
    a[i] = sub(0, a[i]);
  poly::mul(a, n, ef, n, a, n);
  h[0] = 1;
  for (int i = 1; i <= n; i++)
    h[i] = sub(0, h[i]);
  poly::div(h, a, n, b);
  for (int i = 1; i <= n; i++)
    cout << z.reduce(1ll * b[i] * fac[i]) << '\n';
}
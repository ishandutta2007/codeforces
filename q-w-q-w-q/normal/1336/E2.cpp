#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math,inline")
#pragma GCC target("sse4,sse4.1,sse4.2,ssse3,sse3,sse2,sse,avx2,avx,popcnt,abm,mmx,tune=native")
#include <cstdio>
#include <iostream>

using namespace std;

typedef long long i64;

char gc() {
  const int sz = 1 << 21;
  static char v[sz], *b, *e;
  return b == e ? (e = (b = v) + fread(v, 1, sz, stdin), b == e ? EOF : *b++) : *b++;
}
template <class _Tp>
void rd(_Tp &x) {
  char c = gc();
  x = 0;
  while (isspace(c))
    c = gc();
  while (isdigit(c))
    x = x * 10 + c - '0', c = gc();
}

const int mod = 998244353;
int n, m, k, mp[60];
i64 b[60], v1[1 << 13], v2[1 << 13], val[60];
int ans[60], sum[60], c[60][60];

bool insert(i64 x) {
  for (int i = m - 1; i != -1; i--)
    if (x >> i & 1) {
      if (!b[i]) {
        b[i] = x;
        return 1;
      }
      x ^= b[i];
    }
  return 0;
}

void gu() {
  for (int i = 0; i != m; i++)
    if (b[i])
      for (int j = i + 1; j != m; j++)
        if (b[j] >> i & 1)
          b[j] ^= b[i];
}

int pw2(int n) {
  int tp = 1, x = 2;
  while (n) {
    if (n & 1)
      tp = 1ll * tp * x % mod;
    x = 1ll * x * x % mod, n >>= 1;
  }
  return tp;
}

int main() {
  rd(n), rd(m);
  for (int i = 1; i <= n; i++) {
    i64 x;
    rd(x);
    k += insert(x);
  }
  gu();
  if (k * 2 <= m) {
    int m1 = k / 2, m2 = k - m1;
    int cnt = 0;
    for (int i = 0; i != m; i++)
      if (b[i])
        val[cnt++] = b[i];
    for (int s = 1; s != (1 << m1); s++) {
      int x = __lg(s);
      v1[s] = v1[s ^ (1 << x)] ^ val[x];
    }
    for (int s = 1; s != (1 << m2); s++) {
      int x = __lg(s);
      v2[s] = v2[s ^ (1 << x)] ^ val[m1 + x];
    }
    for (int s1 = 0; s1 != (1 << m1); s1++)
      for (int s2 = 0; s2 != (1 << m2); s2++)
        ans[__builtin_popcountll(v1[s1] ^ v2[s2])]++;
  } else {
    int cnt = 0;
    for (int i = 0; i != m; i++)
      if (!b[i]) {
        val[cnt] = 1ll << i;
        for (int j = i + 1; j != m; j++)
          if (b[j] >> i & 1)
            val[cnt] |= 1ll << j;
        cnt++;
      }
    int m1 = cnt / 2, m2 = cnt - m1;
    for (int s = 1; s != (1 << m1); s++) {
      int x = __lg(s);
      v1[s] = v1[s ^ (1 << x)] ^ val[x];
    }
    for (int s = 1; s != (1 << m2); s++) {
      int x = __lg(s);
      v2[s] = v2[s ^ (1 << x)] ^ val[m1 + x];
    }
    for (int s1 = 0; s1 != (1 << m1); s1++)
      for (int s2 = 0; s2 != (1 << m2); s2++)
        sum[__builtin_popcountll(v1[s1] ^ v2[s2])]++;
    for (int i = 0; i <= m; i++) {
      c[i][0] = c[i][i] = 1;
      for (int j = 1; j < i; j++) {
        c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
        if (c[i][j] >= mod)
          c[i][j] -= mod;
      }
    }
    for (int i = 0, x = pw2(mod - 1 + k - m); i <= m; i++) {
      int s = 0;
      for (int j = 0; j <= m; j++)
        for (int k = max(0, i + j - m); k <= i && k <= j; k++)
          if (k & 1)
            s = (s + 1ll * (mod - sum[j]) * c[j][k] % mod * c[m - j][i - k]) % mod;
          else
            s = (s + 1ll * sum[j] * c[j][k] % mod * c[m - j][i - k]) % mod;
      ans[i] = 1ll * s * x % mod;
    }
  }

  for (int i = 0, x = pw2(n - k); i <= m; i++)
    cout << 1ll * ans[i] * x % mod << " \n"[i == m];
}
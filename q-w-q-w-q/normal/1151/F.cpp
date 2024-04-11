#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int mod = 1e9 + 7;
int n, k, a[101], s, q;
int c[101][101];
int f[101], g[101][101], t1[101], t2[101][101];
inline int add(int x, int y) { return x + y < mod ? x + y : x + y - mod; }
inline int power(int a, int n) {
  int tp = 1;
  while (n) {
    if (n & 1)
      tp = 1ll * tp * a % mod;
    a = 1ll * a * a % mod, n >>= 1;
  }
  return tp;
}
int main() {
  cin >> n >> k;
  for (int i = 1; i <= n; i++)
    cin >> a[i], s += a[i];
  c[0][0] = 1;
  for (int i = 1; i <= n; i++) {
    c[i][0] = c[i][i] = 1;
    for (int j = 1; j < i; j++)
      c[i][j] = add(c[i - 1][j], c[i - 1][j - 1]);
  }
  for (int i = 0; i <= s; i++) {
    if (s + s - i > n)
      continue;
    g[i][i] =
        (c[n - s][2] + c[s][2] + i * (s - i) + (s - i) * (n - 2 * s + i)) % mod;
    if (i)
      g[i][i - 1] = i * (n - 2 * s + i);
    g[i][i + 1] = (s - i) * (s - i);
  }
  int tp = power(power(c[n][2], mod - 2), k);
  f[s] = 1;
  while (k) {
    if (k & 1) {
      memset(t1, 0, sizeof t1);
      for (int i = 0; i <= s; i++)
        for (int j = 0; j <= s; j++)
          t1[j] = (t1[j] + 1ll * f[i] * g[i][j]) % mod;
      memcpy(f, t1, sizeof t1);
    }
    memset(t2, 0, sizeof t2);
    for (int i = 0; i <= s; i++)
      for (int p = 0; p <= s; p++)
        if (g[i][p])
          for (int j = 0; j <= s; j++)
            t2[i][j] = (t2[i][j] + 1ll * g[i][p] * g[p][j]) % mod;
    memcpy(g, t2, sizeof t2);
    k >>= 1;
  }
  for (int i = n; i >= n - s + 1; i--)
    if (a[i])
      q++;
  cout << 1ll * f[q] * tp % mod * power(c[n - s][s - q], mod - 2) % mod * power(c[s][q], mod - 2) % mod;
}
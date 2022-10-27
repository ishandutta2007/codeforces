#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
int n, mod, ans;
int f[501][250001], s[250001], g[501];
int s1[250001], s2[250001];
int c[501][501], fac[501];
inline int add(int x, int y) { return x + y < mod ? x + y : x + y - mod; }
inline int sub(int x, int y) { return x < y ? x + mod - y : x - y; }
int main() {
  cin >> n >> mod;
  f[1][0] = 1;
  for (int i = 2; i <= n; i++) {
    s[0] = 1;
    for (int j = 1; j <= i * (i - 1) / 2; j++) s[j] = add(s[j - 1], f[i - 1][j]);
    for (int j = 0; j <= i * (i - 1) / 2; j++) {
      f[i][j] = s[j];
      if (j >= i) f[i][j] = sub(f[i][j], s[j - i]);
    }
  }
  c[0][0] = 1;
  for (int i = 1; i <= n; i++) {
    c[i][0] = c[i][i] = 1;
    for (int j = 1; j < i; j++) c[i][j] = add(c[i - 1][j], c[i - 1][j - 1]);
  }
  fac[0] = 1;
  for (int i = 1; i <= n; i++) fac[i] = 1ll * fac[i - 1] * i % mod;
  for (int l = 2; l <= n; l++) {
    int tot = l * (l - 1) / 2;
    memset(s, 0, sizeof s), memset(s1, 0, sizeof s1), memset(s2, 0, sizeof s2);
    s[0] = 1, s1[0] = 1;
    for (int j = 1; j <= tot; j++) {
      s[j] = add(s[j - 1], f[l - 1][j]);
      s1[j] = add(s1[j - 1], s[j]);
      s2[j] = (s2[j - 1] + 1ll * s[j] * j) % mod;
    }
    for (int k = 2; k < tot; k++) {
      int x = s1[k - 2];
      if (k > l + 1) x = sub(x, s1[k - l - 2]);
      g[l] = (g[l] + 1ll * (l - k + 1 + mod) * x % mod * f[l - 1][k]) % mod;
      x = s2[k - 2];
      if (k > l + 1) x = sub(x, s2[k - l - 2]);
      g[l] = (g[l] + 1ll * f[l - 1][k] * x) % mod;
    }
    ans = (ans + 1ll * c[n][l] % mod * fac[n - l] % mod * g[l]) % mod;
  }
  cout << ans;
}
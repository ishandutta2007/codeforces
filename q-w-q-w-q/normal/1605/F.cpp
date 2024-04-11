#include <cstdio>
#include <iostream>

using namespace std;

const int N = 85;
int n, k, mod;
int f[N][N], g[N][N], c[N][N], pw[N * N];
int _c[N][N], iv[N];

int add(int x, int y) { return x + y < mod ? x + y : x + y - mod; }
int sub(int x, int y) { return x < y ? x + mod - y : x - y; }

int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  cin >> n >> k >> mod;

  for (int i = 0; i <= max(n, k); i++) {
    c[i][0] = c[i][i] = 1;
    for (int j = 1; j < i; j++)
      c[i][j] = add(c[i - 1][j - 1], c[i - 1][j]);
  }

  pw[0] = 1;
  for (int i = 1; i <= n * k; i++)
    pw[i] = add(pw[i - 1], pw[i - 1]);

  iv[1] = 1;
  for (int i = 2; i <= n; i++) {
    int j = mod / i + 1;
    iv[i] = 1ll * j * iv[i * j - mod] % mod;
  }

  for (int i = 1; i <= k; i++) {
    int x = pw[i];
    _c[i][0] = 1;
    for (int j = 1; j <= n; j++)
      _c[i][j] = 1ll * _c[i][j - 1] * (x - j) % mod;
  }

  f[0][0] = 1;
  for (int i = 0; i <= k; i++)
    f[1][i] = 1;
  for (int i = 2; i <= n; i++) {
    f[i][0] = 1;
    for (int j = 1; j <= k; j++) {
      for (int l = 2; l < i - i % 2; l += 2)
        for (int t = 1; t < j; t++) {
          f[i][j] = (f[i][j] + 1ll * c[i][l] * c[j][t] % mod * f[l][t] % mod * pw[(i - l) * t] % mod * _c[j - t][i - l]) % mod;
          f[i][j] = (f[i][j] + 1ll * c[i][l + 1] * c[j][t] % mod * g[l + 1][t] % mod * pw[(i - l - 1) * t] % mod * _c[j - t][i - l - 1]) % mod;
        }
      for (int l = 0; l < i - (i % 2); l++)
        f[i][j] = (f[i][j] + 1ll * c[i][l] * _c[j][i - l]) % mod;
      f[i][j] = sub(pw[i * j], f[i][j]);

      for (int t = 0; t < j; t++)
        f[i][j] = sub(f[i][j], 1ll * f[i][t] * c[j][t] % mod);

      if (i & 1) {
        g[i][j] = f[i][j];
        for (int t = 1; t <= j; t++)
          g[i][j] = sub(g[i][j], 1ll * f[i - 1][j - t] * c[j][t] % mod * i % mod * pw[j - t] % mod);
      }
    }
  }

  int ans = 0;
  for (int i = 0; i <= k; i++)
    ans = (ans + 1ll * f[n][i] * c[k][i]) % mod;
  cout << ans;
}
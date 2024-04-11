#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

const int N = 205;
int n, d, mod, c[N][N];
int f1[N], f2[N], f0[N], g[N][N], f[N], h[N][N], sg[N][N];

int reduce(int x) {return x + ((x >> 31) & mod); }
int add(int x, int y) { return reduce(x - mod + y); }
int sub(int x, int y) { return reduce(x - y); }

int main() {
  cin >> n >> d >> mod;

  if (n == 2) {
    cout << 4 % mod;
    return 0;
  }

  if (d == 1) {
    cout << 0;
    return 0;
  }

  for (int i = 0; i <= n; i++) {
    c[i][0] = c[i][i] = 1;
    for (int j = 1; j < i; j++) c[i][j] = add(c[i - 1][j], c[i - 1][j - 1]);
  }

  f0[1] = f1[1] = f2[1] = g[1][0] = 1;
  for (int i = 2; i <= n; i++) {
    for (int j = 1; j <= d; j++)
      for (int k = 1; k < i; k++)
        g[i][j] = (g[i][j] + 1ll * g[i - k][j - 1] * f1[k] % mod * c[i - 2][k - 1]) % mod;
    for (int j = 1; j < d - 1; j++) f2[i] = add(f2[i], g[i][j]);
    f1[i] = add(f2[i], g[i][d - 1]);
    f0[i] = add(f1[i], g[i][d]);
  }

  sg[1][0] = 1;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= d; j++)
      sg[i][j] = add(sg[i][j - 1], g[i][j]);

  for (int i = 0; i < n; i++)
    for (int j = 1; i + j + 1 <= n - 2; j++)
      for (int k = 1; k <= d - 2; k++)
        h[i][j] = (h[i][j] + 1ll * g[j + 1][k] * sg[i + 1][d - 2 - k]) % mod;

  f[1] = 1;
  for (int i = 2; i <= n; i++)
    for (int j = 1; j < i; j++)
      f[i] = (f[i] + 1ll * f[i - j] * f2[j] % mod * c[i - 2][j - 1]) % mod;

  int ans = (2ll * sub(f0[n], g[n][1]) + f[n - 1]) % mod;
  for (int i = 2; i < n - 1; i++)
    for (int l = 0; i - l > 1; l++)
      for (int r = 1; i + r < n; r++)
        ans = (ans + 1ll * f[i - l - 1] * f[n - i - r] % mod * h[l][r] % mod * c[i - 2][l] % mod * c[n - i - 1][r]) % mod;
  cout << 2ll * n * (n - 1) * ans % mod;
}
#include <cstdio>
#include <iostream>

using namespace std;

const int N = 205;
int n, mod;
int f[N][N][N], fac[N], ifac[N];

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

int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  cin >> n >> mod;

  int ans = 2;

  fac[0] = 1;
  for (int i = 1; i <= n; i++)
    fac[i] = 1ll * fac[i - 1] * i % mod;
  ifac[0] = 1;
  for (int i = 1; i <= n; i++)
    ifac[i] = 1ll * ifac[i - 1] * power(i, mod - 2) % mod;

  for (int i = 1; i < n; i++)
    f[n + 1][i][0] = ifac[i];

  for (int i = n; i; i--) {
    for (int j = 1; j < n; j++)
      for (int k = 0; k + j <= i; k++) {
        int l = n - j;
        if (l <= i)
          ans = (ans + 1ll * f[i + 1][j][k] * ifac[l] % mod * fac[n]) % mod;
      }
    for (int j = n - i + 1; j < n; j++)
      for (int k = n - i; k + j <= i; k++)
        f[i][j][k + j] = add(f[i][j][k + j], f[i + 1][j][k]);

    for (int j = n - 1; j > n - i; j--)
      for (int l = 1; l + j < n; l++)
        for (int k = n + 1 - i; k <= i; k++)
          f[i][j + l][k] = (f[i][j + l][k] + 1ll * f[i][j][k] * ifac[l]) % mod;
  }
  cout << ans;
}
#include <cstdio>
#include <iostream>
using namespace std;
const int mod = 998244353, N = 5005;
int n, fac[N], f[N][N], c[N][N];
inline int add(int x, int y) { return x + y < mod ? x + y : x + y - mod; }
int main() {
  cin >> n;
  fac[0] = 1;
  for (int i = 1; i <= n; i++) fac[i] = 1ll * fac[i - 1] * i % mod;
  for (int i = 0; i <= n; i++) {
    c[i][0] = c[i][i] = 1;
    for (int j = 1; j < i; j++) c[i][j] = add(c[i - 1][j], c[i - 1][j - 1]);
  }
  for (int i = 1; i <= n; i++) {
    f[i][0] = 1;
    for (int j = 1; j < i; j++)
      f[i][j] = (f[i - 1][j] + f[i - 1][j - 1] + 1ll * f[i - 1][j] * j + 1ll * f[i - 1][j - 1] * (i - j - 1)) % mod;
  }
  for (int i = 1; i <= n; i++) {
    int ans = 0;
    for (int j = i; j <= n; j++)
      ans = (ans + 1ll * c[n][j] * f[j][i - 1] % mod * fac[n - j]) % mod;
    cout << ans << " \n"[i == n];
  }
}
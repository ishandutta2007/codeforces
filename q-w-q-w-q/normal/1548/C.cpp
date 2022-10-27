#include <cstdio>
#include <iostream>
using namespace std;
const int mod = 1e9 + 7, N = 3000050, i3 = (mod + 1) / 3;
int fac[N], ifac[N], f[N];
inline int power(int a, int n) {
  int tp = 1;
  while (n) {
    if (n & 1) tp = 1ll * tp * a % mod;
    a = 1ll * a * a % mod, n >>= 1;
  }
  return tp;
}
inline int c(int n, int m) { return 1ll * fac[n] * ifac[m] % mod * ifac[n - m] % mod; }
int main() {
  int n, m, q;
  cin >> n, m = n + 1;
  fac[0] = 1;
  for (int i = 1; i <= 3 * m; i++) fac[i] = 1ll * fac[i - 1] * i % mod;
  ifac[3 * m] = power(fac[3 * m], mod - 2);
  for (int i = 3 * m - 1; ~i; i--) ifac[i] = 1ll * ifac[i + 1] * (i + 1) % mod;
  f[0] = m, f[1] = 3ll * n * (n + 1) / 2 % mod;
  for (int i = 2; i <= 3 * n; i++) f[i] = (c(3 * m, i + 1) - (3ll * f[i - 1] + f[i - 2]) % mod + mod) * i3 % mod;
  cin >> q;
  while (q--) {
    int x;
    scanf("%d", &x);
    printf("%d\n", f[x]);
  }
}
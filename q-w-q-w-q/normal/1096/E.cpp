#include <cstdio>
#include <iostream>
using namespace std;
const int mod = 998244353, M = 5105;
int n, m, k, tot, ans;
int fac[M], ifac[M];
inline int add(int x, int y) { return x + y < mod ? x + y : x + y - mod; }
inline int sub(int x, int y) { return x < y ? x + mod - y : x - y; }
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
  cin >> n >> m >> k;
  if (n == 1) {
    cout << 1;
    return 0;
  }
  int t = n + m;
  fac[0] = 1;
  for (int i = 1; i <= t; i++) fac[i] = 1ll * fac[i - 1] * i % mod;
  ifac[t] = power(fac[t], mod - 2);
  for (int i = t - 1; ~i; i--) ifac[i] = 1ll * ifac[i + 1] * (i + 1) % mod;
  for (int i = k; i <= m; i++) tot = add(tot, c(m - i + n - 2, n - 2));
  for (int i = 1; i <= n && i * k <= m; i++)
    if (i & 1)
      ans = (ans + 1ll * c(n, i) * c(m - i * k + n - 1, n - 1)) % mod;
    else
      ans = sub(ans, 1ll * c(n, i) * c(m - i * k + n - 1, n - 1) % mod);
  cout << 1ll * ans * power(1ll * n * tot % mod, mod - 2) % mod;
}
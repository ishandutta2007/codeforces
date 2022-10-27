#include <cstdio>
#include <iostream>
using namespace std;
const int mod = 998244353;
int n, m, s1, s2;
int fac[2000005], ifac[2000005], iv[4000005];
inline int add(int x, int y) { return x + y < mod ? x + y : x + y - mod; }
inline int sub(int x, int y) { return x < y ? x + mod - y : x - y; }
inline int power(int a, int n) {
  int tp = 1;
  while (n) {
    if (n & 1)
      tp = 1ll * tp * a % mod;
    a = 1ll * a * a % mod, n >>= 1;
  }
  return tp;
}
inline int c(int n, int m) {
  return 1ll * fac[n] * ifac[m] % mod * ifac[n - m] % mod;
}
int main() {
  cin >> n >> m;
  fac[0] = 1;
  for (int i = 1; i <= n; i++)
    fac[i] = 1ll * fac[i - 1] * i % mod;
  ifac[n] = power(fac[n], mod - 2);
  for (int i = n - 1; ~i; i--)
    ifac[i] = 1ll * ifac[i + 1] * (i + 1) % mod;
  iv[1] = 1;
  for (int i = 2, j; i <= n + m; i++) {
    j = mod / i + 1;
    iv[i] = 1ll * j * iv[i * j - mod] % mod;
  }
  for (int i = 0, x = 1ll * iv[n + m] * m % mod; i <= n;
       i++, x = 1ll * x * iv[n + m - i] % mod * (n - i + 1) % mod)
    s1 = (s1 + 1ll * x * (i + 1)) % mod;
  for (int i = 1; i <= n; i++)
    if (i & 1)
      s2 = (s2 + 1ll * c(n, i) * (m + i) % mod * iv[i]) % mod;
    else
      s2 = (s2 - 1ll * c(n, i) * (m + i) % mod * iv[i] % mod + mod) % mod;
  cout << 1ll * s1 * s2 % mod;
}
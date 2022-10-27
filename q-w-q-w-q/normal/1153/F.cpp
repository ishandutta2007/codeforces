#include <cstdio>
#include <iostream>
using namespace std;
const int mod = 998244353, N = 4005;
int n, k, l, ans;
int c[N][N], ffac[N], fac[N], iv[N];
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
int main() {
  cin >> n >> k >> l;
  ffac[0] = fac[0] = fac[1] = iv[1] = 1;
  for (int i = 2; i <= 2 * n + 1; i++) {
    fac[i] = 1ll * fac[i - 1] * i % mod;
    ffac[i] = 1ll * ffac[i - 2] * (i - 1) % mod;
    int j = mod / i + 1;
    iv[i] = 1ll * iv[i * j - mod] * j % mod;
  }
  for (int i = 0; i <= 2 * n; i++) {
    c[i][0] = 1;
    for (int j = 1; j <= i; j++) c[i][j] = add(c[i - 1][j], c[i - 1][j - 1]);
  }
  for (int i = 1; i < 2 * n; i++) {
    int x = 0, y = 0;
    for (int j = 0; j <= 2 * n - i; j++)
      if (j & 1)
        x = sub(x, 1ll * c[2 * n - i][j] * iv[i + j + 1] % mod);
      else
        x = (x + 1ll * c[2 * n - i][j] * iv[i + j + 1]) % mod;
    x = 1ll * x * fac[2 * n] % mod * power(1ll * fac[i] * fac[2 * n - i] % mod, mod - 2) % mod;
    for (int j = k; j <= min(i, 2 * n - i); j++)
      y = (y + 1ll * c[i][j] * c[2 * n - i][j] % mod * fac[j] % mod * ffac[i - j] % mod * ffac[2 * n - i - j]) % mod;
    ans = (ans + 1ll * x * y) % mod;
  }
  cout << 1ll * l * ans % mod * power(ffac[2 * n], mod - 2) % mod;
}
#include <cstdio>
#include <iostream>
using namespace std;
const int mod = 998244353, N = 100005;
int t, n, a[N], fac[N], ifac[N];
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
  cin >> t;
  while (t--) {
    scanf("%d", &n);
    fac[0] = 1;
    for (int i = 1; i <= n; i++) fac[i] = 1ll * fac[i - 1] * i % mod, scanf("%1d", a + i);
    ifac[n] = power(fac[n], mod - 2);
    for (int i = n - 1; ~i; i--) ifac[i] = 1ll * ifac[i + 1] * (i + 1) % mod;
    int cnt = a[n], tp = 0;
    for (int i = n - 1; i; i--) {
      if (a[i])
        cnt++;
      else if (cnt & 1)
        cnt--, tp++;
    }
    if (cnt & 1) cnt--, n--;
    printf("%d\n", c(n - cnt + 1 - tp + cnt / 2 - 1, cnt / 2));
  }
}
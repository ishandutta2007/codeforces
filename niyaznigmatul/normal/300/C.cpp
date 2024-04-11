#include <cstdio>
#include <algorithm>

const int md = 1000000007;
bool good(int n, int a, int b) {
  if (n == 0) return false;
  while (n > 0) {
    int v = n % 10;
    if (v != a && v != b) return false;
    n /= 10;
  }
  return true;
}

int fact[1234567], rfact[1234567];

int modPow(long long a, int b, int mod) {
  long long ret = 1;
  while (b > 0) {
    if (b & 1) {
      ret = ret * a % mod;
    }
    a = a * a % mod;
    b >>= 1;
  }
  return ret;
}
  
int c(int n, int k) {
  return (long long) fact[n] * rfact[k] % md * rfact[n - k] % md;
}

int main() {
  rfact[0] = fact[0] = 1;
  int a, b, n;
  scanf("%d%d%d", &a, &b, &n);
  for (int i = 1; i <= n; i++) {
    fact[i] = (long long) fact[i - 1] * i % md;
    rfact[i] = modPow(fact[i], md - 2, md);
  }
  int ans = 0;
  for (int i = 0; i <= n; i++) {
    int sum = i * a + (n - i) * b;
    if (good(sum, a, b)) {
      ans += c(n, i);
      if (ans >= md) ans -= md;
    }
  }
  printf("%d\n", ans);
}
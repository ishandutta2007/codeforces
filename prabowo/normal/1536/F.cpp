#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;
const int N = 1000005;

int n;
int fact[N], ifact[N];

int power(int x, int y) {
  int ret = 1;
  for (; y; y >>= 1) {
    if (y & 1) ret = 1LL * ret * x % MOD;
    x = 1LL * x * x % MOD;
  }
  return ret;
}

int C(int n, int k) {
  if (k < 0 || k > n) return 0;
  return 1LL * fact[n] * ifact[k] % MOD * ifact[n - k] % MOD;
}

int main() {
  int n;
  scanf("%d", &n);

  fact[0] = 1;
  for (int i = 1; i <= n; ++i) fact[i] = 1LL * fact[i - 1] * i % MOD;
  ifact[n] = power(fact[n], MOD - 2);
  for (int i = n - 1; i >= 0; --i) ifact[i] = 1LL * ifact[i + 1] * (i + 1) % MOD;

  int ans = 0;
  for (int i = 2; i <= n; i += 2) {
    ans = (ans + 2LL * (C(i, n - i) + C(i - 1, n - i - 1)) * fact[i]) % MOD;
  }
  printf("%d\n", ans);
	return 0;
}
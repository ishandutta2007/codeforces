#include <bits/stdc++.h>
using namespace std;

const int N = 500005;
const int MOD = 998244353;

int n, k;

int fact[N];
int ifact[N];

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
  return 1LL * fact[n] * ifact[k] % MOD * ifact[n-k] % MOD;
}

int solve() {
  scanf("%d %d", &n, &k);
  fact[0] = 1; for (int i = 1; i <= n; ++i) fact[i] = 1LL * fact[i-1] * i % MOD;
  ifact[n] = power(fact[n], MOD-2); for (int i = n-1; i >= 0; --i) ifact[i] = 1LL * ifact[i+1] * (i+1) % MOD;
  assert(ifact[0] == 1);

  long long ans = 0;
  for (int i = 1; i <= n; ++i) {
    ans += C(n/i - 1, k-1);
  }

  printf("%lld\n", ans % MOD);
  return 0;
}

int main() {
  int t = 1;
  // scanf("%d", &t);
  for (int tc = 0; tc < t; ++tc) {
    // printf("Case #%d: ", tc+1);
    solve();
  }
  return 0;
}
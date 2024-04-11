#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;
const int N = 3000005;

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

// ans = [x^k] ((1 + x)^3 + (1 + x)^6 + ... + (1 + x)^(3n))
//     = [x^k] ((1 + x)^(3n + 3) - (1 + x)^3) / ((1 + x)^3 - 1)

int main() {
  int q;
  scanf("%d %d", &n, &q);

  fact[0] = 1;
  for (int i = 1; i < N; ++i) fact[i] = 1LL * fact[i - 1] * i % MOD;
  ifact[N - 1] = power(fact[N - 1], MOD - 2);
  for (int i = N - 2; i >= 0; --i) ifact[i] = 1LL * ifact[i + 1] * (i + 1) % MOD;

  vector<int> P(n*3 + 4);
  for (int i = 0; i <= n*3 + 3; ++i) {
    P[i] = C(n*3 + 3, i);
  }
  P[0] = (P[0] + MOD-1) % MOD;
  P[1] = (P[1] + MOD-3) % MOD;
  P[2] = (P[2] + MOD-3) % MOD;
  P[3] = (P[3] + MOD-1) % MOD;

  vector<int> Q(n*3 + 1);
  // Q = P / (x^3 + 3x^2 + 3x)
  for (int i = n*3; i >= 0; --i) {
    Q[i] = P[i + 3];
    P[i + 2] = (P[i + 2] - 3LL * Q[i] % MOD + MOD) % MOD;
    P[i + 1] = (P[i + 1] - 3LL * Q[i] % MOD + MOD) % MOD;
  }
  assert(P[0] == 0 && P[1] == 0 && P[2] == 0);

  while (q--) {
    int k;
    scanf("%d", &k);
    printf("%d\n", Q[k]);
  }
	return 0;
}
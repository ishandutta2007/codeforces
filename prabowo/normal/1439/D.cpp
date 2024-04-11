#include <bits/stdc++.h>
using namespace std;

const int N = 505;

int n, m, p;

int power(int x, int y) {
  int ret = 1;
  for (; y; y >>= 1) {
    if (y & 1) ret = 1LL * ret * x % p;
    x = 1LL * x * x % p;
  }
  return ret;
}

int fact[N], ifact[N];
int C(int n, int k) {
  return 1LL * fact[n] * ifact[k] % p * ifact[n-k] % p;
}

int dp0[N], dp1[N];
int dp2[N][N], dp3[N][N];

int main() {
  scanf("%d %d %d", &n, &m, &p);

  fact[0] = 1; for (int i = 1; i <= n; ++i) fact[i] = 1LL * fact[i-1] * i % p;
  ifact[n] = power(fact[n], p-2); for (int i = n-1; i >= 0; --i) ifact[i] = 1LL * ifact[i+1] * (i+1) % p;

  // Count number of ways, n = m
  dp0[0] = 1;
  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j < i; ++j) {
      dp0[i] = (1LL * dp0[j] * dp0[i-j-1] % p * C(i-1, j) % p * (i+1) + dp0[i]) % p;
    }
  }

  // Sum of madness, n = m
  dp1[0] = 0;
  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j < i; ++j) {
      dp1[i] = ((1LL * dp1[j] * dp0[i-j-1] + 1LL * dp1[i-j-1] * dp0[j]) % p * C(i-1, j) % p * (i+1) + dp1[i]) % p;
      dp1[i] = ((1LL * dp0[j] * dp0[i-j-1] % p * C(i-1, j) % p * (j*(j+1)/2 + (i-j)*(i-j-1)/2)) + dp1[i]) % p;
    }
  }

  // Count number of ways
  dp2[0][0] = 1;
  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j <= i; ++j) {
      dp2[i][j] = dp0[j];
      for (int k = 0; k < j; ++k) {
        dp2[i][j] = (1LL * dp0[k] * dp2[i-k-1][j-k] % p * C(j, k) + dp2[i][j]) % p;
      }
    }
  }

  // Sum of madness
  dp3[0][0] = 0;
  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j <= i; ++j) {
      dp3[i][j] = dp1[j];
      for (int k = 0; k < j; ++k) {
        dp3[i][j] = ((1LL * dp2[i-k-1][j-k] * dp1[k] + 1LL * dp3[i-k-1][j-k] * dp0[k]) % p * C(j, k) + dp3[i][j]) % p;
      }
    }
  }

  printf("%d\n", dp3[n][m]);
  return 0;
}
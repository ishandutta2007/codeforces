#include <bits/stdc++.h>
using namespace std;

const int N = 200005;
const int K = 10;
const int MOD = 998244353;

int n, k;
int p[K];

int inv[N * K / 2];
int q[N * K / 2];

// Q = P^n(x)
// log Q = n log P(x)
// n Q P' = Q' P

int main() {
  scanf("%d %d", &n, &k);
  int shift = 10;
  for (int i = 0; i < k; ++i) {
    int d;
    scanf("%d", &d);
    p[d] = 1;
    shift = min(shift, d);
  }

  for (int i = 0; i < 10 - shift; ++i) p[i] = p[i + shift];
  for (int i = 10 - shift; i < 10; ++i) p[i] = 0;

  int sum = n/2 * (9 - shift);

  inv[1] = 1;
  for (int i = 2; i <= sum; ++i) {
    inv[i] = MOD - 1LL * (MOD / i) * inv[MOD % i] % MOD;
  }

  int ans = 1;
  q[0] = 1;
  for (int i = 1; i <= sum; ++i) {
    long long add = 0;
    for (int j = 1; j < 10; ++j) {
      if (i < j) break;
      add += 1LL * (n/2 * j - (i-j)) * q[i-j] * p[j];
    }
    add = add % MOD * inv[i] % MOD;
    q[i] = (add < 0 ? add + MOD : add);

    ans = (1LL * q[i] * q[i] + ans) % MOD;
  }

  printf("%d\n", ans);
  return 0;
}
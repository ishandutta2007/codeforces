#include <bits/stdc++.h>
using namespace std;

const int N = 1000005;

const int MOD = 998244353;

int n;
int k[N];
int presents[N];

int cnt[N];

int power(int x, int y) {
  int ret = 1;
  for (; y; y >>= 1) {
    if (y & 1) ret = 1LL * ret * x % MOD;
    x = 1LL * x * x % MOD;
  }

  return ret;
}

int main() {
  scanf("%d", &n);

  int idx = 0;
  for (int i = 0; i < n; ++i) {
    scanf("%d", &k[i]);
    for (int j = 0; j < k[i]; ++j) {
      scanf("%d", &presents[idx]);
      ++cnt[presents[idx]];
      ++idx;
    }
  }

  int ans = 0;
  idx = 0;
  int invn = power(n ,MOD-2) % MOD;
  for (int i = 0; i < n; ++i) {
    int inv = power(k[i], MOD-2);
    for (int j = 0; j < k[i]; ++j) {
      ans = (1LL * inv * cnt[presents[idx]] % MOD * invn + ans) % MOD;
      ++idx;
    }
  }

  ans = 1LL * ans * invn % MOD;
  printf("%d\n", ans);
  return 0;
}
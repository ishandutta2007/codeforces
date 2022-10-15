#include <cstdio>
#include <algorithm>

int const N = 222222;

int const MOD = 1000000007;

inline void add(int & a, int b) {
  a += b;
  if (a >= MOD) a -= MOD;
}

int main() {
  int dp[N];
  int r, g;
  scanf("%d%d", &r, &g);
  for (int i = 0; i <= r; i++) dp[i] = 0;
  dp[0] = 1;
  int ans = 0;
  int all = 0;
  for (int level = 0; ; level++) {
    int s = 0;
    int put = level + 1;
    for (int j = std::min(r, all); j >= 0; j--) {
      int val = dp[j];
      add(s, val);
      dp[j] = 0;
      if (j + put <= r) add(dp[j + put], val);
      if ((all - j) + put <= g) add(dp[j], val);
    }
    if (s > 0) ans = s; else break;
    all += put;
  }
  printf("%d\n", ans);
}
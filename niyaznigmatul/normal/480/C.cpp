#include <cstdio>

int const N = 12345;

int dp[N], dp2[N];
int const MOD = 1000000007;

void add(int & a, int b) {
  a += b;
  if (a >= MOD) a -= MOD;
}

int main() {
  int n, a, b, k;
  scanf("%d%d%d%d", &n, &a, &b, &k);
  --a;
  --b;
  if (a > b) {
    a = n - 1 - a;
    b = n - 1 - b;
  }
  dp[a] = 1;
  for (int it = 0; it < k; it++) {
    for (int i = 0; i < b; i++) {
      int val = dp[i];
      if (val == 0) continue;
      int j = 2 * i - (b - 1);
      if (j < 0) j = 0;
      add(dp2[j], val);
    }
    for (int i = 1; i < b; i++) {
      add(dp2[i], dp2[i - 1]);
    }
    for (int i = 0; i < b; i++) {
      add(dp2[i], MOD - dp[i]);
      dp[i] = dp2[i];
      dp2[i] = 0;
    }
  }
  int ans = 0;
  for (int i = 0; i < b; i++) add(ans, dp[i]);
  printf("%d\n", ans);
}
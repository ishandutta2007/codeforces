#include <cstdio>

const int mod = 1000000007;
int dp[555][555], dp2[555][555];

void add(int & a, int b) {
  a += b;
  if (a >= mod) a -= mod;
}

int main() {
  int n, m, x;
  scanf("%d%d%d", &n, &m, &x);
  if (n > m) {
    puts("0");
    return 0;
  }
  dp[0][0] = 1;
  for (int it = 1; it <= m; it++) {
    for (int i = 0; i <= n; i++) {
      for (int j = 0; j <= n; j++) {
        int val = dp[i][j];
        if (val == 0) continue;
        if (it != x) {
          add(dp2[i][j], val);
        }
        if (i + 1 <= n) {
          add(dp2[i + 1][j + 1], val);
          add(dp2[i + 1][j], val);
        }
        if (it != x && j > 0) {
          add(dp2[i][j - 1], val);
        }
      }
    }
    for (int i = 0; i <= n; i++) {
      for (int j = 0; j <= n; j++) {
        dp[i][j] = dp2[i][j];
        dp2[i][j] = 0;
      }
    }
  }
  long long ans = dp[n][0];
  for (int i = 2; i <= n; i++) {
    ans = ans * i % mod;
  }
  printf("%d\n", (int) (ans % mod));
}
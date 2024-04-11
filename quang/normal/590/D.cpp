#include <bits/stdc++.h>

using namespace std;

const int N = 155;

int n, k, s;
int dp[2][N][N * N], q[N];

int main() {
  scanf("%d %d %d", &n, &k, &s);
  for (int i = 1; i <= n; i++) {
    scanf("%d", q + i);
  }
  s = min(s, n * (n - 1) / 2);
  for (int i = 0; i <= k; i++) {
    for (int j = 0; j <= s; j++) {
      dp[0][i][j] = 1e9;
    }
  }
  dp[0][0][0] = 0;
  int now = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = i; j >= 0; j--) {
      for (int sum = s; sum >= 0; sum--) {
        dp[now ^ 1][j][sum] = 1e9;
        if (i - 1 >= j) {
          dp[now ^ 1][j][sum] = dp[now][j][sum];
        }
        if (sum >= i - j && j) {
          dp[now ^ 1][j][sum] = min(dp[now ^ 1][j][sum], dp[now][j - 1][sum - i + j] + q[i]);
        }
      }
    }
    now ^= 1;
  }
  cout << *min_element(dp[now][k], dp[now][k] + s + 1);
  return 0;
}
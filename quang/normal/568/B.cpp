#include <bits/stdc++.h>

using namespace std;

const int N = 4010, MOD = 1000000007;

int n;
long long dp[N];
long long c[N][N];

int main() {
  ios_base::sync_with_stdio(0);
  cin >> n;
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= i; j++) {
      if (j == 0 || j == i) {
        c[i][j] = 1;
      } else {
        c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % MOD;
      }
    }
  }
  dp[0] = 1;
  for (int i = 1; i <= n; i++) {
    dp[i] = 0;
    for (int j = 0; j < i; j++) {
      int x = c[i - 1][j];
      dp[i] = (dp[i] + dp[i - 1 - j] * x) % MOD;
    }
  }
  long long res = 0;
  for (int i = 0; i < n; i++) {
    res = (res + dp[i] * c[n][i]) % MOD;
  }
  cout << res << endl;
  return 0;
}
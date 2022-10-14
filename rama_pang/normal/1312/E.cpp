#include <bits/stdc++.h>
using namespace std;

int n;
int a[505];
int dp[505][505];
int comb[505][505];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    dp[i][i] = 1;
    comb[i][i] = a[i];
  }

  for (int i = n - 1; i >= 0; i--) {
    for (int j = i + 1; j < n; j++) {
      dp[i][j] = 1e9;
      for (int k = i; k < j; k++) {
        dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j]);
        if (dp[i][k] == 1 && dp[k + 1][j] == 1 && comb[i][k] == comb[k + 1][j]) {
          dp[i][j] = 1;
          comb[i][j] = comb[i][k] + 1;
          break;
        }
      }
    }
  }

  cout << dp[0][n - 1] << "\n";
  return 0;
}
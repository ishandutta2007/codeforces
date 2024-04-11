#include <bits/stdc++.h>
using namespace std;

void Main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  vector<vector<int>> dp(n, vector<int>(n, 1e9));
  dp[0].assign(n, 0);
  for (int i = 1; i < n; i++) {
    int cnt = 0;
    for (int j = i - 1; j >= 0; j--) {
      if (j + a[j] >= i) {
        dp[i][j + a[j]] = min(dp[i][j + a[j]], dp[j][i - 1] + cnt);
        cnt += 1;
      }
    }
    for (int j = i + 1; j < n; j++) {
      dp[i][j] = min(dp[i][j], dp[i][j - 1]);
    }
  }

  cout << dp[n - 1][n - 1] << '\n';
  return;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int T = 1;
  cin >> T;
  while (T--) {
    Main();
  }
  return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int T;
  cin >> T;
  while (T--) {
    int n, k;
    cin >> n >> k;
    string t;
    cin >> t;
    vector<int> pref(n);
    for (int i = 0; i < n; i++) {
      if (t[i] == '1') pref[i]++;
      if (i > 0) pref[i] += pref[i - 1];
    }
    vector<vector<int>> dp(n + 2, vector<int>(3, n + 1));
    dp[0][0] = dp[0][1] = dp[0][2] = 0;
    for (int i = 0; i <= n; i++) {
      dp[i][1] = min(dp[i][1], dp[i][0]);
      dp[i][2] = min(dp[i][2], dp[i][1]);
      dp[min(i + k, n)][1] = min(dp[min(i + k, n)][1], dp[i][1] + (t[i] == '0') + (pref[min(i + k, n) - 1] - pref[i]));
      dp[i + 1][0] = min(dp[i + 1][0], dp[i][0] + (t[i] == '1'));
      dp[i + 1][2] = min(dp[i + 1][2], dp[i][2] + (t[i] == '1'));
    }
    
    cout << dp[n][2] << "\n";
  }
}
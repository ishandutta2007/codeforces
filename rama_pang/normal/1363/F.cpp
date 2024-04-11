#include <bits/stdc++.h>
using namespace std;

void Solve() {
  int n;
  cin >> n;
  string s, t;
  cin >> s >> t;

  vector<vector<int>> cnts(n + 5, vector<int>(26, 0));
  vector<vector<int>> cntt(n + 5, vector<int>(26, 0));

  for (int i = n; i >= 1; i--) {
    cnts[i] = cnts[i + 1];
    cntt[i] = cntt[i + 1];
    cnts[i][s[i - 1] - 'a']++;
    cntt[i][t[i - 1] - 'a']++;
  }

  if (cnts[1] != cntt[1]) {
    cout << -1 << "\n";
    return;
  }

  vector<vector<int>> dp(n + 5, vector<int>(n + 5, 1e9));

  for (int i = 0; i <= n; i++) {
    for (int j = i; j <= n; j++) {
      if (i == 0) {
        dp[i][j] = 0;
        continue;
      }
      dp[i][j] = dp[i - 1][j] + 1;
      if (s[i - 1] == t[j - 1]) {
        dp[i][j] = min(dp[i][j], dp[i - 1][j - 1]);
      }
      if (cnts[i + 1][t[j - 1] - 'a'] > cntt[j + 1][t[j - 1] - 'a']) {
        dp[i][j] = min(dp[i][j], dp[i][j - 1]);
      }
    }
  }

  cout << dp[n][n] << "\n";
  return;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int T;
  cin >> T;
  while (T--) {
    Solve();
  }
}
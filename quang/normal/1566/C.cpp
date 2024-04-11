#include <bits/stdc++.h>

using namespace std;

void Solve(int test) {
  int n;
  cin >> n;
  string s[2];
  cin >> s[0] >> s[1];
  vector<int> dp(n + 1);
  int last[2] = { -1, -1};
  for (int i = 0; i < n; i++) {
    if (s[0][i] == '0' || s[1][i] == '0') last[0] = i;
    if (s[0][i] == '1' || s[1][i] == '1') last[1] = i;
    dp[i + 1] = dp[i];
    if (last[0] == last[1]) {
      assert(last[0] == i);
      dp[i + 1] = max(dp[i + 1], dp[i] + 2);
    } else if (last[0] < last[1]) {
      dp[i + 1] = max(dp[i + 1], dp[i]);
      if (last[0] >= 0) dp[i + 1] = max(dp[i + 1], dp[last[0]] + 2);
    } else {
      dp[i + 1] = max(dp[i + 1], dp[i] + 1);
      if (last[1] >= 0) dp[i + 1] = max(dp[i + 1], dp[last[1]] + 2);
    }
  }
  cout << dp[n] << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int tc;
  cin >> tc;
  for (int test = 1; test <= tc; ++test) Solve(test);
  return 0;
}
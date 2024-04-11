#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int len;
  cin >> len;

  string s;
  cin >> s;

  vector<vector<int>> lcp(len + 1, vector<int>(len + 1));
  for (int i = len - 1; i >= 0; --i)
    for (int j = len - 1; j >= 0; --j)
      lcp[i][j] = (s[i] == s[j]) * (1 + lcp[i + 1][j + 1]);

  vector<int> dp(len);
  int ret = 0;
  for (int i = len - 1; i >= 0; --i) {
    dp[i] = len - i;
    for (int j = i + 1; j < len; ++j) {
      int x = lcp[i][j];
      if (x == len - j or s[i + x] > s[j + x])
        continue;
      dp[i] = max(dp[i], len - i + dp[j] - lcp[i][j]);
    }
    ret = max(ret, dp[i]);
  }
  cout << ret << '\n';
}

signed main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int nbTests;
  cin >> nbTests;
  for (int iTest(0); iTest < nbTests; ++iTest)
    solve();
}
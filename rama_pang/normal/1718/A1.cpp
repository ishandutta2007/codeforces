#include <bits/stdc++.h>
using namespace std;

using lint = long long;

const lint MOD = 1e9 + 7;
const lint INF = 1e18;

void Main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int MAX = 1;
  while (MAX <= 5000) MAX *= 2;
  vector<vector<int>> dp(n + 1, vector<int>(MAX, 1e9));
  dp[0][0] = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < MAX; j++) {
      int cur_val = j ^ a[i];
      dp[i + 1][0] = min(dp[i + 1][0], dp[i][j] + (cur_val != 0));
      dp[i + 1][cur_val] = min(dp[i + 1][cur_val], dp[i][j] + 1);
    }
  }
  int ans = 1e9;
  for(int j = 0; j < MAX; j++) ans = min(ans, dp[n][j]);
  cout << ans << '\n';
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
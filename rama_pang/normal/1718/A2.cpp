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
  map<int, int> dp;
  dp[0] = 0;
  int lazyAdd = 0;
  int lazyXor = 0;
  int min_value = 0;
  for (int i = 0; i < n; i++) {
    if (dp.count(lazyXor) == 0) {
      dp[lazyXor] = 1e9;
    }
    if (dp.count(lazyXor ^ a[i]) == 0) {
      dp[lazyXor ^ a[i]] = 1e9;
    }    
    int ret = dp[lazyXor ^ a[i]] + lazyAdd;
    int ret1 = min_value + 1;
    lazyXor ^= a[i];
    lazyAdd += 1;
    min_value += 1;
    dp[lazyXor] = min(dp[lazyXor], ret - lazyAdd);
    dp[lazyXor] = min(dp[lazyXor], ret1 - lazyAdd);
    min_value = min({min_value, dp[lazyXor] + lazyAdd});
    // for (int j = 0; j < MAX; j++) {
    //   int cur_val = j ^ a[i];
    //   dp[i + 1][0] = min(dp[i + 1][0], dp[i][j] + (cur_val != 0));
    //   dp[i + 1][cur_val] = min(dp[i + 1][cur_val], dp[i][j] + 1);
    // }
  }
  cout << min_value << '\n';
  // int ans = 1e9;
  // for (auto [j, v] : dp) ans = min(ans, v + lazyAdd);
  // // for(int j = 0; j < MAX; j++) ans = min(ans, dp[n][j]);
  // cout << ans << '\n';
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
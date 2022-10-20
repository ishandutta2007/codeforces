#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif

void Solve(int test) {
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &u : a) {
    cin >> u;
  }
  vector<int> dp(n + 1);
  map<int, int> latest;
  int cur = 0;
  latest[0] = 0;
  int res = 0;
  for (int i = 0; i < n; i++) {
    cur ^= a[i];
    dp[i + 1] = dp[i] + 1;
    if (latest.count(cur)) {
      auto last = latest[cur];
      dp[i + 1] = min(dp[last] + i - last, dp[i + 1]);
    }
    latest[cur] = i + 1;
    debug(i, dp[i + 1]);
  }
  cout << dp.back() << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int tc;
  cin >> tc;
  for (int test = 1; test <= tc; ++test) Solve(test);
  return 0;
}
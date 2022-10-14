#include <bits/stdc++.h>
using namespace std;
using lint = long long;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int T = 1;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<int> a(n);
    const int MAX = 2e5 + 5;
    vector<int> cnt(MAX);
    vector<int> dp(MAX);
    for (auto &i : a) cin >> i, cnt[i]++;
    for (int i = MAX - 1; i > 0; i--) {
      for (int j = i + i; j < MAX; j += i) {
        dp[i] = max(dp[i], dp[j]);
      }
      dp[i] += cnt[i];
    }
    int ans = 1e9;
    for (int i = 0; i < MAX; i++) {
      ans = min(ans, n - dp[i]);
    }
    cout << ans << '\n';
  }
  return 0;
}
#include <bits/stdc++.h>
using namespace std;
using lint = long long;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int T = 1;
  cin >> T;
  while (T--) {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto &i : a) cin >> i;
    const int MOD = 1e9 + 7;
    vector<pair<int, int>> dp(k + 1), ndp;
    dp[0] = {0, 1};
    const auto Update = [&](pair<int, int> &x, pair<int, int> y) {
      if (x.first < y.first) {
        x.first = y.first;
        x.second = 0;
      }
      if (x.first == y.first) {
        x.second += y.second;
        x.second %= MOD;
      }
    };
    for (int i = 0; i < n; i++) {
      for (int j = k - 1; j >= 0; j--) {
        Update(dp[j + 1], {dp[j].first + a[i], dp[j].second});
      }
    }
    cout << dp[k].second << '\n';
  }
  return 0;
}
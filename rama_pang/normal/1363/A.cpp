#include <bits/stdc++.h>
using namespace std;
using lint = long long;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int T;
  cin >> T;
  while (T--) {
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    int even = 0, odd = 0;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      a[i] %= 2;
      if (a[i] == 0) even++;
      else odd++;
    }
    vector<vector<pair<int, int>>> dp(n + 1, vector<pair<int, int>>(x + 5));
    dp[0][0].first = 0;
    dp[0][0].second = 1;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j <= x; j++) {
        dp[i + 1][j].first |= dp[i][j].first;
        dp[i + 1][j].second |= dp[i][j].second;
        
        if (a[i] == 0) {
          dp[i + 1][j + 1].first |= dp[i][j].first;
          dp[i + 1][j + 1].second |= dp[i][j].second;
        } else {
          dp[i + 1][j + 1].first |= dp[i][j].second;
          dp[i + 1][j + 1].second |= dp[i][j].first;
        }
      }
    }
    if (dp[n][x].first) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
}
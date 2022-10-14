#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int n;
  cin >> n;
  vector<int> a(n);
  vector<int> ones;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (a[i] == 1) {
      ones.emplace_back(i);
    }
  }

  const auto chmax = [&](int &a, int b) {
    a = max(a, b);
  };

  int dp[n + 1][n + 1][n * (n - 1) / 2 + 1] = {};
  for (int pos = 0; pos < n; pos++) {
    for (int one = 0; one < min(pos + 1, (int) ones.size()); one++) {
      int add = abs(pos - ones[one]);
      for (int moves = 0; moves + add <= n * (n - 1) / 2; moves++) {
        for (int zero = 0; pos + zero + 1 <= n; zero++) {
          chmax(dp[pos + zero + 1][one + 1][moves + add], dp[pos][one][moves] + zero * (pos - one));
        }
      }
    }
  }

  for (int i = 0; i <= n * (n - 1) / 2; i++) {
    cout << dp[n][ones.size()][i] << " ";
  }
  cout << "\n";
  return 0;
}
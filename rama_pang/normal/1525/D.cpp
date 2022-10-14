#include <bits/stdc++.h>
using namespace std;

using lint = long long;
const lint INF = 1e18;

void Main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<int> posA, posB;
  for (int i = 0; i < n; i++) {
    if (a[i] == 0) {
      posB.emplace_back(i);
    } else {
      posA.emplace_back(i);
    }
  }

  vector<vector<int>> dp(posA.size() + 1, vector<int>(posB.size() + 1));
  int szA = posA.size();
  int szB = posB.size();
  
  for (int i = szA; i >= 0; i--) {
    for (int j = szB; j >= 0; j--) {
      if (i == szA) {
        dp[i][j] = 0;
        continue;
      }
      dp[i][j] = 1e9;
      if (j < szB) {
        dp[i][j] = min(dp[i][j], dp[i][j + 1]);
      }
      if (i < szA && j < szB) {
        dp[i][j] = min(dp[i][j], abs(posA[i] - posB[j]) + dp[i + 1][j + 1]);
      }
    }
  }

  cout << dp[0][0] << '\n';
  return;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int T = 1;
  // cin >> T;
  while (T--) {
    Main();
  }
  return 0;
}
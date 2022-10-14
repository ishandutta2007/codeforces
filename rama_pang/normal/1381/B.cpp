#include <bits/stdc++.h>
using namespace std;
using lint = long long;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    n *= 2;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    vector<int> blocks;
    for (int i = 0; i < n; i++) {
      int j = i;
      while (j + 1 < n && a[j + 1] < a[i]) {
        j++;
      }
      blocks.emplace_back(j - i + 1);
      i = j;
    }
    int need = n / 2;
    vector<vector<int>> dp(blocks.size() + 1, vector<int>(need + 1, 0));
    dp[0][0] = 1;
    for (int i = 0; i < (int) blocks.size(); i++) {
      for (int j = 0; j <= need; j++) {
        dp[i + 1][j] |= dp[i][j];
        if (j + blocks[i] <= need) {
          dp[i + 1][j + blocks[i]] |= dp[i][j];
        }
      }
    }
    if (dp[blocks.size()][need]) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }  
  return 0;
}
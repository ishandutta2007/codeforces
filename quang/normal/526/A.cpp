#include <bits/stdc++.h>

using namespace std;

const int N = 110;

int dp[N][N];
int n;
string s;

int main() {
  ios_base::sync_with_stdio(0);
  cin >> n;
  cin >> s;
  for (int i = 0; i < n; i++) {
    if (s[i] != '.') {
      for (int j = 1; j <= n; j++) {
        dp[i][j] = 1;
        int pos = i - j;
        if (pos >= 0) {
          if (dp[i][j] < dp[pos][j] + 1) {
            dp[i][j] = dp[pos][j] + 1;
          }
        }
        if (dp[i][j] >= 5) {
          cout << "yes";
          return 0;
        }
      }
    }
  }
  cout << "no";
}
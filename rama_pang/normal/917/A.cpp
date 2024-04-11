#include <bits/stdc++.h>
using namespace std;
using lint = long long;

int N;
string S;

int dp[5005][5005];
int mt[5005];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  memset(mt, -1, sizeof(mt));

  cin >> S;
  N = S.size();

  int ans = 0;
  for (int i = N - 1; i >= 0; i--) {
    for (int j = i + 1; j < N; j++ ) {
      if (i + 1 == j) {
        dp[i][j] = (S[i] != ')' && S[j] != '(');
        mt[i] = j;
        continue;
      }
      if (mt[i] != -1) {
        dp[i][j] |= dp[i][mt[i]] && dp[mt[i] + 1][j];
      }
      if (!dp[i][j] && S[i] != ')' && S[j] != '(') {
        dp[i][j] |= dp[i + 1][j - 1];
        if (dp[i + 1][j - 1]) {
          mt[i] = j;
        }
      }
    }
  }
  for (int i = 0; i < N; i++) {
    for (int j = i; j < N; j++) {
      if (dp[i][j]) {
        ans++;
      }
    }
  }
  cout << ans << "\n";
  return 0;
}
#include <bits/stdc++.h>
using namespace std;

using lint = long long;
const lint INF = 1e18;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int N;
  cin >> N;
  vector<lint> T(N + 1), X(N + 1);
  for (int i = 1; i <= N; i++) {
    cin >> T[i] >> X[i];
  }
  int ans = 0;
  vector<vector<lint>> dp(N + 1, vector<lint>(N + 1, INF)); 
  dp[0][0] = 0;
  for (int i = 0; i <= N; i++) {
    for (int j = 0; j <= N; j++) {
      // Case 1: j == 0: no clones currently
      // - go to k, leave clone on k, go back to i
      // Case 2: j == i - 1: clone is on last cake
      // - Can go to k, wait for cake j to appear, make clone on k, go back to i
      // Case 3: j == i: already left clone waiting for cake i
      // - so can go to k, wait for cake i to appear, make clone on k, go to i+1
      // Case 4: j == i + 1: already left clone, so need to wait manually for cake i
      // - after that, can go to k, wait for cake j to appear, leave clone on k, go to i+2
      // Case 5: j > i + 1: must wait for cake i manually, then go to i+1
      if (dp[i][j] > T[i]) {
        dp[i][j] = INF;
        continue;
      }
      if (i == N) {
        ans = 1;
        break;
      }
      if (j == 0) { // currently have no clones
        for (int k = i; k <= N; k++) {
          dp[i][k] = min(dp[i][k], dp[i][j] + 2 * abs(X[k] - X[i]));
        }
      }
      if (j == i - 1) {
        for (int k = i; k <= N; k++) {
          dp[i][k] = min(dp[i][k], max(T[j], dp[i][j] + abs(X[k] - X[i])) + abs(X[k] - X[i]));
        }
      }
      if (j == i) {
        for (int k = i + 1; k <= N; k++) {
          dp[i + 1][k] = min(dp[i + 1][k], max(T[i], dp[i][j] + abs(X[k] - X[i])) + abs(X[k] - X[i + 1]));
        }
      }
      if (j == i + 1) {
        if (i + 1 == N) ans = 1;
        dp[i][j] = max(dp[i][j], T[i]);
        for (int k = i + 2; k <= N; k++) {
          dp[i + 2][k] = min(dp[i + 2][k], max(T[j], dp[i][j] + abs(X[k] - X[i])) + abs(X[k] - X[i + 2]));
        }
      }
      if (j > i + 1) {
        dp[i + 1][j] = min(dp[i + 1][j], max(dp[i][j], T[i]) + abs(X[i + 1] - X[i]));
      }
    }
  }

  if (ans) {
    cout << "YES\n";
  } else {
    cout << "NO\n";
  }
  return 0;
}
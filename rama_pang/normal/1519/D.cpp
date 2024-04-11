#include <bits/stdc++.h>
using namespace std;

using lint = long long;
const lint INF = 1e18;

void Main() {
  int N;
  cin >> N;
  vector<lint> A(N), B(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }
  for (int i = 0; i < N; i++) {
    cin >> B[i];
  }
  vector<vector<lint>> dp(N + 5, vector<lint>(N + 5));
  for (int i = N - 1; i >= 0; i--) {
    for (int j = i; j < N; j++) {
      if (i == j) {
        dp[i][i] = A[i] * B[i];
        continue;
      }
      dp[i][j] = A[i] * B[j] + B[i] * A[j] + (i + 1 < N && j > 0 ? dp[i + 1][j - 1] : 0);
    }
  }

  lint ans = 0;

  vector<lint> pref(N);
  vector<lint> suff(N);
  for (int i = 0; i < N; i++) {
    pref[i] = A[i] * B[i];
    suff[i] = A[i] * B[i];
  }
  for (int i = 1; i < N; i++) pref[i] += pref[i - 1];
  for (int i = N - 2; i >= 0; i--) suff[i] += suff[i + 1];
  for (int i = 0; i < N; i++) {
    for (int j = i; j < N; j++) {
      lint cur = dp[i][j];
      if (i) cur += pref[i - 1];
      if (j + 1 < N) cur += suff[j + 1];
      ans = max(ans, cur);
    }
  }


  cout << ans << '\n';
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
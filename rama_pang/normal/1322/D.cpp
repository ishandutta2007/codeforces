#include <bits/stdc++.h>
using namespace std;

using lint = long long;
const lint INF = 1e18;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int N, M;
  cin >> N >> M;
  M += N;
  vector<lint> L(N);
  for (int i = 0; i < N; i++) {
    cin >> L[i];
    L[i]--;
  }
  vector<lint> S(N);
  for (int i = 0; i < N; i++) {
    cin >> S[i];
  }
  vector<lint> C(M + 1);
  for (int i = 0; i < M; i++) {
    cin >> C[i];
  }

  vector<vector<lint>> dp(M + 1, vector<lint>(N + 1, -INF));
  // dp[value][cnt]
  for (int i = 0; i <= M; i++) dp[i][0] = 0;
  for (int i = N - 1; i >= 0; i--) {
    int val = L[i];
    for (int cnt = N - 1; cnt >= 0; cnt--) if (dp[val][cnt] != -INF) {
      dp[val][cnt + 1] = max(dp[val][cnt + 1], dp[val][cnt] - S[i] + C[L[i]]);
    }
    int lim = N;
    for (int val = L[i]; val < M; val++) {
      for (int cnt = 0; cnt <= lim; cnt++) if (dp[val][cnt] != -INF) {
        dp[val + 1][cnt / 2] = max(dp[val + 1][cnt / 2], dp[val][cnt] + C[val + 1] * (cnt / 2));
      }
      lim /= 2;
    }
  }
  
  lint ans = 0;
  for (int i = 0; i <= M; i++) {
    for (int j = 0; j <= N; j++) if (dp[i][j] != -INF) {
      if (i == M) {
        assert(j <= 1);
        ans = max(ans, dp[i][j]);
      } else {
        dp[i + 1][j / 2] = max(dp[i + 1][j / 2], dp[i][j] + (j / 2) * C[i + 1]);
      }
    }
  }

  cout << ans << '\n';
  return 0;
}
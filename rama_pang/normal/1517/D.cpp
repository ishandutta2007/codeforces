#include <bits/stdc++.h>
using namespace std;

using lint = long long;
const lint INF = 1e18;

lint dp[505][505][25];

void Main() {
  lint N, M, K;
  cin >> N >> M >> K;
  vector<vector<lint>> H(N, vector<lint>(M));
  vector<vector<lint>> V(N, vector<lint>(M));

  for (int i = 0; i < N; i++) {
    for (int j = 0; j + 1 < M; j++) {
      cin >> H[i][j];
    }
  }
  for (int i = 0; i + 1 < N; i++) {
    for (int j = 0; j < M; j++) {
      cin >> V[i][j];
    }
  }

  if (K & 1) {
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < M; j++) {
        cout << -1 << ' ';
      }
      cout << '\n';
    }
    return;
  }

  K /= 2;

  memset(dp, -1, sizeof(dp));
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      dp[i][j][0] = 0;
      for (int k = 1; k <= K; k++) {
        dp[i][j][k] = 1e18;
      }
    }
  }

  for (int k = 1; k <= K; k++) {
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < M; j++) {
        if (i > 0) {
          dp[i][j][k] = min(dp[i][j][k], V[i - 1][j] + dp[i - 1][j][k - 1]);
        }
        if (i + 1 < N) {
          dp[i][j][k] = min(dp[i][j][k], V[i][j] + dp[i + 1][j][k - 1]);
        }
        if (j > 0) {
          dp[i][j][k] = min(dp[i][j][k], H[i][j - 1] + dp[i][j - 1][k - 1]);
        }
        if (j + 1 < M) {
          dp[i][j][k] = min(dp[i][j][k], H[i][j] + dp[i][j + 1][k - 1]);
        }
      }
    }
  }

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cout << 2 * dp[i][j][K] << ' ';
    }
    cout << '\n';
  }
  
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
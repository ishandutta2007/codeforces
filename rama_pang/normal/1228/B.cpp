#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int N, M;
  cin >> N >> M;

  vector<int> R(N), C(M);
  for (int i = 0; i < N; i++) {
    cin >> R[i];
  }
  for (int i = 0; i < M; i++) {
    cin >> C[i];
  }
  vector<vector<int>> forced(N, vector<int>(M, 0));
  vector<vector<int>> color(N, vector<int>(M, 0));
  
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < min(M, R[i] + 1); j++) {
      forced[i][j] = 1;
      color[i][j] = 1;
    }
    if (R[i] < M) {
      color[i][R[i]] = 0;
    }
  }
  for (int j = 0; j < M; j++) {
    for (int i = 0; i < min(N, C[j] + 1); i++) {
      forced[i][j] = 1;
      color[i][j] = 1;
    }
    if (C[j] < N) {
      color[C[j]][j] = 0;
    }
  }

  auto noAnswer = [&]() {
    cout << 0 << "\n";
    exit(0);
  };

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < R[i]; j++) {
      if (forced[i][j] == 1 && color[i][j] == 0) {
        noAnswer();
      }
    }
    if (R[i] < M) {
      if (forced[i][R[i]] == 1 && color[i][R[i]] == 1) {
        noAnswer();
      }
    }
  }

  for (int j = 0; j < M; j++) {
    for (int i = 0; i < C[j]; i++) {
      if (forced[i][j] == 1 && color[i][j] == 0) {
        noAnswer();
      }
    }
    if (C[j] < N) {
      if (forced[C[j]][j] == 1 && color[C[j]][j] == 1) {
        noAnswer();
      }
    }
  }

  int ans = 1;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      if (!forced[i][j]) {
        ans *= 2;
        if (ans >= MOD) {
          ans -= MOD;
        }
      }
    }
  }

  cout << ans << "\n";
  return 0;
}
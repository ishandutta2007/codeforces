#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int N, M;
  cin >> N >> M;

  // Will use 3-operation at most once
  // All other operations are 1-operation
  // Solving for 1-operation: 
  // Can solve in greedy manner
  
  vector<vector<int>> A(N, vector<int>(M));
  for (int i = 0; i < N; i++) {
    string s;
    cin >> s;
    for (int j = 0; j < M; j++) {
      char c = s[j];
      A[i][j] = c == 'B';
    }
  }

  int cost = 0;
  vector<vector<int>> active(N, vector<int>(M));
  const auto ToggleOp = [&](int x, int y) {
    if (x < 0 || y < 0) return;
    cost -= active[x][y];
    active[x][y] ^= 1;
    cost += active[x][y];
  };
  const auto ToggleCell = [&](int x, int y) {
    ToggleOp(x, y);
    ToggleOp(x, y - 1);
    ToggleOp(x - 1, y);
    ToggleOp(x - 1, y - 1);
  };

  int ans = 1e9;
  for (int r = 0; r < N; r++) {
    cost = 0;
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < M; j++) {
        active[i][j] = 0;
      }
    }
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < M; j++) {
        if (A[i][j] == 1) {
          ToggleCell(i, j);
        }
      }
    }
    ans = min(ans, cost);
    for (int j = M - 1; j >= 0; j--) {
      for (int i = r; i < N; i++) {
        ToggleCell(i, j);
      }
      ans = min(ans, cost + 3);
    }
  }
  cout << ans << '\n';
  return 0;
}
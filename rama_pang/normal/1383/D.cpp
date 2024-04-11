#include <bits/stdc++.h>
using namespace std;

void Main() {
  int N, M;
  cin >> N >> M;
  vector<vector<int>> A(N, vector<int>(M));
  vector<int> R(N);
  vector<int> C(M);
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cin >> A[i][j];
      A[i][j]--;
      R[i] = max(R[i], A[i][j]);
      C[j] = max(C[j], A[i][j]);
    }
  }
  vector<int> posR(N * M, -1);
  vector<int> posC(N * M, -1);
  for (int i = 0; i < N; i++) posR[R[i]] = i;
  for (int j = 0; j < M; j++) posC[C[j]] = j;

  queue<pair<int, int>> valid;
  vector<vector<int>> ans(N, vector<int>(M, -1));

  for (int v = N * M - 1, r = -1, c = -1; v >= 0; v--) {
    if (posR[v] != -1) r += 1;
    if (posC[v] != -1) c += 1;
    if (posR[v] != -1 || posC[v] != -1) {
      ans[r][c] = v;
    } else {
      auto [x, y] = valid.front(); valid.pop();
      ans[x][y] = v;
    }
    if (posR[v] != -1) {
      for (int j = c - 1; j >= 0; j--) {
        valid.emplace(r, j);
      }
    }
    if (posC[v] != -1) {
      for (int i = r - 1; i >= 0; i--) {
        valid.emplace(i, c);
      }
    }
  }
  
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cout << ans[i][j] + 1 << " \n"[j + 1 == M];
    }
  }
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
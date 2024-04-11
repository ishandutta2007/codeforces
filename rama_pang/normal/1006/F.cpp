#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int N, M;
  long long K;
  cin >> N >> M >> K;

  vector<vector<long long>> A(N, vector<long long>(M));
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cin >> A[i][j];
    }
  }

  int total_steps = N - 1 + M - 1;
  int half_steps = total_steps / 2;

  vector<vector<vector<long long>>> paths(2, vector<vector<long long>>(N));
  const auto Dfs = [&](const auto &self, int type, int n, int m, int steps, long long Xor) -> void {
    if (type == 0) {
      if (steps == half_steps) {
        paths[type][n].emplace_back(Xor ^ A[n][m]);
        return;
      }
      if (n + 1 < N) self(self, type, n + 1, m, steps + 1, Xor ^ A[n][m]);
      if (m + 1 < M) self(self, type, n, m + 1, steps + 1, Xor ^ A[n][m]);
    } else if (type == 1) {
      if (steps == total_steps - half_steps) {
        paths[type][n].emplace_back(Xor ^ K);
        return;
      }
      if (n > 0) self(self, type, n - 1, m, steps + 1, Xor ^ A[n][m]);
      if (m > 0) self(self, type, n, m - 1, steps + 1, Xor ^ A[n][m]);
    }
  };

  Dfs(Dfs, 0, 0, 0, 0, 0);
  Dfs(Dfs, 1, N - 1, M - 1, 0, 0);

  long long ans = 0;
  for (int i = 0; i < N; i++) {
    auto v1 = paths[0][i];
    auto v2 = paths[1][i];
    sort(begin(v1), end(v1));
    sort(begin(v2), end(v2));
    for (auto j : v1) {
      ans += upper_bound(begin(v2), end(v2), j) - lower_bound(begin(v2), end(v2), j);
    }
  }

  cout << ans << '\n';
  return 0;
}
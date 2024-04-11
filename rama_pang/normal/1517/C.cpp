#include <bits/stdc++.h>
using namespace std;

using lint = long long;
const lint INF = 1e18;

void Main() {
  lint N;
  cin >> N;
  vector<lint> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }

  vector<vector<lint>> ans(N, vector<lint>(N, -1));
  int need = 0;
  const auto Dfs = [&](const auto &self, int x, int y, int c) {
    if (need == 0) return;
    if (ans[x][y] != -1) return;
    ans[x][y] = c;
    need--;
    if (y > 0) self(self, x, y - 1, c);
    if (x + 1 < N) self(self, x + 1, y, c);
  };

  for (int i = 0; i < N; i++) {
    need = A[i];
    Dfs(Dfs, i, i, A[i]);
    if (need != 0) {
      cout << -1 << '\n';
      return;
    }
  }

  for (int i = 0; i < N; i++) {
    for (int j = 0; j <= i; j++) {
      cout << ans[i][j] << ' ';
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
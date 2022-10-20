#include <bits/stdc++.h>

using namespace std;

void Solve(int test) {
  int n;
  cin >> n;
  vector<vector<int>> c(n * 2, vector<int>(n * 2));
  for (auto &row : c) {
    for (auto &u : row) {
      cin >> u;
    }
  }
  long long tot = 0;
  for (int i = n; i < n * 2; i++) {
    for (int j = n; j < n * 2; j++) {
      tot += c[i][j];
    }
  }
  int delta = 2e9;
  delta = min(delta, c[0][n]);
  delta = min(delta, c[0][n * 2 - 1]);
  delta = min(delta, c[n - 1][n]);
  delta = min(delta, c[n - 1][n * 2 - 1]);
  delta = min(delta, c[n][0]);
  delta = min(delta, c[n * 2 - 1][0]);
  delta = min(delta, c[n][n - 1]);
  delta = min(delta, c[n * 2 - 1][n - 1]);
  cout << tot + delta << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int tc;
  cin >> tc;
  for (int test = 1; test <= tc; ++test) Solve(test);
  return 0;
}
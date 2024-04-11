#include <bits/stdc++.h>
using namespace std;

using lint = long long;
const lint MOD = 1e9 + 7;

void Main() {
  int n;
  cin >> n;
  int m = 2;
  vector<string> a(2);
  cin >> a[0] >> a[1];
  swap(n, m);
  vector<pair<int, int>> que;
  que.emplace_back(0, 0);
  vector<vector<int>> vis(n, vector<int>(m));
  vis[0][0] = 1;
  const auto Push = [&](int x, int y) {
    if (x < 0 || x >= n || y < 0 || y >= m || a[x][y] == '1') {
      return;
    }
    if (!vis[x][y]) {
      vis[x][y] = 1;
      que.emplace_back(x, y);
    }
  };
  for (int q = 0; q < int(que.size()); q++) {
    auto [x, y] = que[q];
    for (int d = -1; d <= 1; d++) {
      for (int e = -1; e <= 1; e++) {
        Push(x + d, y + e);
      }
    }
  }
  if (vis[n - 1][m - 1]) {
    cout << "YES\n";
  } else {
    cout << "NO\n";
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int T = 1;
  cin >> T;
  while (T--) {
    Main();
  }
  return 0;
}
#include <bits/stdc++.h>
using namespace std;
using lint = long long;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int T;
  cin >> T;
  while (T--) {
    int n, m;
    cin >> n >> m;
    vector<string> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    a[n - 1][m - 1] = 'G';

    int valid = 1;
    vector<int> dx = {1, 0, -1, 0};
    vector<int> dy = {0, 1, 0, -1};
    auto Inside = [&](int i, int j) {
      return 0 <= i && i < n && 0 <= j && j < m;
    };

    int good = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (i != n - 1 || j != m - 1) {
          if (a[i][j] == 'G') good = 1;
        }
        if (a[i][j] != 'B') continue;
        for (int d = 0; d < 4; d++) {
          if (!Inside(i + dx[d], j + dy[d])) continue;
          if (a[i + dx[d]][j + dy[d]] == 'G') {
            valid = 0;
          } else if (a[i + dx[d]][j + dy[d]] != 'B') {
            a[i + dx[d]][j + dy[d]] = '#';
          }
        }
      }
    } 

    vector<vector<int>> vis(n, vector<int>(m, 0));
    function<void(int, int)> Flood = [&](int i, int j) {
      if (vis[i][j] || a[i][j] == '#') return;
      vis[i][j] = 1;
      for (int d = 0; d < 4; d++) {
        if (Inside(i + dx[d], j + dy[d])) {
          Flood(i + dx[d], j + dy[d]);
        }
      }
    };

    Flood(n - 1, m - 1);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (a[i][j] == 'G' && vis[i][j] == 0) valid = 0;
        if (a[i][j] == 'B' && vis[i][j] == 1) valid = 0;
      }
    }

    if (good == 0 || valid == 1) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  } 
}
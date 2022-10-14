#include <bits/stdc++.h>
using namespace std;
using lint = long long;

void Main() {
  int n;
  cin >> n;
  vector<string> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<pair<int, int>> cells;
  vector<pair<int, int>> ans;
  cells.emplace_back(0, 1);
  cells.emplace_back(1, 0);
  cells.emplace_back(0, 2);
  cells.emplace_back(1, 1);
  cells.emplace_back(2, 0);
  for (int mask = 0; mask < (1 << 5); mask++) {
    if (__builtin_popcount(mask) > 2) {
      continue;
    }
    for (int i = 0; i < 5; i++) {
      if ((mask >> i) & 1) {
        a[cells[i].first][cells[i].second] ^= '0' ^ '1';
      }
    }

    bool valid = true;
    for (int d = 0; d < 2; d++) {
      a[n - 1][n - 1] = d + '0';
      vector<vector<int>> vis(n, vector<int>(n));
      vis[0][0] = 1;
      queue<pair<int, int>> q;
      q.emplace(0, 0);
      while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        if (x + 1 < n && vis[x + 1][y] == 0 && a[x + 1][y] == d + '0') {
          q.emplace(x + 1, y);
          vis[x + 1][y] = 1;
        }
        if (x - 1 >= 0 && vis[x - 1][y] == 0 && a[x - 1][y] == d + '0') {
          q.emplace(x - 1, y);
          vis[x - 1][y] = 1;
        }
        if (y + 1 < n && vis[x][y + 1] == 0 && a[x][y + 1] == d + '0') {
          q.emplace(x, y + 1);
          vis[x][y + 1] = 1;
        }
        if (y - 1 >= 0 && vis[x][y - 1] == 0 && a[x][y - 1] == d + '0') {
          q.emplace(x, y - 1);
          vis[x][y - 1] = 1;
        }
      }

      valid &= !vis[n - 1][n - 1];
    }

    if (valid) {
      ans.clear();
      for (int i = 0; i < 5; i++) {
        if ((mask >> i) & 1) {
          ans.emplace_back(cells[i]);
        }
      }
    }

    for (int i = 0; i < 5; i++) {
      if ((mask >> i) & 1) {
        a[cells[i].first][cells[i].second] ^= '0' ^ '1';
      }
    }
  }

  cout << ans.size() << '\n';
  for (auto i : ans) {
    cout << i.first + 1 << ' ' << i.second + 1 << '\n';
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
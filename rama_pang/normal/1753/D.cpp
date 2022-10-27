#include <bits/stdc++.h>
using namespace std;

using lint = long long;

void Main() {
  int n, m, p, q;
  cin >> n >> m >> p >> q;
  vector<string> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  vector<lint> dist(n * m, -1);
  vector<vector<pair<int, int>>> adj(n * m);
  priority_queue<pair<lint, int>> pq;
  const auto Add = [&](int x, int y, int u, int v, int w) {
    adj[x * m + y].emplace_back(u * m + v, w);    
  };

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (a[i][j] == '#') {
        continue;
      }
      if (a[i][j] == '.') {
        pq.emplace(0, i * m + j);
        dist[i * m + j] = 0;
      }
      if (j + 2 < m && a[i][j + 1] == 'L' && a[i][j + 2] == 'R') {
        Add(i, j, i, j + 2, q);
      }
      if (j - 2 >= 0 && a[i][j - 2] == 'L' && a[i][j - 1] == 'R') {
        Add(i, j, i, j - 2, q);
      }
      if (i + 2 < n && a[i + 1][j] == 'U' && a[i + 2][j] == 'D') {
        Add(i, j, i + 2, j, q);
      }
      if (i - 2 >= 0 && a[i - 2][j] == 'U' && a[i - 1][j] == 'D') {
        Add(i, j, i - 2, j, q);
      }
      if (i + 1 < n && j + 1 < m && a[i + 1][j] == 'L' && a[i + 1][j + 1] == 'R') {
        Add(i, j, i + 1, j + 1, p);
      }
      if (i + 1 < n && j + 1 < m && a[i][j + 1] == 'U' && a[i + 1][j + 1] == 'D') {
        Add(i, j, i + 1, j + 1, p);
      }
      if (i + 1 < n && j - 1 >= 0 && a[i + 1][j] == 'R' && a[i + 1][j - 1] == 'L') {
        Add(i, j, i + 1, j - 1, p);
      }
      if (i + 1 < n && j - 1 >= 0 && a[i][j - 1] == 'U' && a[i + 1][j - 1] == 'D') {
        Add(i, j, i + 1, j - 1, p);
      }
      if (i - 1 >= 0 && j - 1 >= 0 && a[i - 1][j] == 'R' && a[i - 1][j - 1] == 'L') {
        Add(i, j, i - 1, j - 1, p);
      }
      if (i - 1 >= 0 && j - 1 >= 0 && a[i][j - 1] == 'D' && a[i - 1][j - 1] == 'U') {
        Add(i, j, i - 1, j - 1, p);
      }
      if (i - 1 >= 0 && j + 1 < m && a[i - 1][j] == 'L' && a[i - 1][j + 1] == 'R') {
        Add(i, j, i - 1, j + 1, p);
      }
      if (i - 1 >= 0 && j + 1 < m && a[i][j + 1] == 'D' && a[i - 1][j + 1] == 'U') {
        Add(i, j, i - 1, j + 1, p);
      }
    }
  }

  while (!pq.empty()) {
    auto [dt, u] = pq.top();
    pq.pop();
    if (dist[u] != -dt) {
      continue;
    }
    // cout << u / m << ' ' << u % m << ' ' << -dt << '\n';
    for (auto [v, w] : adj[u]) {
      if (dist[v] == -1 || dist[v] > dist[u] + w) {
        dist[v] = dist[u] + w;
        pq.emplace(-dist[v], v);
      }
    }
  }

  lint ans = 1e18;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (j + 1 < m && a[i][j] != '#' && a[i][j + 1] != '#') {
        lint x = dist[i * m + j];
        lint y = dist[i * m + j + 1];
        if (x != -1 && y != -1) {
          ans = min(ans, x + y);
        }
      }
      if (i + 1 < n && a[i][j] != '#' && a[i + 1][j] != '#') {
        lint x = dist[i * m + j];
        lint y = dist[(i + 1) * m + j];
        if (x != -1 && y != -1) {
          ans = min(ans, x + y);
        }
      }       
    }
  }
  if (ans > 1e17) cout << "-1\n";
  else cout << ans << '\n';
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
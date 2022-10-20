#include <bits/stdc++.h>

using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  iota(a.begin(), a.end(), 0);
  vector<vector<int>> dist(n, vector<int>(n, -1));

  function<void(const vector<int> &, int)> Dfs = [&](const vector<int> &a, int h) {
    if (a.size() == 1) return;
    int n = a.size();
    int m = (n + k - 1) / k;
    for (int i = 0; i < n; i += m) {
      vector<int> now;
      for (int j = i; j < min(i + m, n); j++) {
        now.push_back(a[j]);
        for (int x = 0; x < i; x++) {
          dist[a[x]][a[j]] = h;
        }
      }
      Dfs(now, h + 1);
    }
  };

  Dfs(a, 0);
  int res = 0;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      res = max(res, dist[i][j] + 1);
    }
  }
  cout << res << '\n';

  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      cout << dist[i][j] + 1 << ' ';
    }
  }
  cout << '\n';
  return 0;
}
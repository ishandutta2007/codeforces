#include <bits/stdc++.h>
using namespace std;
using lint = long long;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int T;
  cin >> T;
  while (T--) {
    int n, x;
    cin >> n >> x;
    x--;
    vector<vector<int>> adj(n);
    for (int i = 0; i < n - 1; i++) {
      int u, v;
      cin >> u >> v;
      u--, v--;
      adj[u].emplace_back(v);
      adj[v].emplace_back(u);
    }

    vector<int> d(n);
    vector<int> sz(n);
    d[x] = 1;
    function<void(int, int)> Dfs = [&](int u, int p) {
      sz[u] = 1;
      for (auto v : adj[u]) if (v != p) {
        d[v] = d[u] + 1;
        Dfs(v, u);
        sz[u] += sz[v];
      }
    };
    Dfs(x, -1);
    int cur = 1;
    while (true) {
      int ch = 0;
      for (auto v : adj[x]) if (sz[v] > 0) ch++;
      if (ch <= 1) break;
      int done = 0;
      for (auto v : adj[x]) if (sz[v] > 1) {
        sz[v]--;
        done = 1;
        break;
      }
      if (!done) {
        for (auto v : adj[x]) if (sz[v] > 0) {
          done = 1;
          sz[v]--;
          break;
        }
      }
      assert(done == 1);
      cur ^= 1;
    }
    if (cur == 0) {
      cout << "Ashish\n";
    } else {
      cout << "Ayush\n";
    }
  }
}
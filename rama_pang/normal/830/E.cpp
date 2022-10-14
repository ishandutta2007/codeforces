#include <bits/stdc++.h>
using namespace std;

int Solve() {
  int N, M;
  cin >> N >> M;
  vector<int> ans(N, 0);

  vector<vector<int>> adj(N);
  for (int i = 0; i < M; i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    adj[u].emplace_back(v);
    adj[v].emplace_back(u);
  }

  vector<int> vis(N);
  for (int i = 0; i < N; i++) {
    if (vis[i] || adj[i].size() == 0) {
      continue;
    }
    vector<int> connected;
    queue<int> q;
    q.emplace(i);
    vis[i] = 1;
    while (!q.empty()) {
      int u = q.front();
      q.pop();
      connected.emplace_back(u);
      for (auto v : adj[u]) if (!vis[v]) {
        vis[v] = 1;
        q.emplace(v);
      }
    }
    int edges = 0;
    for (auto u : connected) {
      edges += adj[u].size();
    }
    assert(edges % 2 == 0);
    edges /= 2;
    if (connected.size() <= edges) {
      ans.assign(N, 0);
      for (auto u : connected) {
        ans[u] = 1;
      }
      break;
    } else {
      assert(edges + 1 == connected.size()); // tree
      bool found = false;
      for (auto u : connected) {
        if (adj[u].size() >= 4) {
          ans.assign(N, 0);
          for (auto v : connected) {
            ans[v] = 1;
          }
          ans[u] = 2;
          found = true;
          break;
        }
      }
      if (found) {
        break;
      }
      int three = 0;
      for (auto u : connected) {
        if (adj[u].size() == 3) {
          three++;
        }
      }
      if (three == 0) {
        continue;
      }
      if (three >= 2) {
        int fs = -1, sc = -1;
        for (auto u : connected) {
          if (adj[u].size() == 3) {
            if (fs == -1) {
              fs = u;
            } else if (sc == -1) {
              sc = u;
            }
          }
        }
        assert(fs != -1 && sc != -1);
        vector<int> path;
        function<bool(int, int)> Dfs = [&](int u, int p) {
          if (u == sc) {
            path.emplace_back(u);
            return true;
          }
          for (auto v : adj[u]) if (v != p) {
            if (Dfs(v, u)) {
              path.emplace_back(u);
              return true;
            }
          }
          return false;
        };
        assert(Dfs(fs, -1));
        ans.assign(N, 0);
        for (auto u : connected) {
          ans[u] = 1;
        }
        for (auto u : path) {
          ans[u] = 2;
        }
        break;
      }
      assert(three == 1);
      int center = -1;
      for (auto u : connected) {
        if (adj[u].size() == 3) {
          center = u;
        }
      }
      bool can = true;
      for (auto v : adj[center]) {
        if (adj[v].size() == 1) {
          can = false;
        }
      }
      if (can) {
        ans.assign(N, 0);
        for (auto u : connected) {
          ans[u] = 1;
        }
        assert(adj[center].size() == 3);
        ans[center] = 3;
        for (auto v : adj[center]) {
          assert(adj[v].size() == 2);
          ans[v] = 2;
        }
        break;
      }
      int adjtwo = 0;
      for (auto v : adj[center]) {
        if (adj[v].size() == 2) {
          adjtwo++;
        }
      }
      if (adjtwo == 2) {
        bool finally = false;
        int longerarm = 0;
        for (auto v : adj[center]) {
          if (adj[v].size() == 2) {
            for (auto w : adj[v]) if (w != center) {
              if (adj[w].size() == 2) {
                longerarm++;
              }
            }
          }
        }
        if (longerarm == 2) {
          finally = true;
          ans.assign(N, 0);
          for (auto u : connected) {
            ans[u] = 1;
          }
          ans[center] = 4;
          for (auto v : adj[center]) {
            if (adj[v].size() == 2) {
              ans[v] = 3;
              for (auto w : adj[v]) if (w != center) {
                ans[w] = 2;
              }
            } else {
              ans[v] = 2;
            }
          }
        }
        if (finally) {
          break;
        }
        // some more uncovered cases
        int superlongarm = -1;
        for (auto v : adj[center]) {
          if (adj[v].size() == 2) {
            for (auto w : adj[v]) if (w != center) {
              if (adj[w].size() == 2) {
                for (auto x : adj[w]) if (x != v) {
                  if (adj[x].size() == 2) {
                    for (auto y : adj[x]) if (y != w) {
                      if (adj[y].size() == 2) {
                        superlongarm = v;
                      }
                    }
                  }
                }
              }
            }
          }
        }
        if (superlongarm != -1) {
          ans.assign(N, 0);
          for (auto u : connected) {
            ans[u] = 1;
          }
          ans[center] = 6;
          for (auto v : adj[center]) {
            if (adj[v].size() == 2) {
              if (v != superlongarm) {
                ans[v] = 4;
                for (auto w : adj[v]) if (w != center) {
                  ans[w] = 2;
                }
                continue;
              }
              ans[v] = 5;
              for (auto w : adj[v]) if (w != center) {
                if (adj[w].size() == 2) {
                  for (auto x : adj[w]) if (x != v) {
                    if (adj[x].size() == 2) {
                      for (auto y : adj[x]) if (y != w) {
                        if (adj[y].size() == 2) {
                          ans[w] = 4;
                          ans[x] = 3;
                          ans[y] = 2;
                        }
                      }
                    }
                  }
                }
              }
            } else {
              ans[v] = 3;
            }
          }
          break;
        }
      }
    }
  }

  auto Valid = [&](vector<int> a) {
    long long power = 0;
    for (auto i = 0; i < N; i++) {
      power -= 1ll * a[i] * a[i];
    }
    for (int u = 0; u < N; u++) {
      for (auto v : adj[u]) if (u < v) {
        power += 1ll * a[u] * a[v];
      }
    }
    return power >= 0;
  };

  if (ans == vector<int>(N, 0)) {
    cout << "NO\n";
  } else {
    assert(Valid(ans));
    cout << "YES\n";
    for (int i = 0; i < N; i++) {
      if (i > 0) {
        cout << " ";
      }
      cout << ans[i];
    }
    cout << "\n";
  }
  return 0;    
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int T;
  cin >> T;
  while (T--) {
      Solve();
  }
  return 0;
}
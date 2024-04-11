#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int N, M;
  cin >> N >> M;
  vector<int> ws;
  vector<array<int, 3>> edges;
  for (int i = 0; i < M; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    u--, v--;
    edges.push_back({w, u, v});
  }
  sort(begin(edges), end(edges));

  vector<vector<pair<int, int>>> adj(N);
  for (int i = 0; i < M; i++) {
    adj[edges[i][1]].push_back({edges[i][2], i});
  }

  const auto Check = [&](int mx) {
    vector<bool> done(N, false);
    vector<int> match(N, -1);
    for (int i = 0; i < N; i++) {
      for (auto j : adj[i]) {
        if (j.second > mx) {
          break;
        }
        if (match[j.first] == -1) {
          match[j.first] = i;
          done[i] = true;
          break;
        }
      }
    }

    bitset<10005> vis = 0;
    const auto Dfs = [&](const auto &self, int u) {
      if (vis[u]) {
        return 0;
      }
      vis[u] = 1;
      for (auto j : adj[u]) {
        if (j.second > mx) {
          break;
        }
        if (match[j.first] == -1) {
          match[j.first] = u;
          done[u] = true;
          return 1;
        }
      }

      for (auto j : adj[u]) {
        if (j.second > mx) {
          break;
        }
        if (self(self, match[j.first])) {
          match[j.first] = u;
          done[u] = true;
          return 1;
        }
      }

      return 0;
    };

    for (int i = 0; i < N; i++) {
      if (!done[i]) {
        vis = 0;
        if (!Dfs(Dfs, i)) {
          return false;
        }
      }
    }

    return true;
  };

  int lo = 0, hi = M;
  while (lo < hi) {
    int md = (lo + hi) / 2;
    if (Check(md)) {
      hi = md;
    } else {
      lo = md + 1;
    }
  }
  
  cout << (lo == M ? -1 : edges[lo][0]) << "\n";
  return 0;
}
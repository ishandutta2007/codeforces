#include <bits/stdc++.h>
using namespace std;
using lint = long long;

const int MAXN = 205;

int N;
vector<int> adj[MAXN];

bool Dfs(int u, int p, int t, vector<int> &res) {
  if (u == t) {
    res.emplace_back(u);
    return true;
  }
  for (auto v : adj[u]) if (v != p) {
    if (Dfs(v, u, t, res)) {
      res.emplace_back(u);
      return true;
    }
  }
  return false;
}

vector<int> Path(int u, int v) {
  vector<int> res;
  Dfs(u, -1, v, res);
  return res;
}

pair<int, int> DfsDepth(int u, int d, int p, int block) {
  pair<int, int> res = {d, u};
  for (auto v : adj[u]) if (v != p && v != block) {
    res = max(res, DfsDepth(v, d + 1, u, block));
  }
  return res;
}

int Diameter(int u, int block) {
  int v = DfsDepth(u, 0, -1, block).second;
  return DfsDepth(v, 0, -1, block).first;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  cin >> N;
  for (int i = 1; i < N; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].emplace_back(v);
    adj[v].emplace_back(u);
  }
  
  lint ans = 0;

  for (int i = 1; i <= N; i++) {
    for (int j = i + 1; j <= N; j++) {
      auto d = Path(i, j);
      static vector<int> inpath(N + 1);
      for (auto k : d) {
        inpath[k] = 1;
      }
      int mx = 0;
      for (auto k : d) {
        for (auto u : adj[k]) {
          if (!inpath[u]) {
            mx = max(mx, Diameter(u, k));
          }
        }
      }
      ans = max(ans, 1ll * (int(d.size()) - 1) * mx);
      for (auto k : d) {
        inpath[k] = 0;
      }
    }
  }

  cout << ans << "\n";
  return 0;
}
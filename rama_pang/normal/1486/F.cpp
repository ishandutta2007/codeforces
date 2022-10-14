#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int N;
  cin >> N;
  vector<vector<int>> adj(N);
  for (int i = 1; i < N; i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    adj[u].emplace_back(v);
    adj[v].emplace_back(u);
  }
  int M;
  cin >> M;
  vector<pair<int, int>> path(M);
  for (int i = 0; i < M; i++) {
    cin >> path[i].first >> path[i].second;
    path[i].first--, path[i].second--;
  }

  vector<int> sz(N);
  vector<int> dead(N);
  const auto Centroid = [&](int u) {
    const auto Dfs = [&](const auto &self, int u, int p) -> void {
      sz[u] = 1;
      for (auto v : adj[u]) if (!dead[v] && v != p) {
        self(self, v, u);
        sz[u] += sz[v];
      }
    };
    Dfs(Dfs, u, -1);
    int s = sz[u];
    int p = -1;
    while (true) {
      pair<int, int> mx = {-1, -1};
      for (auto v : adj[u]) if (!dead[v] && v != p) {
        mx = max(mx, {sz[v], v});
      }
      if (mx.first * 2 <= s) {
        return u;
      }
      p = u;
      u = mx.second;
    }
  };

  const int LOG = 20;
  vector<vector<int>> lift(N, vector<int>(LOG));
  vector<int> color(N);
  vector<int> value(N);
  vector<int> depth(N);
  vector<vector<pair<int, int>>> ls(N);
  const auto DfsCol = [&](const auto &self, int u, int p, int x) -> void {
    color[u] = x;
    value[u] = 0;
    lift[u][0] = p;
    ls[u].clear();
    for (int j = 1; j < LOG; j++) {
      if (lift[u][j - 1] == -1) {
        lift[u][j] = -1;
      } else {
        lift[u][j] = lift[lift[u][j - 1]][j - 1];
      }
    }
    for (auto v : adj[u]) if (!dead[v] && v != p) {
      depth[v] = depth[u] + 1;
      self(self, v, u, x);
    }
  };

  const auto GetAnc = [&](int u, int x) {
    // cerr << u << ' ' << x << " why" << endl;
    for (int i = 0; i < LOG; i++) {
      if ((x >> i) & 1) {
        assert(u != -1);
        u = lift[u][i];
      }
    }
    return u;
  };

  const auto Lca = [&](int u, int v) {
    if (depth[u] > depth[v]) {
      swap(u, v);
    }
    v = GetAnc(v, depth[v] - depth[u]);
    // cerr << u << ' ' << v << " lca" << endl;
    for (int i = LOG - 1; i >= 0; i--) {
      if (lift[u][i] != lift[v][i]) {
        u = lift[u][i];
        v = lift[v][i];
      }
    }
    return u == v ? u : lift[u][0];
  };

  long long ans = 0;

  const auto DfsDp = [&](const auto &self, int u, int p) -> void {
    for (auto v : adj[u]) if (!dead[v] && v != p) {
      self(self, v, u);
      value[u] += value[v];
    }
    for (auto i : ls[u]) {
      int t = value[u];
      if (i.first != -1) t -= value[i.first];
      if (i.second != -1) t -= value[i.second];
      // cerr << t << " t" << endl;
      ans += t;
    }
  };

  map<pair<int, int>, int> mp;
  const auto Gen = [&](const auto &self, int u, vector<int> active) -> void {
    if (active.empty()) return;
    u = Centroid(u);
    // cerr << u << endl;
    depth[u] = 0;
    DfsCol(DfsCol, u, -1, 0);
    color[u] = -1;
    for (int vid = 0; vid < adj[u].size(); vid++) if (!dead[adj[u][vid]]) {
      DfsCol(DfsCol, adj[u][vid], u, vid);
    }
    int all = 0;
    vector<int> oncentroid(adj[u].size());
    vector<vector<int>> todo(adj[u].size());
    array<int, 3> last = {-1, -1, 0};
    mp.clear();
    for (auto i : active) {
      // cerr << "HI " << endl;
      // cerr << path[i].first << ' ' << path[i].second << endl;
      if (color[path[i].first] == color[path[i].second] && color[path[i].first] != -1) {
        todo[color[path[i].first]].emplace_back(i);
      }
      if (color[path[i].first] == -1 || color[path[i].first] != color[path[i].second]) {
        // cerr << "AA" << endl;
        if (color[path[i].first] != -1) value[path[i].first]++;
        if (color[path[i].second] != -1) value[path[i].second]++;
        int u = path[i].first, v = path[i].second;
        if (color[u] == -1 && color[v] == -1) {
          ans += all;
        } else if (color[u] == -1) {
          ans += all;
          ans -= oncentroid[color[v]];
        } else if (color[v] == -1) {
          ans += all;
          ans -= oncentroid[color[u]];
        } else {
          ans += all;
          ans -= oncentroid[color[u]];
          ans -= oncentroid[color[v]];
          ans += mp[{color[u], color[v]}];
          mp[{color[u], color[v]}]++;
          mp[{color[v], color[u]}]++;
        }
        all++;
        if (color[u] != -1) oncentroid[color[u]]++;
        if (color[v] != -1) oncentroid[color[v]]++;
      } else {
        int w = Lca(path[i].first, path[i].second);
        if (path[i].first == w && path[i].second == w) {
          ls[w].emplace_back(-1, -1);
        } else if (path[i].first == w) {
          ls[w].emplace_back(GetAnc(path[i].second, -depth[w] + depth[path[i].second] - 1), -1);
        } else if (path[i].second == w) {
          ls[w].emplace_back(GetAnc(path[i].first, -depth[w] + depth[path[i].first] - 1), -1);
        } else {
          ls[w].emplace_back(GetAnc(path[i].first, -depth[w] + depth[path[i].first] - 1), GetAnc(path[i].second, -depth[w] + depth[path[i].second] - 1));
        }
      }
    }

    // cerr << "ZZ" << endl;
    DfsDp(DfsDp, u, -1);

    dead[u] = 1;
    for (int vid = 0; vid < adj[u].size(); vid++) {
      int v = adj[u][vid];
      if (!dead[v]) self(self, v, todo[vid]);
    }
  };

  vector<int> act;
  for (int i = 0; i < M; i++) { 
    act.emplace_back(i);
  }
  Gen(Gen, 0, act);

  // cerr << "ans: ";
  cout << ans << '\n';
  return 0;
}
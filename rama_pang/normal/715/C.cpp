#include <bits/stdc++.h>
using namespace std;

int Totient(int x) {
  int z = x;
  for (int i = 2; i * i <= x; i++) {
    if (x % i == 0) {
      while (x % i == 0) {
        x /= i;
      }
      z = z - z / i;
    }
  }
  if (x > 1) {
    z = z - z / x;
  }
  return z;
}

int Power(int a, int x, int mod) {
  int z = 1;
  while (x > 0) {
    if (x & 1) z = 1ll * z * a % mod;
    a = 1ll * a * a % mod;
    x /= 2;
  }
  return z;
}

int main() {
  int N, M;
  cin >> N >> M;

  vector<vector<pair<int, int>>> adj(N);
  for (int i = 0; i < N - 1; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    adj[u].emplace_back(v, w);
    adj[v].emplace_back(u, w);
  }

  if (M == 1) {
    cout << 1ll * N * (N - 1) << '\n';
    return 0;
  }

  int totient = Totient(M);
  int I10 = Power(10, totient - 1, M);
  assert(10ll * I10 % M == 1);

  vector<int> pow10(N + 1, 1);
  vector<int> inv10(N + 1, 1);
  for (int i = 1; i <= N; i++) {
    pow10[i] = 10ll * pow10[i - 1] % M;
    inv10[i] = 1ll * I10 * inv10[i - 1] % M;
  }

  long long ans = 0;

  vector<int> siz(N);
  vector<int> dead(N);
  vector<int> depth(N);
  vector<int> digitTo(N);
  vector<int> digitFrom(N);

  const auto Dfs = [&](const auto &self, int u, int p) -> void {
    siz[u] = 1;
    for (auto [v, w] : adj[u]) if (!dead[v] && v != p) {
      depth[v] = depth[u] + 1;
      self(self, v, u);
      siz[u] += siz[v];
    }
  };

  const auto Centroid = [&](int u) {
    Dfs(Dfs, u, -1);
    int p = -1;
    int s = siz[u];
    while (true) {
      pair<int, int> mx = {-1, -1};
      for (auto [v, w] : adj[u]) if (!dead[v] && v != p) {
        mx = max(mx, {siz[v], v});
      }
      if (mx.first * 2 <= s) {
        return u;
      }
      p = u;
      u = mx.second;
    }
    return -1;
  };

  const auto DfsGet = [&](const auto &self, int u, int p, int w, vector<int> &vec) -> void {
    vec.emplace_back(u);
    digitTo[u] = (10ll * digitTo[p] + w) % M;
    digitFrom[u] = (1ll * w * pow10[depth[u] - 1] + digitFrom[p]) % M;
    for (auto [v, w2] : adj[u]) if (!dead[v] && v != p) {
      self(self, v, u, w2, vec);
    }
  };

  const auto Gen = [&](const auto &self, int u) -> void {
    u = Centroid(u);
    static vector<vector<int>> subtree; subtree.clear();
    subtree.resize(adj[u].size());

    dead[u] = 1;
    depth[u] = 0;
    digitTo[u] = 0;
    digitFrom[u] = 0;
    Dfs(Dfs, u, -1);

    for (int i = 0; i < int(adj[u].size()); i++) if (!dead[adj[u][i].first]) {
      DfsGet(DfsGet, adj[u][i].first, u, adj[u][i].second, subtree[i]);
      for (auto j : subtree[i]) { // u and other
        ans += digitTo[j] == 0;
        ans += digitFrom[j] == 0;
      }
    }

    // digitFrom[u] * 10^depth[v] + digitTo[v] = 0 mod M
    // digitFrom[u] + digitTo[v] * 10^{-depth[v]} = 0 mod M

    static vector<int> cnt; cnt.clear();
    static vector<int> coord; coord.clear();
    for (int i = 0; i < int(adj[u].size()); i++) if (!dead[adj[u][i].first]) {
      for (auto j : subtree[i]) {
        coord.emplace_back(digitFrom[j]);
      }
    }
    
    sort(begin(coord), end(coord));
    coord.resize(unique(begin(coord), end(coord)) - begin(coord));
    cnt.resize(coord.size());

    for (int i = 0; i < int(adj[u].size()); i++) if (!dead[adj[u][i].first]) {
      for (auto j : subtree[i]) {
        int y = lower_bound(begin(coord), end(coord), digitFrom[j]) - begin(coord);
        cnt[y]++;
      }
    }

    for (int i = 0; i < int(adj[u].size()); i++) if (!dead[adj[u][i].first]) {
      for (auto j : subtree[i]) {
        int y = lower_bound(begin(coord), end(coord), digitFrom[j]) - begin(coord);
        cnt[y]--;
      }
      for (auto j : subtree[i]) {
        int x = (M - (1ll * digitTo[j] * inv10[depth[j]] % M)) % M;
        int y = lower_bound(begin(coord), end(coord), x) - begin(coord);
        if (y < int(coord.size()) && coord[y] == x) {
          ans += cnt[y];
        }
      }
      for (auto j : subtree[i]) {
        int y = lower_bound(begin(coord), end(coord), digitFrom[j]) - begin(coord);
        cnt[y]++;
      }
    }

    for (auto [v, w] : adj[u]) if (!dead[v]) {
      self(self, v);
    }
  };

  Gen(Gen, 0);

  cout << ans << '\n';
  return 0;
}
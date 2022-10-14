#include <bits/stdc++.h>
using namespace std;
using lint = long long;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  const lint mod = 1e9 + 7;

  lint n, m, k;
  cin >> n >> m >> k;

  vector<vector<pair<lint, lint>>> adj(n);
  vector<array<lint, 3>> edge;
  vector<array<lint, 2>> lines;

  for (lint i = 0; i < m; i++) {
    lint u, v, w;
    cin >> u >> v >> w;
    u--, v--;
    adj[u].emplace_back(v, w);
    adj[v].emplace_back(u, w);
    edge.push_back({u, v, w});
  }

  vector<vector<lint>> dist(n, vector<lint>(n + 1, -1));
  dist[0][0] = 0;
  for (int i = 0; i < n; i++) {
    for (int u = 0; u < n; u++) {
      if (dist[u][i] != -1) {
        for (auto v : adj[u]) {
          dist[v.first][i + 1] = max(dist[v.first][i + 1], dist[u][i] + v.second);
        }
      }
    }
  }
  for (lint i = 0; i < m; i++) {
    lint u = edge[i][0];
    lint v = edge[i][1];
    lint w = edge[i][2];
    lint mx = -1e18;
    for (int j = 0; j <= n; j++) {
      if (dist[u][j] != -1) {
        mx = max(mx, dist[u][j] - 1ll * j * w);
      }
      if (dist[v][j] != -1) {
        mx = max(mx, dist[v][j] - 1ll * j * w);
      }
    }
    if (mx != -1e18) {
      lines.push_back({w, mx});
    }
  }
  lint ans = 0;
  for (int i = 1; i <= min(k, n); i++) {
    lint mx = 0;
    for (int j = 0; j < n; j++) {
      mx = max(mx, dist[j][i]);
    }
    ans += mx;
    ans %= mod;
  }
  ans %= mod;
  if (k <= n) {
    cout << ans << "\n";
    return 0;
  }
  
  for (int i = 0; i < m; i++) {
    lint l = n + 1, r = k;
    auto get = [&](lint id, lint x) {
      return pair<lint, lint>{lines[id][0] * x + lines[id][1], id};
    };
    for (int j = 0; j < m; j++) if (i != j) {
      if (get(i, l) > get(j, l) && get(i, r) > get(j, r)) {
        continue;
      }
      if (get(i, l) < get(j, l) && get(i, r) < get(j, r)) {
        l = r + 1;
        break;
      }
      if (get(i, l) > get(j, l)) {
        lint lo = l, hi = r;
        while (lo < hi) {
          lint md = (lo + hi + 1) / 2;
          if (get(i, md) > get(j, md)) {
            lo = md;
          } else {
            hi = md - 1;
          }
        }
        r = lo;
      } else if (get(i, r) > get(j, r)) {
        lint lo = l, hi = r;
        while (lo < hi) {
          lint md = (lo + hi) / 2;
          if (get(i, md) > get(j, md)) {
            hi = md;
          } else {
            lo = md + 1;
          }
        }
        l = lo;
      }
    }
    if (l > r) continue;
    lint cnt = r - l + 1;
    ans += 1ll * (get(i, l).first + get(i, r).first) % mod * cnt % mod * ((mod + 1) / 2) % mod;
    ans %= mod;
  }

  cout << ans << "\n";
  return 0;
}
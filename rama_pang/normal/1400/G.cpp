#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;

class DisjointSet {
 public:
  int n;
  vector<int> p;
  vector<int> sz;

  DisjointSet(int n) : n(n), p(n), sz(n, 1) {
    iota(begin(p), end(p), 0);
  }

  int Find(int x) {
    return p[x] == x ? x : p[x] = Find(p[x]);
  }
  int Unite(int x, int y) {
    x = Find(x), y = Find(y);
    if (x == y) return 0;
    if (sz[x] < sz[y]) swap(x, y);
    p[y] = x;
    sz[x] += sz[y];
    return 1;
  }
  int ComponentSize(int x) {
    return sz[Find(x)];
  }
};

int Power(int n, int x) {
  int mul = n;
  int res = 1;
  while (x > 0) {
    if (x & 1) {
      res = 1ll * res * mul % MOD;
    }
    x /= 2;
    mul = 1ll * mul * mul % MOD;
  }
  return res;
}

int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int n, m;
  cin >> n >> m;
  vector<pair<int, int>> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i].first >> a[i].second;
  }

  DisjointSet D(n);
  vector<int> haters;
  vector<pair<int, int>> edges;
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    D.Unite(u, v);
    edges.emplace_back(u, v);
    haters.emplace_back(u);
    haters.emplace_back(v);
  }
  sort(begin(haters), end(haters));
  haters.resize(unique(begin(haters), end(haters)) - begin(haters));

  vector<vector<int>> components;
  for (int i = 0; i < n; i++) if (D.Find(i) == i && D.ComponentSize(i) > 1) {
    components.emplace_back();
    for (int j = 0; j < n; j++) {
      if (D.Find(i) == D.Find(j)) {
        components.back().emplace_back(j);
      }
    }
  }

  vector<int> events(n + 2);
  for (int i = 0; i < n; i++) {
    events[a[i].first] += 1;
    events[a[i].second + 1] -= 1;
  }

  vector<int> fact(n + 1);
  vector<int> inv(n + 1);
  fact[0] = inv[0] = 1;
  for (int i = 1; i <= n; i++) {
    fact[i] = 1ll * i * fact[i - 1] % MOD;
    inv[i] = Power(fact[i], MOD - 2);
  }

  auto C = [&](int n, int k) -> int {
    if (k < 0 || k > n) return 0;
    return 1ll * fact[n] * inv[k] % MOD * inv[n - k] % MOD;
  };
  vector<vector<vector<int>>> ways(components.size());
  for (int cid = 0; cid < (int) components.size(); cid++) {
    vector<int> &comp = components[cid];
    vector<vector<int>> &dp = ways[cid];
    int sz = comp.size();
    dp.assign(1 << sz, vector<int>(sz + 1, 0));

    vector<int> pos_in_comp(n, -1);
    for (int i = 0; i < sz; i++) {
      pos_in_comp[comp[i]] = i;
    }

    for (int mask = 0; mask < (1 << sz); mask++) {
      bool bad = false;
      for (int i = 0; i < m; i++) {
        int u = edges[i].first, v = edges[i].second;
        if (pos_in_comp[u] != -1 && (mask & (1 << pos_in_comp[u])) &&
            pos_in_comp[v] != -1 && (mask & (1 << pos_in_comp[v]))) {
          bad = true;
          break;
        }
      }
      if (!bad) {
        dp[mask][__builtin_popcount(mask)] = 1;
      }
    }
    for (int bit = 0; bit < sz; bit++) { // DP SoS
      for (int mask = 0; mask < (1 << sz); mask++) {
        for (int on = 0; on <= sz; on++) {
          if (mask & (1 << bit)) {
            dp[mask][on] += dp[mask ^ (1 << bit)][on];
            if (dp[mask][on] >= MOD) {
              dp[mask][on] -= MOD;
            }
          }
        }
      }
    }
  }
  
  int ans = 0;
  long long haters_mask = 0;
  vector<int> pos_in_haters(n, -1);
  for (int i = 0; i < (int) haters.size(); i++) {
    pos_in_haters[haters[i]] = i;
  }
  for (int pick = 1, active = 0; pick <= n; pick++) {
    active += events[pick];
    for (int i = 0; i < (int) haters.size(); i++) {
      if (a[haters[i]].first == pick || a[haters[i]].second + 1 == pick) {
        haters_mask ^= 1ll << i;
      }
    }

    vector<int> dp(2 * m + 1); // knapsack
    dp[0] = 1;
    int incomp = 0;

    for (int cid = 0; cid < (int) components.size(); cid++) {
      int mask = 0;
      for (int c = 0; c < (int) components[cid].size(); c++) {
        if (haters_mask & (1ll << pos_in_haters[components[cid][c]])) {
          mask |= 1 << c;
        }
      }
      incomp += __builtin_popcount(mask);
      for (int i = 2 * m; i >= 0; i--) {
        for (int j = 1; j < (int) ways[cid][mask].size(); j++) {
          if (i + j <= 2 * m) {
            dp[i + j] += 1ll * dp[i] * ways[cid][mask][j] % MOD;
            if (dp[i + j] >= MOD) {
              dp[i + j] -= MOD;
            }
          }
        }
      }
    }

    for (int i = 0; i <= 2 * m; i++) {
      ans += 1ll * dp[i] * C(active - incomp, pick - i) % MOD;
      if (ans >= MOD) {
        ans -= MOD;
      }
    }
  }

  cout << ans << "\n";
  return 0;
}
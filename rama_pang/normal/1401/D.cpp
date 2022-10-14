#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<vector<int>> adj(n);
    for (int i = 0; i + 1 < n; i++) {
      int u, v;
      cin >> u >> v;
      u--, v--;
      adj[u].emplace_back(v);
      adj[v].emplace_back(u);
    }
    int m;
    cin >> m;
    vector<int> p(m);
    for (int i = 0; i < m; i++) {
      cin >> p[i];
    }
    sort(begin(p), end(p), greater<int>());
    int big = 1;
    if (m >= n - 1) big = m - (n - 1) + 1;
    vector<long long> mul;
    vector<int> sz(n);
    function<void(int, int)> Dfs = [&](int u, int p) {
      sz[u] = 1;
      for (auto v : adj[u]) if (v != p) {
        Dfs(v, u);
        sz[u] += sz[v];
      }
      if (p != -1) {
        mul.emplace_back(1ll * sz[u] * (n - sz[u]));
      }
    };
    Dfs(0, -1);
    sort(begin(mul), end(mul), greater<long long>());
    long long ans = 0;
    long long bigmul = 1;
    const int MOD = 1e9 + 7;
    for (int i = 0; i < big; i++) {
      bigmul *= p[i];
      bigmul %= MOD;
    }
    ans += bigmul * (mul[0] % MOD) % MOD;
    for (int i = 1; i < (int) mul.size(); i++) {
      ans += 1ll * (big + i - 1 < m ? p[big + i - 1] : 1) * (mul[i] % MOD) % MOD;
    }
    ans %= MOD;
    cout << ans << "\n";
  }
  return 0;
}
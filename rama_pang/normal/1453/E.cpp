#include <bits/stdc++.h>
using namespace std;

using lint = long long;
const lint MOD = 1e9 + 7;

lint Power(lint n, lint x) {
  lint res = 1;
  for (; x > 0; x /= 2, n = 1ll * n * n % MOD) {
    if (x & 1) {
      res = 1ll * res * n % MOD;
    }
  }
  return res;
}

void Main() {
  int n;
  cin >> n;
  vector<vector<int>> adj(n);
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    adj[u].emplace_back(v);
    adj[v].emplace_back(u);
  }

  int ans = 0;
  const auto Dfs = [&](const auto &self, int u, int p) -> int {
    vector<int> leaf;
    for (auto &v : adj[u]) if (v != p) {
      int x = self(self, v, u);
      leaf.emplace_back(x);
    }
    if (leaf.empty()) {
      return 1;
    }
    sort(begin(leaf), end(leaf));
    if (leaf.size() > 1) {
      if (u == 0) {
        ans = max(ans, leaf.back());
        ans = max(ans, leaf[int(leaf.size()) - 2] + 1);
      } else {
        ans = max(ans, leaf.back() + 1);
      }
    } else {
      ans = max(ans, leaf[0]);
    }
    return leaf[0] + 1;
  };
  
  Dfs(Dfs, 0, -1);
  cout << ans << '\n';
  return;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int T = 1;
  cin >> T;
  while (T--) {
    Main();
  }
  return 0;
}
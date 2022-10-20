#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif

void Solve(int test) {
  int n, k;
  cin >> n >> k;
  // n = 200000;
  // k = 1000000000;
  vector<vector<int>> adj(n);
  for (int i = 1; i < n; i++) {
    int u;
    cin >> u;
    u--;
    // u = rand() % i;
    adj[u].push_back(i);
  }
  vector<int> s(n);
  for (auto &u : s) {
    cin >> u;
    // u = rand() % 10000;
  }
  map<pair<int, int>, long long> mem;
  function<long long(int, int)> Dfs = [&](int u, int k) -> long long {
    if (!k) return 0ll;
    if (mem.count({u, k})) return mem[{u, k}];
    long long res = 1ll * s[u] * k;
    if (adj[u].empty()) {
      return mem[{u, k}] = res;
    }
    auto kk = k / adj[u].size();
    vector<long long> delta;
    int num = k % adj[u].size();
    for (auto v : adj[u]) {
      auto base = Dfs(v, kk);
      res += base;
      if (num) {
        auto add = Dfs(v, kk + 1);
        delta.push_back(add - base);
      }
    }
    sort(delta.rbegin(), delta.rend());
    for (int i = 0; i < num; i++) {
      res += delta[i];
    }
    return mem[{u, k}] = res;
  };

  cout << Dfs(0, k) << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int tc;
  cin >> tc;
  for (int test = 1; test <= tc; ++test) Solve(test);
  return 0;
}
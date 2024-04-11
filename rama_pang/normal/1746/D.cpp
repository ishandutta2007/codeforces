#include <bits/stdc++.h>
using namespace std;

void Main() {
  int n, k;
  cin >> n >> k;
  vector<int> p(n);
  vector<vector<int>> adj(n);
  for (int i = 1; i < n; i++) {
    cin >> p[i];
    p[i]--;
    adj[p[i]].emplace_back(i);
  }  
  vector<int> a(n);
  for (auto &i : a) cin >> i;
  map<pair<int, int>, long long> memo;
  const auto Dfs = [&](const auto &self, int u, int paths) {
    if (adj[u].empty()) {      
      return 1ll * a[u] * paths;
    }
    if (memo.count({u, paths})) {
      return memo[{u, paths}];
    }
    long long ret = 1ll * a[u] * paths;
    int cnt = paths / adj[u].size();
    int extra = paths % adj[u].size();
    if (extra == 0) {
      for (auto v : adj[u]) {
        ret += self(self, v, cnt);
      }
    } else {
      vector<long long> buff;
      for (auto v : adj[u]) {
        ret += self(self, v, cnt);
        buff.emplace_back(self(self, v, cnt + 1) - self(self, v, cnt));
      }
      sort(begin(buff), end(buff));
      reverse(begin(buff), end(buff));
      for (auto x : buff) {
        if (extra > 0) {
          extra--;
          ret += x;
        }
      }
    }
    return memo[{u, paths}] = ret;
  };
  cout << Dfs(Dfs, 0, k) << '\n';
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  int T = 1;
  cin >> T;
  while (T--) {
    Main();
  }
}
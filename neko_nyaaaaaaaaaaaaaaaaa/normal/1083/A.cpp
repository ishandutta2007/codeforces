#include <bits/stdc++.h>
using namespace std;

#define int long long

int n, ans;
vector<pair<int, int>> adj[300001];
vector<int> a(300001);

int dfs(int now, int prev) {
      int mx = a[now];
      int tmp = a[now];

      vector<int> paths;
      for (auto u: adj[now]) {
            if (u.first != prev) {
                  paths.push_back(max(0LL, dfs(u.first, now) - u.second));
            }
      }

      sort(paths.begin(), paths.end());

      if (paths.size()) {
            mx += paths.back();
            tmp += paths.back();
            paths.pop_back();
      }
      if (paths.size()) {
            tmp += paths.back();
      }

      ans = max(ans, tmp);
      return mx;
}

signed main() {
      ios::sync_with_stdio(0); cin.tie(0);

      cin >> n;
      for (int i = 1; i <= n; i++) {
            cin >> a[i];
            ans = max(ans, a[i]);
      }
      for (int i = 1; i < n; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
      }

      dfs(1, 0);
      cout << ans;

      return 0;
}
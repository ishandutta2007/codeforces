#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, m, w;
vector<int> p(1002);
vector<int> b(1002);

vector<vector<int>> adj(1002);
vector<int> vis(1002);

vector<vector<pair<int, int>>> s(1002);

void dfs(int now, int &cc, int &wtot, int &btot) {
      vis[now] = cc;
      s[cc].push_back({p[now], b[now]});
      wtot += p[now]; btot += b[now];

      for (auto u: adj[now]) {
            if (!vis[u]) dfs(u, cc, wtot, btot);
      }
}

signed main() {
      ios::sync_with_stdio(0); cin.tie(0);

      cin >> n >> m >> w;
      for (int i = 1; i <= n; i++) cin >> p[i];
      for (int i = 1; i <= n; i++) cin >> b[i];
      while (m--) {
            int x, y; cin >> x >> y;
            adj[x].push_back(y);
            adj[y].push_back(x);
      }
      int cc = 1;
      for (int i = 1; i <= n; i++) {
            if (!vis[i]) {
                  int wtot = 0, btot = 0;
                  dfs(i, cc, wtot, btot);
                  s[cc].push_back({wtot, btot});
                  cc++;
            }
      }

      vector<int> dp(1002);
      for (int i = 1; i < cc; i++) {
            for (int j = w; j >= 0; j--) {
                  for (auto u: s[i]) {
                        if (u.first > j) continue;
                        dp[j] = max(dp[j], dp[j - u.first] + u.second);
                  }
            }
      }
      cout << dp[w];

      return 0;
}
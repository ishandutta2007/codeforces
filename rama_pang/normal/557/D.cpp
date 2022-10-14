#include <bits/stdc++.h>
using namespace std;
using lint = long long;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int n, m;
  cin >> n >> m;
  vector<vector<int>> adj(n);
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    adj[u].emplace_back(v);
    adj[v].emplace_back(u);
  }

  vector<int> vis(n, -1); // color
  int one = 0, two = 0;
  vector<pair<int, int>> more;
  for (int i = 0; i < n; i++) {
    if (vis[i] == -1) {
      queue<int> q;
      q.emplace(i);
      vis[i] = 0;
      int cnt = 0;
      int b = 0, w = 0;
      while(!q.empty()) {
        int u = q.front();
        q.pop();
        cnt++;
        if (vis[u] == 0) {
          w++;
        } else {
          b++;
        }
        for (auto v : adj[u]) {
          if (vis[v] != -1 && vis[v] == vis[u]) {
            cout << 0 << " " << 1 << "\n";
            return 0;
          }
          if (vis[v] == -1) {
            vis[v] = (vis[u] ^ 1);
            q.emplace(v);
          }
        }
      }
      if (cnt == 1) {
        one++;
      } else if (cnt == 2) {
        two++;
      } else {
        more.emplace_back(b, w);
      }
    }
  }

  if (!more.empty()) { // 1
    lint ans = 0;
    for (auto i : more) {
      ans += 1ll * i.first * (i.first - 1) / 2;
      ans += 1ll * i.second * (i.second - 1) / 2;
    }
    cout << 1 << " " << ans << "\n";
  } else if (two > 0) { // 2
    lint ans = 0;
    ans += 1ll * one * two;
    ans += 2ll * two * (two - 1);
    cout << 2 << " " << ans << "\n";
  } else { // 3
    lint ans = 0;
    ans += 1ll * one * (one - 1) * (one - 2) / 6;
    cout << 3 << " " << ans << "\n";
  }
  return 0;
}
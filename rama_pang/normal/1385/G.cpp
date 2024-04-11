#include <bits/stdc++.h>
using namespace std;
using lint = long long;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> cnt(n);
    vector<int> a(n);
    vector<int> b(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      a[i]--;
      cnt[a[i]]++;
    }
    for (int i = 0; i < n; i++) {
      cin >> b[i];
      b[i]--;
      cnt[b[i]]++;
    }
    if (cnt != vector<int>(n, 2)) {
      cout << -1 << "\n";
      continue;
    }
    cnt.assign(n, 0);
    vector<vector<pair<int, int>>> adj(n), radj(n);
    for (int i = 0; i < n; i++) {
      cnt[a[i]]++;
      adj[a[i]].emplace_back(b[i], i);
      radj[b[i]].emplace_back(a[i], i);
    }

    vector<vector<int>> op(2);
    vector<int> ans;
    vector<int> vis(n);
    function<void(int, int, int, int, int)> Dfs = [&](int st, int p, int u, int rev, int cur) {
      vis[u] = 1;
      if (rev) {
        if (u == st) {
          return;
        } else if (cnt[u] == 2) {
          return Dfs(st, p, u, 0, cur ^ 1);
        } else {
          for (auto v : radj[u]) if (v.second != p) {
            op[cur].emplace_back(v.second);
            Dfs(st, v.second, v.first, rev, cur);
          }
        }
      } else {
        if (cnt[u] == 0) {
          return Dfs(st, p, u, 1, cur ^ 1);
        } else if (u == st) {
          op[0].emplace_back(adj[u][0].second);
          Dfs(st, adj[u][0].second, adj[u][0].first, 0, 0);
        } else {
          for (auto v : adj[u]) if (v.second != p) {
            op[cur].emplace_back(v.second);
            Dfs(st, v.second, v.first, rev, cur);
          }
        }
      }
    };

    for (int i = 0; i < n; i++) {
      if (vis[i] == 0 && cnt[i] == 2) {
        Dfs(i, -1, i, 0, 0);
        if (op[0].size() > op[1].size()) {
          swap(op[0], op[1]);
        }
        for (auto j : op[0]) {
          ans.emplace_back(j);
        }
        op[0].clear();
        op[1].clear();
      }
    }

    sort(begin(ans), end(ans));
    cout << ans.size() << "\n";
    for (auto i : ans) {
      cout << i + 1 << " ";
    }
    cout << "\n";
  }  
  return 0;
}
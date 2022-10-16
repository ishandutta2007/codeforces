#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, m;
vector<pair<int, int>> adj[100001];
vector<int> a(100001);
vector<int> x(100001), y(100001);
vector<int> vis(100001);
vector<int> c1(100001);
vector<int> c2(100001);

void input() {
      cin >> n >> m;
      for (int i = 1; i <= n; i++) {
            cin >> a[i]; a[i] ^= 1;
      }
      for (int i = 1; i <= m; i++) {
            int k; cin >> k;
            while (k--) {
                  int u; cin >> u;
                  if (x[u]) y[u] = i;
                  else x[u] = i;
            }
      }
      for (int i = 1; i <= n; i++) {
            adj[x[i]].push_back({y[i], a[i]});
            adj[y[i]].push_back({x[i], a[i]});
      }
}

void dfs1(int now, int col) {
      vis[now] = 1; c1[now] = col;
      for (auto u: adj[now]) {
            if (!vis[u.first]) {
                  dfs1(u.first, col^u.second);
            }
      }
}

void dfs2(int now, int col) {
      vis[now] = 2; c2[now] = col;
      for (auto u: adj[now]) {
            if (vis[u.first] == 1) {
                  dfs2(u.first, col^u.second);
            }
      }
}

void solve() {
      for (int i = 1; i <= m; i++) {
            if (!vis[i]) {
                  dfs1(i, 1);
                  dfs2(i, 0);
            }
      }

      for (int i = 1; i <= n; i++) {
            if (c1[x[i]] ^ c1[y[i]] == a[i]) continue;
            if (c2[x[i]] ^ c2[y[i]] == a[i]) continue;
            cout << "NO"; exit(0);
      }
      cout << "YES";
}

signed main() {
      ios::sync_with_stdio(0); cin.tie(0);

      input();
      solve();

      return 0;
}
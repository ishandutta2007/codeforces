#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, ans;
vector<int> adj[200005];
vector<int> deg(200005);
vector<int> col(200005);

void dfs(int now, int prev) {
      int c = 0;
      for (auto u: adj[now]) {
            if (u != prev) {
                  c++;
                  while (c == col[now] || c == col[prev]) c++;
                  col[u] = c;
            }
      }
      for (auto u: adj[now]) {
            if (u != prev) dfs(u, now);
      }
}

int main() {
      ios::sync_with_stdio(0); cin.tie(0);

      cin >> n;
      for (int i = 1; i < n; i++) {
            int x, y; cin >> x >> y;
            deg[x]++; deg[y]++;
            ans = max(ans, max(deg[x] + 1, deg[y] + 1));
            adj[x].push_back(y);
            adj[y].push_back(x);
      }
      cout << ans << '\n';

      col[1] = 1;
      dfs(1, 0);

      for (int i = 1; i <= n; i++) {
            cout << col[i] << " ";
      }

      return 0;
}
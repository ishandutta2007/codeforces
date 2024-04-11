#include <bits/stdc++.h>
using namespace std;

#define int long long
vector<int> adj[100002];
int n, s, ans;

void dfs(int now, int prev) {
      if (adj[now].size() == 1) ans++;
      for (int u: adj[now]) {
            if (u != prev) dfs(u, now);
      }
}

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);

      cin >> n >> s;
      for (int i = 1; i < n; i++) {
            int x, y; cin >> x >> y;
            adj[x].push_back(y);
            adj[y].push_back(x);
      }
      dfs(1, 0);

      cout << fixed << setprecision(12) << (2.0*s)/ans;

	return 0;
}
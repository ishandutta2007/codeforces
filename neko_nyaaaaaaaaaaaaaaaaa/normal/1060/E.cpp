#include <bits/stdc++.h>
using namespace std;

#define int long long

int n, ans, o, e;
vector<vector<int>> adj(200008);
vector<int> subtr(200008, 1);

void dfs(int now, int prev, int d = 0) {
      if (d) o++;
      else e++;
      for (int u: adj[now]) {
            if (u != prev) {
                  dfs(u, now, d^1);
                  subtr[now] += subtr[u];
            }
      }
      ans += subtr[now] * (n - subtr[now]);
}

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);

      cin >> n;
      if (n == 1) {cout << 0; return 0;}
      for (int i = 1; i < n; i++) {
            int x, y; cin >> x >> y;
            adj[x].push_back(y);
            adj[y].push_back(x);
      }
      dfs(1, 0);

      cout << (ans + o*e)/2;

	return 0;
}
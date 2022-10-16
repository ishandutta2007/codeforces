#include <bits/stdc++.h>
using namespace std;

#define int long long

int n, m, cc = 0, mx = 0, o, z;
vector<int> adj[100005];
vector<int> sz(100005);
vector<int> par(100005);

void dfs(int now, int pr) {
      cc++;
      if (pr) o++;
      else z++;
      mx = max(mx, cc);
      par[now] = pr;
      sz[now] = cc;
      for (auto u: adj[now]) {
            if (!sz[u]) {
                  dfs(u, pr^1);
            } else {
                  if (par[u] == par[now]) {cout << "0 1"; exit(0);}
            }
      }
}

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);

      cin >> n >> m;
      for (int i = 0; i < m; i++) {
            int x, y; cin >> x >> y;
            adj[x].push_back(y);
            adj[y].push_back(x);
      }
      for (int i = 1; i <= n; i++) {
            if (!sz[i]) {
                  cc = 0;
                  dfs(i, 0);
            }
      }
      if (mx == 1) {
            int ans = 0;
            ans = n*(n-1)*(n-2)/6;
            cout << "3 " << ans;
            return 0;
      } else if (mx == 2) {
            int ans = 0;
            cout << "2 ";
            for (int i = 1; i <= n; i++) {
                  if (sz[i] == 2) ans += n-2;
            }
            cout << ans;
      } else {
            cout << "1 ";
            for (int i = 1; i <= n; i++) {
                  sz[i] = par[i] = 0;
            }
            int ans = 0;
            for (int i = 1; i <= n; i++) {
                  if (!sz[i]) {
                        cc = o = z = 0;
                        dfs(i, 0);
                        ans += o*(o-1)/2;
                        ans += z*(z-1)/2;
                  }
            }
            cout << ans;
      }

	return 0;
}
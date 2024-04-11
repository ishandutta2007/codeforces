#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, m, cc;
set<int> v;
vector<set<int>> adj(300008);

void dfs(int now) {
      vector<int> tmp;
      for (int u: v) {
            if (adj[now].find(u) == adj[now].end()) {
                  tmp.push_back(u);
                  cc++;
            }
      }
      for (int u: tmp) v.erase(u);
      for (int u: tmp) dfs(u);
}

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);

      cin >> n >> m;
      for (int i = 0; i < m; i++) {
            int x, y; cin >> x >> y;
            adj[x].insert(y);
            adj[y].insert(x);
      }
      for (int i = 1; i <= n; i++) {
            v.insert(i);
      }
      vector<int> ans;
      for (int i = 1; i <= n; i++) {
            if (v.find(i) != v.end()) {
                  v.erase(i);
                  cc = 1;
                  dfs(i);
                  ans.push_back(cc);
            }
      }
      cout << ans.size() << '\n';
      sort(ans.begin(), ans.end());
      
      for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
      }

	return 0;
}
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, m, k;
set<int> v;
vector<set<int>> adj(300008);

void dfs(int now) {
      vector<int> tmp;
      for (int u: v) if (adj[now].find(u) == adj[now].end()) tmp.push_back(u);
      for (int u: tmp) v.erase(u);
      for (int u: tmp) dfs(u);
}

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);

      cin >> n >> m >> k;
      int deg1 = 0;
      for (int i = 0; i < m; i++) {
            int x, y; cin >> x >> y;
            adj[x].insert(y);
            adj[y].insert(x);
            if (x == 1 || y == 1) deg1++;
      }
      for (int i = 2; i <= n; i++) {
            v.insert(i);
      }
      dfs(1);
      if (v.size()) {cout << "impossible"; return 0;}

      int lo = 0;
      for (int i = 2; i <= n; i++) {
            v.insert(i);
      }
      for (int i = 2; i <= n; i++) {
            if (v.find(i) != v.end()) {v.erase(i); dfs(i); lo++;}
      }

      ll hi = n-1 - deg1;

      if (k >= lo && k <= hi) {cout << "possible";}
      else {cout << "impossible";}

	return 0;
}
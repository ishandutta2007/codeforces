#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, root = 1;
vector<int> parent(100005);
vector<int> level(100005);
vector<vector<int>> sp(100005, vector<int>(22, -1));
vector<int> pref(100005);
vector<vector<int>> adj(100005);
vector<pair<int, int>> edge;
map<pair<int, int>, int> ans;

void dfs(int now, int prev) {
	level[now] = level[prev] + 1;
	parent[now] = prev;

	for (auto u: adj[now]) {
		if (u != prev) {
			dfs(u, now);
		}
	}
}

void LCAinit() {
      for(int i = 1; i <= n; i++){
            sp[i][0] = parent[i] ;
      }

      for (int j = 1; (1 << j) < n; j++) {
            for (int i = 1; i <= n; i++) {
                 if(sp[i][j-1] != -1){
                        sp[i][j] = sp[sp[i][j-1]][j-1];
                  }
            }
      }
}

int LCA(int u, int v) {
      if (level[u] < level[v]) {
            swap(u, v);
      }

      int dist = level[u] - level[v] ;
      while(dist > 0){
            int raise_by = log2(dist);
            u = sp[u][raise_by];
            dist -= (1 << raise_by) ;
      }
      if(u == v) return u;

      for (int j = 20; j >= 0; j--) {
            if (sp[u][j] != -1 && sp[u][j] != sp[v][j]) {
                  u = sp[u][j];
                  v = sp[v][j];
            }
      }

      return parent[u];
}

void dfs2(int now, int prev) {
	for (auto u: adj[now]) {
		if (u != prev) {
			dfs2(u, now);
			pref[now] += pref[u];
		}
	}
	ans[{min(now, prev), max(now, prev)}] = pref[now];
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	cin >> n;
	for (int i = 1; i < n; i++) {
		int x, y; cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
		edge.push_back({min(x, y), max(x, y)});
	}
	dfs(1, 0);
	LCAinit();
	
	int q; cin >> q;
	while (q--) {
		int a, b;
		cin >> a >> b;
		
		int lca = LCA(a, b);
		pref[a]++; pref[b]++; pref[lca] -= 2;
	}
	dfs2(1, 0);
	
	for (int i = 0; i < n-1; i++) {
		cout << ans[edge[i]] << ' ';
	}
	
	return 0;
}
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, m, k, root = 1;
ll MST = 0;
vector<int> parent(200005);
vector<int> sz(200005, 1);
vector<vector<pair<int, int>>> adj(200005);

vector<int> level(200005);
vector<vector<int>> sp(200005, vector<int>(20, -1));  // sparse table
vector<vector<int>> mx(200005, vector<int>(20, -1)); 

void DSUinit(int n) {
	for (int i = 1; i <= n; i++) {
      	parent[i] = i;
	}
}

int find(int x) {
	while (x != parent[x]) {x = parent[x];}
	return x;
}

bool same(int a, int b) {
	return (find(a) == find(b));
}

void merge(int a, int b) {
	a = find(a);
	b = find(b);
	if (sz[a] < sz[b]) {swap(a, b);}
	sz[a] += sz[b];
	parent[b] = a;
}

void dfs(int now) {
	for (auto u: adj[now]) {
		int v = u.first, w = u.second;
		if (v != sp[now][0]) {
			sp[v][0] = now; level[v] = level[now] + 1;
			mx[v][0] = w;
			dfs(v);
		}
	}
}

void LCAinit() {
	for (int j = 1; (1 << j) < n; j++) {
            for (int i = 1; i <= n; i++) {
            	if(sp[i][j-1] != -1){
                        sp[i][j] = sp[sp[i][j-1]][j-1];
                        mx[i][j] = max(mx[i][j-1], mx[sp[i][j-1]][j-1]);
                  }
            }
      }
}

void query(int u, int v, int w) {
	if (level[u] < level[v]) {
            swap(u, v);
      }
      int wmax = INT_MIN;
      
      int lg = log2(level[u]);
      for(int i = lg; i >= 0; i--) {
		if(level[u] - (1 << i) >= level[v]) {
			wmax = max(wmax, mx[u][i]);
			u = sp[u][i];
		}
	}
	
      if (u != v) {
      	for (int j = lg; j >= 0; j--) {
            	if (sp[u][j] != sp[v][j]) {
				wmax = max(wmax, max(mx[u][j], mx[v][j]));
	                  u = sp[u][j];
	                  v = sp[v][j];
            	}
      	}
		wmax = max(wmax, max(mx[u][0], mx[v][0]));
      }
      
	cout << MST + w - wmax << "\n";
}

signed main() {
	//ios::sync_with_stdio(0);
	
	// inputting
	cin >> n >> m;
	int x, y, w;
	vector<vector<int>> e(m, vector<int>(3));
	for (int i = 0; i < m; i++) {
		cin >> e[i][2] >> e[i][1] >> e[i][0];
	}

	vector<vector<int>> tmp = e;
	sort(e.begin(), e.end());
	DSUinit(n);
	for (int i = 0; i < m; i++) {
		if (!same(e[i][1], e[i][2])) {
			MST += e[i][0];
			int u = e[i][1], v = e[i][2], w = e[i][0];
			merge(u, v);
			adj[u].push_back({v, w});
			adj[v].push_back({u, w});
		}
	}
	
	// initializing
	dfs(1);
	LCAinit();

	// querying
	e = tmp;
	for (int i = 0; i < m; i++) {
		query(e[i][1], e[i][2], e[i][0]);
	}
	
	return 0;
}
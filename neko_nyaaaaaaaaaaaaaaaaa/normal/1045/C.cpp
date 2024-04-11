#include <bits/stdc++.h>
using namespace std;
 
int n, m, q;
vector<vector<int>> adj(100007);
vector<vector<int>> bcc;
vector<int> CriticalNode(100007);
vector<int> num(100007), low(100007);
stack<int> st;
int t = 1;
 
vector<int> id(200007);
vector<vector<int>> bct(200007);
 
void dfs(int now, int prev) {
	low[now] = num[now] = t++;
	st.push(now);
 
	for (int u: adj[now]) {
		if (u != prev) {
			if (num[u]) low[now] = min(low[now], num[u]);
			else {
				dfs(u, now);
				low[now] = min(low[now], low[u]);
 
				if (low[u] >= num[now]) {
					CriticalNode[now] = (num[now] > 1 || num[u] > 2);
 
					bcc.push_back({now});
					while (bcc.back().back() != u) {
						bcc.back().push_back(st.top()); 
						st.pop();
					}
				}
			}
		}
	}
}
 
void build_bct() {
	t = 0;
	for (int i = 1; i <= n; i++) {
		if (CriticalNode[i]) {
			id[i] = ++t;
		}
	}
 
	for (auto bc: bcc) {
		t++;
		for (int u: bc) {
			if (CriticalNode[u]) {
				bct[id[u]].push_back(t);
				bct[t].push_back(id[u]);
			} else {
				id[u] = t;
			}
		}
	}
}
 
int par[200001], level[200001];
int sp[200001][19];
 
void dfs_bct(int now, int prev) {
	par[now] = prev;
	level[now] = level[prev] + 1;
	for (int u: bct[now]) {
		if (u != prev) dfs_bct(u, now);
	}
}
 
void LCAinit() {
	memset(sp, -1, sizeof(sp));
 
	for(int i = 1; i <= t; i++){
		sp[i][0] = par[i];
	}
 
	for (int j = 1; j < 19; j++) {
		for (int i = 1; i <= t; i++) {
			if(sp[i][j-1] != -1) {
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
 
	for (int j = 17; j >= 0; j--) {
		if (sp[u][j] != -1 && sp[u][j] != sp[v][j]) {
			u = sp[u][j];
			v = sp[v][j];
		}
	}
 
	return par[u];
}
 
int dist(int u, int v) {
	return level[u] + level[v] - 2*level[LCA(u, v)];
}
 
signed main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> m >> q;
	for (int i = 0; i < m; i++) {
		int x, y; cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	dfs(1, 1);
	build_bct();
	dfs_bct(1, 0);
	LCAinit();
 
	while (q--) {
		int c, d; cin >> c >> d;
		if (id[c] == id[d]) {
			cout << "1\n";
		} else {
			int ans = dist(id[c], id[d]);
			if (CriticalNode[c]) ans--;
			if (CriticalNode[d]) ans--;
			
			cout << ans/2 + 1 << '\n';
		}
	}
 
	return 0;
}
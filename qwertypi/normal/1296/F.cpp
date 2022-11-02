#include <bits/stdc++.h>
 
using namespace std;
 
vector<vector<pair<int, int>>> G(5001);
// lmao laughed this is not even 1700 for n <= 10^5, only 1500
int p[5001], e[5001], dep[5001], g[5001];
int ans[5001];
void dfs(int v = 0, int par = -1){
	for(auto i : G[v]){
		int u = i.first, id = i.second;
		if(u != par){
			dep[u] = dep[v] + 1;
			dfs(u, v);
			p[u] = v;
			e[u] = id;
		}
	}
}
 
vector<pair<int, int>> E;
vector<pair<pair<int, int>, int>> Q;
int lca(int a, int b){
	if(dep[a] < dep[b]) swap(a, b);
	while(dep[a] > dep[b]) a = p[a];
	while(a != b) a = p[a], b = p[b];
	return a;
}
 
int main(){
	int n;
	cin >> n;
	for(int i = 0; i < n - 1; i++){
		int u, v; 
		cin >> u >> v;
		u--; v--;
		G[u].push_back({v, i});
		G[v].push_back({u, i});
	}
	dfs(0);
	int m;
	cin >> m; 
	for(int i = 0; i < m; i++){
		int a, b, good;
		cin >> a >> b >> good;
		a--; b--;
		Q.push_back({{a, b}, good});
		int l = lca(a, b);
		while(a != l){
			g[a] = max(g[a], good);
			a = p[a];
		}
		while(b != l){
			g[b] = max(g[b], good);
			b = p[b];
		}
	}
	for(int i = 0; i < n - 1; i++){
		ans[i] = 1;
	}
	for(int i = 0; i < m; i++){
		int a, b, good;
		a = Q[i].first.first, b = Q[i].first.second, good = Q[i].second;
		int m = (1 << 30);
		int l = lca(a, b);
		while(a != l){
			m = min(m, g[a]);
			a = p[a];
		}
		while(b != l){
			m = min(m, g[b]);
			b = p[b];
		}
		if(m != good){
			cout << -1 << endl;
			return 0;
		}
	}
	
	for(int i = 1; i < n; i++){
		ans[e[i]] = max(ans[e[i]], g[i]);
	}
	
	for(int i = 0; i < n - 1; i++){
		cout << ans[i] << ' ';
	}
	cout << endl;
}
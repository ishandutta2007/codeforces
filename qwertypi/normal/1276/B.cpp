#include <bits/stdc++.h>
#define int long long
using namespace std;
 
vector<vector<int>> G(200001);
bool vis[200001], bk[200001];
int T1[200001], T2[200001];
 
void dfs(int u){
	vis[u] = true;
	for(auto v : G[u]){
		if(!vis[v] && !bk[v]){
			dfs(v);
		}
	}
}
 
void solve(){
	int n, m, a, b;
	cin >> n >> m >> a >> b;
	for(int i = 1; i <= n; i++){
		G[i].clear();
	}
	for(int i = 0; i < m; i++){
		int u, v;
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	int a1 = 0, a2 = 0;
	bk[a] = true;
	fill(vis, vis + n + 1, false);
	dfs(b);
	for(int i = 1; i <= n; i++){
		if(!vis[i] && i != a){
			a1++; T1[i] = true;
		}
	}
	bk[a] = false;
	bk[b] = true;
	fill(vis, vis + n + 1, false);
	dfs(a);
	for(int i = 1; i <= n; i++){
		if(!vis[i] && i != b){
			a2++; T2[i] = true;
		}
	}
	bk[b] = false;
	cout << a1 * a2 << endl;
}
 
signed main(){
	int t = 1;
	cin >> t;
	while(t--){
		solve();
	}
}
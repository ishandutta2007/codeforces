#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> G(100001);
int a[100001];
int w[100001];
int par[100001];
void dfs(int u, int p = -1){
	int deg = 0;
	for(auto v : G[u]){
		deg++;
		if(v != p){
			par[v] = -par[u];
			dfs(v, u);
		}
	}
	a[u] = deg * par[u];
}

void solve(){
	int n;
	cin >> n;
	par[1] = 1;
	for(int i = 0; i <= n; i++) G[i].clear();
	for(int i = 0; i < n - 1; i++){
		int u, v; cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	dfs(1);
	for(int i = 1; i <= n; i++){
		cout << a[i] << ' ';
	}
	cout << endl;
}

int main(){
	int t;
	cin >> t;
	while(t--){
		solve();
	}
}
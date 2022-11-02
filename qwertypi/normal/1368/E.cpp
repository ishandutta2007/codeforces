#include <bits/stdc++.h>
#define int long long
using namespace std;
 
vector<vector<int>> G(200001);
int dp[200001];
vector<bool> visited;
vector<int> tp;
vector<int> V; 
 int n, m;
void dfs(int v) {
    visited[v] = true;
    for (int u : G[v]) {
        if (!visited[u])
            dfs(u);
    }
    tp.push_back(v);
}
 
void topological_sort() {
    for (int i = 1; i <= n; i++) {
        if (!visited[i])
            dfs(i);
    }
    reverse(tp.begin(), tp.end());
}
 
void sub(){
	cin >> n >> m;
    visited.assign(n + 1, false);
    tp.clear();
	for(int i = 1; i <= n; i++){
		G[i].clear();
		dp[i] = 0;
	}
	V.clear();
	for(int i = 0; i < m; i++){
		int a, b;
		cin >> a >> b;
		G[a].push_back(b);
	}
	topological_sort();
	for(int i = 0; i < n; i++){
		int v = dp[tp[i]];
		if(v >= 2){
			V.push_back(tp[i]);
			dp[tp[i]] = -1;
		}
		for(auto j : G[tp[i]]){
			dp[j] = max(dp[j], dp[tp[i]] + 1);
		}
	}
	
	cout << V.size() << endl; 
	for(auto i : V){
		cout << i << ' ';
	}
	cout << endl;
}
 
int32_t main(){
	int t;
	cin >> t;
	while(t--){
		sub();
	}
}
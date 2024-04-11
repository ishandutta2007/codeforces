#include <bits/stdc++.h>
#define int long long

using namespace std;
vector<vector<int>> G(50001);
int dp[50001][501];
int ans = 0;
int n, k;

void dfs(int v, int p = -1){
	dp[v][0]++;
	for(auto i : G[v]){
		if(i != p){
			dfs(i, v);
			for(int j = 1; j <= k; j++){
				ans += dp[v][k - j] * dp[i][j - 1];
			}
			for(int j = 0; j < k; j++){
				dp[v][j + 1] += dp[i][j];
			}
		}
	}
}

void solve(){
	cin >> n >> k;
	for(int i = 0; i < n - 1; i++){
		int u, v;
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	dfs(1);
	cout << ans << endl;
}

int32_t main(){
	int t = 1;
	// cin >> t;
	while(t--){
		solve();
	}
}
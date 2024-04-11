#include <bits/stdc++.h>
#define int long long
using namespace std;

int a[1001];
int to[1001];
int dp[1001][1001];
int s[1001];
vector<int> G[1001];

const int M = 998244353;

bool vis[1001];
vector<int> tp;
vector<int> tpi;
void dfs_tp(int v){
	vis[v] = true;
	for(auto i : G[v]){
		if(!vis[i])
			dfs_tp(i);
	}
	tp.push_back(v);
}

void solve(){
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < n; i++) G[i].clear();
	for(int i = 0; i < n; i++) cin >> a[i];
	for(int i = 0; i < m; i++){
		int u, v;
		cin >> u >> v;
		u--; v--;
		G[u].push_back(v);
	}
	
	int t = 0;
	for(t; t < n; t++){
		bool dead = true;
		fill(to, to + n, 0);
		for(int i = 0; i < n; i++){
			if(a[i]){
				to[i]--;
				dead = false;
				for(auto j : G[i]){
					to[j]++;
				}
			}
		}
		if(dead){
			cout << t << '\n';
			return;
		}
		for(int i = 0; i < n; i++){
			a[i] += to[i];
		}
	}
	tp.clear();
	fill(vis, vis + n, false);
	for(int i = 0; i < n; i++){
		if(!vis[i]){
			dfs_tp(i);
		}
	}
	reverse(tp.begin(), tp.end());
	tpi.clear(); tpi.resize(n);
	for(int i = 0; i < n; i++){
		tpi[tp[i]] = i;
	}
	for(int i = 0; i < n; i++)
		fill(dp[i] + 0, dp[i] + n, 0);
	for(int i = 0; i < n; i++){
		dp[i][i] = 1;
		for(int j = i; j < n; j++){
			for(auto k : G[tp[j]]){
				dp[i][tpi[k]] += dp[i][j];
				dp[i][tpi[k]] %= M;
			}
		}
	}
	for(int i = 0; i < n; i++){
		s[i] = 0;
	}
	for(int i = 0; i < n; i++){
		for(int j = n - 1; j < n; j++){
			s[j] += dp[i][j] * a[tp[i]];
		}
	}
	for(int i = 0; i < n; i++) s[i] %= M;
	
	cout << (t + s[n - 1]) % M << '\n';
}

int32_t main(){
	int t;
	cin >> t;
	while(t--){
		solve();
	}
}
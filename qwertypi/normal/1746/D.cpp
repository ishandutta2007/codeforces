#include <bits/stdc++.h>
#define int long long
using namespace std;

int p[200001];
int s[200001];
int c[200001];
int r[200001];
vector<int> G[200001];
int dp[200001][2];

int ans = 0;
void dfs1(int v){
	ans += c[v] * s[v];
	int d = G[v].size();
	for(auto j : G[v]){
		c[j] = c[v] / d;
		dfs1(j);
	}
	if(d != 0) r[v] = c[v] % d;
	else r[v] = 0;
}

void dfs(int v){
	for(auto i : G[v]){
		dfs(i);
	}
	vector<int> vi;
	for(auto i : G[v]){
		vi.push_back(s[i] + dp[i][1] - dp[i][0]);
	}
	sort(vi.begin(), vi.end(), [](int a, int b){
		return a > b;
	});
	int s = 0;
	for(auto i : G[v]){
		s += dp[i][0];
	}
	for(int i = 0; i < r[v]; i++){
		s += vi[i];
	}
	dp[v][0] = s;
	dp[v][1] = s + (G[v].size() == 0 ? 0 : vi[r[v]]);
}

void solve(){
	ans = 0;
	int n, k;
	cin >> n >> k;
	for(int i = 0; i < n; i++) G[i].clear();
	for(int i = 1; i < n; i++){
		cin >> p[i];
		p[i]--;
		G[p[i]].push_back(i);
	}
	
	for(int i = 0; i < n; i++) cin >> s[i];
	
	c[0] = k;
	dfs1(0);
	dfs(0);
	cout << ans + dp[0][0] << endl;
}

int32_t main(){
	int t;
	cin >> t;
	while(t--){
		solve();
	}
}
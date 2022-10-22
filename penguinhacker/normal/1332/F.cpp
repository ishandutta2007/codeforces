#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=3e5, MOD=998244353;
int n;
ll dp[mxN][3];
vector<int> adj[mxN];

void dfs(int u=0, int p=-1) {
	dp[u][0]=1;
	if (adj[u].size()==1&&u)
		return;
	dp[u][1]=dp[u][2]=1;
	ll mult=1;
	for (int v: adj[u]) if (v!=p) {
		dfs(v, u);
		ll sum=dp[v][0]+dp[v][1]+dp[v][2];
		mult=mult*sum%MOD;
		dp[u][0]=(dp[u][0]*sum)%MOD;
		dp[u][1]=(dp[u][1]*(sum+dp[v][0]*2+dp[v][1]+dp[v][2]))%MOD;
		dp[u][2]=(dp[u][2]*(sum+dp[v][0]+dp[v][1]))%MOD;
	}
	dp[u][1]=(dp[u][1]-mult+MOD)%MOD;
	dp[u][2]=(dp[u][2]-mult+MOD)%MOD;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i=1; i<n; ++i) {
		int a, b; cin >> a >> b, --a, --b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	dfs();
	cout << (dp[0][0]+dp[0][1]+dp[0][2]+MOD-1)%MOD << '\n';
	return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
*/
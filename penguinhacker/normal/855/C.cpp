#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=1e5, M=1e9+7;
int n, m, k, x;
ll dp[mxN][11][3], tmp[11][3], ans;
vector<int> adj[mxN];

void dfs(int u=0, int p=-1) {
	dp[u][0][0]=k-1;
	dp[u][1][1]=1;
	dp[u][0][2]=m-k;
	for (int v : adj[u]) {
		if (v==p)
			continue;
		dfs(v, u);
		for (int i=0; i<=x; ++i) {
			for (int j=0; j<=x-i; ++j) {
				tmp[i+j][0]+=dp[u][i][0]*(dp[v][j][0]+dp[v][j][1]+dp[v][j][2])%M;
				tmp[i+j][1]+=dp[u][i][1]*dp[v][j][0]%M;
				tmp[i+j][2]+=dp[u][i][2]*(dp[v][j][0]+dp[v][j][2])%M;
			}
		}
		for (int i=0; i<=x; ++i)
			for (int j=0; j<3; ++j)
				dp[u][i][j]=tmp[i][j]%M, tmp[i][j]=0;
	}
	/*for (int i=0; i<=x; ++i)
		for (int j=0; j<3; ++j)
			cout << u << " " << i << " " << j << " " << dp[u][i][j] << "\n";*/
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i=1; i<n; ++i) {
		int u, v;
		cin >> u >> v, --u, --v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	cin >> k >> x;
	dfs();
	for (int i=0; i<=x; ++i)
		for (int j=0; j<3; ++j)
			ans+=dp[0][i][j];
	cout << ans%M;
	return 0;
}
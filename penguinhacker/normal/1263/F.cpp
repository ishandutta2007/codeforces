#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=1000;
int n, a[2], l[2*mxN][2], c[mxN+1][mxN+1][2], dp[mxN+1][mxN+1];
vector<int> adj[2*mxN][2];

vector<ar<int, 2>> dfs(int u, int d, int t) {
	if (l[u][t]) {
		assert(adj[u][t].empty());
		c[0][l[u][t]][t]=d;
		return {{l[u][t], 0}};
	}
	assert(adj[u][t].size());
	vector<ar<int, 2>> lv;
	for (int v : adj[u][t]) {
		vector<ar<int, 2>> cur=dfs(v, d+1, t);
		for (ar<int, 2> x : cur)
			for (ar<int, 2> y : lv) {
				if (y[0]<x[0])
					c[y[0]][x[0]][t]=x[1]+1;
				else
					c[x[0]][y[0]][t]=y[1];
			}
		for (ar<int, 2> x : cur)
			lv.push_back({x[0], x[1]+1});
	}
	return lv;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int j : {0, 1}) {
		cin >> a[j];
		for (int i=1; i<a[j]; ++i) {
			int p;
			cin >> p, --p;
			adj[p][j].push_back(i);
		}
		for (int i=1; i<=n; ++i) {
			int x;
			cin >> x, --x;
			l[x][j]=i;
		}
		dfs(0, 0, j);
		/*for (int x=0; x<=n; ++x)
			for (int y=x+1; y<=n; ++y)
				cout << x << " " << y << " " << j << " " << c[x][y][j] << "\n";*/
	}
	memset(dp, 0x3f, sizeof(dp));
	dp[0][0]=0;
	for (int i=0; i<n; ++i) {
		for (int j=0; j<=i; ++j) {
			dp[i+1][j]=min(dp[i+1][j], dp[i][j]+c[i][i+1][0]);
			dp[i+1][i]=min(dp[i+1][i], dp[j][i]+c[j][i+1][0]);
			dp[j][i+1]=min(dp[j][i+1], dp[j][i]+c[i][i+1][1]);
			dp[i][i+1]=min(dp[i][i+1], dp[i][j]+c[j][i+1][1]);
		}
	}
	int ans=696969;
	for (int i=0; i<n; ++i)
		ans=min(ans, min(dp[n][i], dp[i][n]));
	cout << a[0]+a[1]-2-ans;
	return 0;
}
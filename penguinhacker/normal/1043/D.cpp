#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n, m, a[100000][10], p[100000][10], dp[1000000];
bool vis[100000];
ll ans=0;

void dfs(int u) {
	vis[u]=1;
	dp[u]=1;
	++ans;
	for (int i=0; i<m; ++i)
		if (p[u][i]==n-1)
			return;
	int x=a[p[u][0]+1][0];
	for (int i=1; i<m; ++i)
		if (a[p[u][i]+1][i]^x)
			return;
	if (!vis[x])
		dfs(x);
	dp[u]+=dp[x];
	ans+=dp[x];
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i=0; i<m; ++i)
		for (int j=0; j<n; ++j) {
			int x;
			cin >> x, --x;
			a[j][i]=x;
			p[x][i]=j;
		}
	for (int i=0; i<n; ++i)
		if (!vis[i])
			dfs(i);
	cout << ans;
	return 0;
}
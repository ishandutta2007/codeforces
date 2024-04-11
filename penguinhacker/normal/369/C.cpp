#include <bits/stdc++.h>
using namespace std;

int n, dp[100000]={0};
bool white[100000]={0};
vector<int> adj[100000];

void dfs(int u=0, int p=-1) {
	if (white[u])
		dp[u]=1;
	for (int v:adj[u]) {
		if (v!=p) {
			dfs(v, u);
			dp[u]+=dp[v];
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i=0, u, v, state; i<n-1; ++i) {
		cin >> u >> v >> state, u--, v--;
		if (state==2)
			white[u] = white[v] = 1;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs();
	int ans=0;
	vector<int> v;
	for (int i=0; i<n; ++i) {
		if (dp[i]==1) {
			ans++;
			v.push_back(i+1);
		}
	}
	cout << ans << '\n';
	for (int i:v)
		cout << i << ' ';
	return 0;
}
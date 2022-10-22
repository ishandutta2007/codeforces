#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=5e5;
int n, m, p[mxN], d[mxN];
string s;
bool ans[mxN];
vector<int> adj[mxN], dp[mxN];
vector<ar<int, 2>> qry[mxN];

void dfs(int u=0) {
	dp[u]={1<<s[u]-'a'};
	for (int v : adj[u]) {
		d[v]=d[u]+1;
		dfs(v);
		dp[v].push_back(0);
		if (dp[u].size()<dp[v].size())
			swap(dp[u], dp[v]);
		for (int i=dp[v].size()-1, j=dp[u].size()-1; ~i; --i, --j)
			dp[u][j]^=dp[v][i];
	}
	for (auto [x, i] : qry[u]) {
		if (x<=d[u])
			ans[i]=1;
		else {
			x-=d[u];
			int pos=dp[u].size()-1-x;
			if (pos<0)
				ans[i]=1;
			else {
				int cur=dp[u][dp[u].size()-1-x];
				ans[i]=__builtin_popcount(cur)<=1;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i=1; i<n; ++i) {
		cin >> p[i], --p[i];
		adj[p[i]].push_back(i);
	}
	cin >> s;
	for (int i=0; i<m; ++i) {
		int v, h;
		cin >> v >> h, --v, --h;
		qry[v].push_back({h, i});
	}
	dfs();
	for (int i=0; i<m; ++i)
		cout << (ans[i]?"Yes":"No") << "\n";
	return 0;
}
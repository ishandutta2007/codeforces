#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=200000;
int n, m, k, c=0, mx;
vector<int> adj[mxN], cur;
bool vis[mxN];
vector<vector<int>> ans;

void consider(int u) {
	++c;
	cur.push_back(u);
	if (c==mx) {
		c=0;
		ans.push_back(cur);
		cur.clear();
	}
}

void dfs(int u=0) {
	vis[u]=1;
	consider(u);
	for (int v : adj[u]) {
		if (vis[v])
			continue;
		dfs(v);
		consider(u);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m >> k;
	for (int i=0; i<m; ++i) {
		int u, v;
		cin >> u >> v, --u, --v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	mx=(2*n+k-1)/k;
	dfs();
	if (!cur.empty())
		ans.push_back(cur);
	assert(ans.size()<=k);
	while(ans.size()<k)
		ans.push_back({0});
	for (vector<int> v : ans) {
		cout << v.size() << " ";
		for (int i : v)
			cout << i+1 << " ";
		cout << "\n";
	}
	return 0;
}
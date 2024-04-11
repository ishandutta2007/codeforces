#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int getCentroid(int root, const vector<vector<int>> &adj, const vector<bool> &vis) {
	static vector<int> sz(adj.size());
	function<void (int, int)> dfs_size=[&](int u, int p) {
		sz[u]=1;
		for (int v: adj[u]) if (v!=p&&!vis[v]) {
			dfs_size(v, u);
			sz[u]+=sz[v];
		}
	};
	dfs_size(root, -1);
	function<int (int, int)> dfs_get=[&] (int u, int p) {
		for (int v: adj[u]) if (v!=p&&!vis[v])
			if (sz[v]>sz[root]/2)
				return dfs_get(v, u);
		return u;
	};
	return dfs_get(root, -1);
}

vector<char> decompose(const vector<vector<int>> &adj) {
	int n=adj.size();
	vector<bool> vis(n, 0);
	vector<char> ans(n);
	function<void (int, char)> dfs=[&](int u, char cur) {
		int x=getCentroid(u, adj, vis);
		vis[x]=1;
		//cerr << u << " " << x << '\n';
		assert(cur<='Z');
		ans[x]=cur;
		for (int v: adj[x]) if (!vis[v])
			dfs(v, cur+1);
		vis[x]=0;
	};
	dfs(0, 'A');
	return ans;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n; cin >> n;
	vector<vector<int>> adj(n);
	for (int i=1; i<n; ++i) {
		int a, b; cin >> a >> b, --a, --b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	vector<char> ans=decompose(adj);
	for (char i: ans)
		cout << i << ' ';
	return 0;
}
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=500000;
int n, m, par[mxN];
bool vis[mxN];
vector<int> adj[mxN], dep[mxN]; //dep is nodes at depth[i] in the dfs tree

void dfs(int u=0, int d=0) {
	dep[d].push_back(u);
	vis[u]=1;
	/*if (par[u]!=-1)
		adj[u].erase(find(adj[u].begin(), adj[u].end(), par[u]));*/
	for (int v: adj[u]) if (!vis[v]) {
		par[v]=u;
		dfs(v, d+1);
	}
}

void test_case() {
	cin >> n >> m;
	for (int i=0; i<n; ++i)
		adj[i].clear(), dep[i].clear();
	for (int i=0; i<m; ++i) {
		int a, b; cin >> a >> b, --a, --b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	fill(par, par+n, -1);
	fill(vis, vis+n, 0);
	dfs();
	if (!dep[(n-1)/2].empty()) {
		cout << "PATH\n" << (n+1)/2 << '\n';
		int cur=dep[(n-1)/2][0];
		while(cur!=-1) {
			cout << cur+1 << ' ';
			cur=par[cur];
		}
		cout << '\n';
	}
	else {
		vector<pair<int, int>> ans;
		for (int i=0; !dep[i].empty(); ++i) {
			for (int j=0; j<(int)dep[i].size()-1; j+=2) {
				ans.emplace_back(dep[i][j], dep[i][j+1]);
			}
		}
		assert((int)ans.size()*2>=(n+1)/2);
		cout << "PAIRING\n" << ans.size() << '\n';
		for (auto x: ans)
			cout << x.first+1 << ' ' << x.second+1 << '\n';
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while(t--)
		test_case();
	return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
*/
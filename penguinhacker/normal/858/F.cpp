#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=200000;
int n, m, t, tin[mxN];
vector<int> adj[mxN], e[mxN];
vector<ar<int, 3>> ans;

void dfs(int u, int p=-1) {
	tin[u]=++t;
	if (p^-1)
		e[u].push_back(p);
	for (int v : adj[u]) {
		if (v==p)
			continue;
		if (!tin[v]) {
			dfs(v, u);
		} else if (tin[v]<tin[u]) {
			e[u].push_back(v);
		}
	}
	while(e[u].size()>=2) {
		int v=e[u].back();
		e[u].pop_back();
		int w=e[u].back();
		e[u].pop_back();
		ans.push_back({v, u, w});
	}
	if (e[u].size()==1&&p^-1)
		e[p].push_back(u);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i=0; i<m; ++i) {
		int u, v;
		cin >> u >> v, --u, --v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for (int i=0; i<n; ++i)
		if (!tin[i])
			dfs(i);
	cout << ans.size() << "\n";
	for (ar<int, 3> x : ans)
		cout << x[0]+1 << " " << x[1]+1 << " " << x[2]+1 << "\n";
	return 0;
}
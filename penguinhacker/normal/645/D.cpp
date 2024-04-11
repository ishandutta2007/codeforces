#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n, m;
bool vis[100000];
ar<int, 2> e[100000];
vector<int> adj[100000];
vector<int> ord;

void dfs(int u) {
	vis[u]=1;
	for (int v: adj[u])
		if (!vis[v])
			dfs(v);
	ord.push_back(u);
}

bool ok(int x) {
	ord.clear();
	for (int i=0; i<n; ++i)
		vis[i]=0, adj[i].clear();
	for (int i=0; i<x; ++i)
		adj[e[i][0]].push_back(e[i][1]);
	for (int i=0; i<n; ++i) if (!vis[i])
		dfs(i);
	assert(ord.size()==n);
	for (int i=1; i<n; ++i)
		if (find(adj[ord[i]].begin(), adj[ord[i]].end(), ord[i-1])==adj[ord[i]].end())
			return 0;
	return 1;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i=0; i<m; ++i)
		cin >> e[i][1] >> e[i][0], --e[i][0], --e[i][1];
	int l=1, r=m;
	while(l<r) {
		int mid=(l+r)/2;
		if (ok(mid)) r=mid;
		else l=mid+1;
	}
	cout << (ok(l)?l:-1);
	return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
*/
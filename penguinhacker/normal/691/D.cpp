#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n, m, a[1000000];
bool vis[1000000]={};
vector<int> adj[1000000];
vector<int> pos, num;

void dfs(int u) {
	vis[u]=1;
	pos.push_back(u);
	num.push_back(a[u]);
	for (int v:adj[u])
		if (!vis[v])
			dfs(v);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i=0; i<n; ++i)
		cin >> a[i];
	for (int i=0, u, v; i<m; ++i) {
		cin >> u >> v, u--, v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	
	for (int i=0; i<n; ++i) {
		if (vis[i])
			continue;
		dfs(i);
		sort(pos.begin(), pos.end());
		sort(num.rbegin(), num.rend());
		for (int i=0; i<pos.size(); ++i)
			a[pos[i]]=num[i];
		pos.clear();
		num.clear();
	}
	for (int i=0; i<n; ++i)
		cout << a[i] << ' ';
	return 0;
}
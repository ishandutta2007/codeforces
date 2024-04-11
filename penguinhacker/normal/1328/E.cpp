#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define arr array

int n, m, dep[200001], par[200001], tin[200001], tout[200001];
vector<int> adj[200001];

int T=0;
void dfs(int u=1, int p=-1, int d=0) {
	dep[u]=d;
	par[u]=p;
	tin[u]=T++;
	for (int v : adj[u])
		if (v!=p)
			dfs(v, u, d+1);
	tout[u]=T++;
}

bool isAnc(int u, int v) { //is u the ancestor of v?
	return tin[u]<=tin[v]&&tout[v]<=tout[u];
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	for (int i=1, u, v; i<n; ++i) {
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs();
	while(m--) {
		int k;
		cin >> k;
		vector<int> v(k);
		for (auto &i : v)
			cin >> i;
		int deepest=v[0];
		for (auto &i : v)
			if (dep[i]>dep[deepest])
				deepest=i;
		for (auto &i : v)
			if (par[i]!=-1)
				i=par[i];
		bool ok=1;
		for (auto &i : v)
			if (!isAnc(i, deepest)) {
				ok=0;
				break;
			}
		cout << (ok?"YES":"NO") << '\n';
	}
	return 0;
}
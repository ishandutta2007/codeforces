#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n, ans=0, c[200000], nxt[200000];
bool vis1[200000]={}, vis2[200000]={};
vector<int> adj[200000];

vector<int> cycle;
void dfs1(int u) {
	if (vis1[u]) {
		cycle.push_back(u);
		return;
	}
	vis1[u]=1;
	dfs1(nxt[u]);
	if (nxt[u]==cycle.back()&&cycle[0]!=u&&nxt[u]!=nxt[nxt[u]])
		cycle.push_back(u);
}

void dfs2(int u) {
	vis2[u]=1;
	for (int v:adj[u])
		if (!vis2[v])
			dfs2(v);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i=0; i<n; ++i)
		cin >> c[i];
	for (int i=0; i<n; ++i) {
		cin >> nxt[i], nxt[i]--;
		adj[nxt[i]].push_back(i);
	}
	for (int i=0; i<n; ++i) {
		if (vis2[i])
			continue;
		cycle.clear();
		dfs1(i);
		dfs2(cycle[0]);
		int x=1e9;
		for (int j:cycle)
			x=min(x, c[j]);
		ans+=x;
	}
	cout << ans;
	return 0;
}
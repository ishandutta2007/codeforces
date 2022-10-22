#include <bits/stdc++.h>
using namespace std;

int n, p[200001], chosen=-1;
bool vis1[200001]={}, vis2[200001]={};
vector<int> adj[200001], change;

//just to fill visited2 array
void dfs2(int u) {
	vis2[u]=1;
	for (int v:adj[u])
		if (!vis2[v])
			dfs2(v);
}

void dfs1(int u) {
	if (vis1[u]) {
		if (chosen==-1&&p[u]==u)
			chosen=u;
		else
			change.push_back(u);
		dfs2(u);
		return;
	}
	vis1[u]=1;
	dfs1(p[u]);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i=1; i<=n; ++i) {
		cin >> p[i];
		adj[p[i]].push_back(i);
	}
	for (int i=1; i<=n; ++i) {
		if (vis2[i])
			continue;
		dfs1(i);
	}
	int ans=0;
	if (chosen==-1)
		chosen=change.back();

	for (int u:change) {
		p[u]=chosen;
		ans++;
	}
	cout << ans << '\n';
	for (int i=1; i<=n; ++i)
		cout << p[i] << ' ';
	return 0;
}
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define arr array

int n, m, cnt=0;
vector<int> adj[100000];
bool hasCat[100000];

void dfs(int u=0, int p=-1, int cats=0) {
	if (hasCat[u])
		cats++;
	else
		cats=0;
	if (cats > m)
		return;
	//check if is leaf
	if (adj[u].size() == 1 && adj[u][0] == p)
		cnt++;
	for (int v : adj[u]) {
		if (v != p) {
			dfs(v, u, cats);
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i=0; i<n; ++i)
		cin >> hasCat[i];
	for (int i=0, u, v; i<n-1; ++i) {
		cin >> u >> v, u--, v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	dfs();
	
	cout << cnt;
	return 0;
}
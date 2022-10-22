#include <bits/stdc++.h>
using namespace std;

int n, under[100000];
vector<int> adj[100000];

void dfs1(int u=0, int p=-1) {
	under[u] = 1;
	for (int v:adj[u]) {
		if (v!=p) {
			dfs1(v, u);
			under[u] += under[v];
		}
	}
}

int dfs2(int u=0, int p=-1) {
	int ans = 0;
	for (int v:adj[u]) {
		if (v!=p) {
			ans += dfs2(v, u);
			if (!(under[v]&1))
				ans++;
		}
	}
	return ans;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i=0, u, v; i<n-1; ++i) {
		cin >> u >> v, u--, v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	if (n&1) {
		cout << -1;
		return 0;
	}
	dfs1();
	cout << dfs2();
	return 0;
}
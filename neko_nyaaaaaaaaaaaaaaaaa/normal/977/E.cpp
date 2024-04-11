#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, m, x, y, s;
vector<vector<int>> adj(200001);
vector<int> v(200001);
int cycle;

void dfs(int now) {
	v[now] = 1;
	if (adj[now].size() != 2) {cycle = 0;}

	for (int i = 0; i < adj[now].size(); i++) {
		if (v[adj[now][i]]) {continue;}
		dfs(adj[now][i]);
	}
}

int main() {

	cin >> n >> m;
	while (m--) {
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}

	int ans = 0;
	for (int i = 1; i <= n; i++) {
		if (v[i]) continue;

		cycle = 1;
		dfs(i);
		ans += cycle;
	}

	cout << ans;

	return 0;
}
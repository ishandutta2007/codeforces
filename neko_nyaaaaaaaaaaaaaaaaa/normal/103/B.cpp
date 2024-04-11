#include <bits/stdc++.h>
using namespace std;

vector<bool> v;
vector<vector<int>> adj;

void dfs(int now) {
	v[now] = 0;
	for (int i = 0; i < adj[now].size(); i++) {
		if (v[adj[now][i]]) {dfs(adj[now][i]);}
	}
}

int main() {
	
	int n, m, x, y;
	cin >> n >> m;
	adj.resize(n+1, vector<int>(0));
	v.resize(n+1, 1);
	if (n != m) {cout << "NO"; return 0;}
	while (m--) {
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	dfs(1);
	for (int i = 1; i <= n; i++) {
		if (v[i] == 1) {cout << "NO"; return 0;}
	}
	cout << "FHTAGN!";
	
	return 0;
}
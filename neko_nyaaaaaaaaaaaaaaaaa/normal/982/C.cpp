#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, ans;
vector<vector<int>> adj(100005);
vector<int> vis(100005);
vector<int> deg(100005);

void dfs(int now) {
	vis[now] = 1;
	
	for (int i = 0; i < adj[now].size(); i++) {
		if (vis[adj[now][i]]) continue;
		
		dfs(adj[now][i]);
		deg[now] += deg[adj[now][i]];
	}
	
	deg[now]++;
}

void dfs2(int now) {
	vis[now] = 1;
	
	for (int i = 0; i < adj[now].size(); i++) {
		if (vis[adj[now][i]]) continue;
		if (deg[adj[now][i]] % 2 == 0) ans++;
		dfs2(adj[now][i]);
	}
}

int main() {
	ios::sync_with_stdio(0);
	
	cin >> n;
	if (n % 2) {cout << "-1"; return 0;}
	
	int x, y;
	for (int i = 1; i < n; i++) {
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	dfs(1);
	
	for (int i = 1; i <= n; i++) {
		vis[i] = 0;
	}
	dfs2(1);
	
	cout << ans;
	
	return 0;
}
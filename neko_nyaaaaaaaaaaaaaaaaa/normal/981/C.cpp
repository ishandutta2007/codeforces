#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, x, y, root = 1, cnt = 0;
vector<vector<int>> adj(100005);
vector<int> vis(100005);
vector<int> deg(100005);
vector<pair<int, int>> ans;

void dfs(int now) {
	vis[now] = 1;
	if (now != root && adj[now].size() == 1) {
		ans.push_back({root, now});
	}
	for (auto u: adj[now]) {
		if (vis[u]) continue;
		dfs(u);
	}
}

int main() {
	ios::sync_with_stdio(0);
	
	cin >> n;
	for (int i = 1; i < n; i++) {
		cin >> x >> y;
		deg[x]++;
		deg[y]++;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	
	for (int i = 1; i <= n; i++) {
		if (deg[i] > 2) {
			root = i;
			cnt++;
		}
	}
	
	if (cnt > 1) {cout << "No"; return 0;}
	
	dfs(root);
	
	cout << "Yes\n" << ans.size() << '\n';
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i].first << " " << ans[i].second << "\n";
	}
	return 0;
}
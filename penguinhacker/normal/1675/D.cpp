#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=2e5;
int n, p[mxN], rt, d[mxN];
vector<int> adj[mxN], cur;
vector<vector<int>> ans;

void dfs1(int u=rt) {
	d[u]=0;
	for (int v : adj[u]) {
		dfs1(v);
		d[u]=max(d[u], d[v]+1);
	}
}

void dfs2(int u=rt) {
	cur.push_back(u);
	sort(adj[u].begin(), adj[u].end(), [&](int i, int j) { return d[i]>d[j]; });
	if (adj[u].empty()) {
		ans.push_back(cur);
		cur.clear();
		return;
	}
	dfs2(adj[u][0]);
	for (int i=1; i<adj[u].size(); ++i)
		dfs2(adj[u][i]);
}

void solve() {
	cin >> n;
	for (int i=0; i<n; ++i) {
		cin >> p[i], --p[i];
		if (p[i]==i)
			rt=i;
		adj[i].clear();
	}
	for (int i=0; i<n; ++i)
		if (i!=rt)
			adj[p[i]].push_back(i);
	ans.clear();
	dfs1();
	dfs2();
	cout << ans.size() << "\n";
	for (auto x : ans) {
		cout << x.size() << "\n";
		for (int i : x)
			cout << i+1 << " ";
		cout << "\n";
	}
	cout << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--)
		solve();
	return 0;
}
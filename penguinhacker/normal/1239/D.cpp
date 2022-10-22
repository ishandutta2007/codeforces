#include <bits/stdc++.h>
using namespace std;

const int mxN=1e6;
int n, m;
vector<int> adj[mxN], adj2[mxN], st, cur;
vector<vector<int>> scc;
bool vis[mxN];

void dfs1(int u=0) {
	vis[u]=1;
	for (int v : adj[u])
		if (!vis[v])
			dfs1(v);
	st.push_back(u);
}

void dfs2(int u) {
	vis[u]=0;
	cur.push_back(u);
	for (int v : adj2[u])
		if (vis[v])
			dfs2(v);
}

void solve() {
	cin >> n >> m;
	for (int i=0; i<n; ++i) {
		vis[i]=0;
		adj[i].clear();
		adj2[i].clear();
	}
	st.clear();
	scc.clear();
	for (int i=0; i<m; ++i) {
		int u, v;
		cin >> u >> v, --u, --v;
		if (u==v)
			continue;
		adj[u].push_back(v);
		adj2[v].push_back(u);
	}
	dfs1();
	int x=count(vis, vis+n, 1);
	if (x<n) {
		cout << "Yes\n" << x << " " << n-x << "\n";
		for (int j : {1, 0}) {
			for (int i=0; i<n; ++i)
				if (vis[i]==j)
					cout << i+1 << " ";
			cout << "\n";
		}
		return;
	}
	for (int i=n-1; ~i; --i)
		if (vis[st[i]]) {
			dfs2(st[i]);
			scc.push_back({});
			swap(cur, scc.back());
		}
	if (scc.size()==1) {
		cout << "No\n";
		return;
	}
	cur=scc.back();
	cout << "Yes\n" << cur.size() << " " << n-cur.size() << "\n";
	memset(vis, 0, n);
	for (int i : cur)
		vis[i]=1;
	for (int j : {1, 0}) {
		for (int i=0; i<n; ++i)
			if (vis[i]==j)
				cout << i+1 << " ";
		cout << "\n";
	}
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
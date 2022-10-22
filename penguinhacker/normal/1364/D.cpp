#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array
const int mxN=100001;

int n, m, k, dep[mxN];
vector<int> adj[mxN], col[2], path, cyc;

bool dfs(int u=1) {
	dep[u]=path.size();
	col[path.size()%2].push_back(u);
	path.push_back(u);
	int f=-1;
	for (int v : adj[u]) {
		if (dep[v]!=-1&&dep[u]-dep[v]>1)
			f=max(f, dep[v]);
	}
	if (f!=-1) {
		for (int i=f; i<path.size(); ++i)
			cyc.push_back(path[i]);
		return 1;
	}
	for (int v : adj[u])
		if (dep[v]==-1)
			if (dfs(v))
				return 1;
	path.pop_back();
	return 0;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> k;
	for (int i=0, u, v; i<m; ++i) {
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	fill(begin(dep), end(dep), -1);
	dfs();
	if (cyc.empty()) {
		if (col[1].size()>col[0].size())
			swap(col[0], col[1]);
		cout << "1\n";
		for (int i=0; i<(k+1)/2; ++i)
			cout << col[0][i] << ' ';
	}
	else {
		if (cyc.size()<=k) {
			cout << "2\n";
			cout << cyc.size() << '\n';
			for (int i : cyc)
				cout << i << ' ';
		}
		else {
			cout << "1\n";
			for (int i=0; i<(k+1)/2; ++i)
				cout << cyc[2*i] << ' ';
		}
	}
	return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
*/
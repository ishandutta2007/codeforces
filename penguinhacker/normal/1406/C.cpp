#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n, sz[100000];
vector<int> adj[100000];

void dfs1(int u = 0, int p = -1) {
	sz[u] = 1;
	for (int v : adj[u]) {
		if (v != p) {
			dfs1(v, u);
			sz[u] += sz[v];
		}
	}
}

int dfs2(int u = 0, int p = -1) {
	for (int v : adj[u]) {
		if (v != p && 2 * sz[v] > sz[0]) {
			return dfs2(v, u);
		}
	}
	return u;
}


void solve() {
	cin >> n;
	for (int i = 0; i < n; ++i) {
		adj[i].clear();
	}
	for (int i = 1; i < n; ++i) {
		int a, b;
		cin >> a >> b, --a, --b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	dfs1();
	int u = dfs2();
	//cout << center << "\n";
	int found = -1;
	for (int v : adj[u]) {
		if (2 * sz[v] == sz[0]) {
			found = v;
			break;
		}
	}
	if (found == -1) {
		int x = adj[0][0];
		cout << "1 " << x + 1 << "\n";
		cout << "1 " << x + 1 << "\n";
		return;
	}
	assert(sz[found] == n / 2);
	int found2 = -1;
	for (int v : adj[u]) {
		if (v != found) {
			found2 = v;
			break;
		}
	}
	assert(found2 != -1);
	cout << u + 1 << " " << found2 + 1 << "\n";
	cout << found + 1 << " " << found2 + 1 << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while(t--) {
		solve();
	}
	return 0;
}
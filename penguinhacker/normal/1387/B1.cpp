#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN = 100000;
int n, ans = 0, p[mxN];
bool changed[mxN];
vector<int> adj[mxN];

void dfs(int u = 0, int par = -1) {
	for (int v : adj[u]) if (v != par) {
		dfs(v, u);
		if (!changed[v]) {
			changed[u] = 1;
			changed[v] = 1;
			ans += 2;
			swap(p[u], p[v]);
		}
	}
	if (u == 0 && !changed[u]) {
		for (int v : adj[u]) if (v != par) {
			changed[u] = 1;
			changed[v] = 1;
			ans += 2;
			swap(p[u], p[v]);
			break;
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 1; i < n; ++i) {
		int a, b; cin >> a >> b, --a, --b;
		adj[a].push_back(b);
		adj[b].push_back(a);
		p[i] = i;
	}
	dfs();
	cout << ans << "\n";
	for (int i = 0; i < n; ++i) {
		assert(changed[i] && i != p[i]);
		cout << p[i] + 1 << " ";
	}
	return 0;
}
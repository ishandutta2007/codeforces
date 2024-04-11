#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN = 100000;
int n, cnt[2];
vector<int> adj[mxN];

void dfs(int u = 0, int p = 0, bool par = 0) {
	++cnt[par];
	for (int v : adj[u]) if (v != p) dfs(v, u, par ^ 1);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 1; i < n; ++i) {
		int a, b; cin >> a >> b, --a, --b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	dfs();
	cout << (ll)cnt[0] * cnt[1] - (n - 1);
	return 0;
}
#include <bits/stdc++.h>
#define finish(x) return cout << x << endl, 0
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7;
const ll inf = 4e18;
const int OO = 1;
const int OOO = 1;
using namespace std;

int n, k;
vector<vector<int>> g;
vector<int> vis;

void dfs(int v) {
	if (vis[v]) return;
	vis[v] = 1;
	for (const auto &i : g[v])
		dfs(i);
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n >> k;
	g.resize(n);
	vis.resize(n, 0);
	int ans = 0;
	for (int i = 0, u, v; i < k; i++) {
		cin >> u >> v;
		--u, --v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	for (int i = 0; i < n; i++)
		if (!vis[i])
			dfs(i), ans++;
	cout << k - n + ans << '\n';
}
#include <bits/stdc++.h>
#define finish(x) return cout << x << endl, 0
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7;
const ll inf = 1e18;
const int OO = 1;
const int OOO = 1;
using namespace std;

int n;
vector<vector<int>> g;
vector<int> sz;
ll ans = 0;

int pre(int v, int prev) {
	sz[v] = 1;
	for (const auto &i : g[v])
		if (i != prev)
			sz[v] += pre(i, v);
	return sz[v];
}
void work(int v, int prev, ll tot) {
	ans = max(ans, tot);
	for (const auto &i : g[v])
		if (i != prev)
			work(i, v, tot - sz[i] + (n - sz[i]));
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n;
	g.resize(n);
	sz.resize(n);
	for (int i = 0, u, v; i < n - 1; i++) {
		cin >> u >> v;
		--u, --v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	pre(0, 0);
	for (int i = 0; i < n; i++) ans += sz[i];
	ans -= n;
	work(0, 0, ans);
	finish(ans + n);
}
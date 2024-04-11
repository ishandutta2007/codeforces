#include <bits/stdc++.h>
#define finish(x) return cout << x << endl, 0
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7;
const ll inf = 4e18;
const int OO = 1;
const int OOO = 1;
using namespace std;

int n;
vector<ll> a, b;
vector<int> vis, cyc, can;

bool adj(int i, int j) {
	return (a[i] & a[j]) == a[i];
}

void dfs(int v) {
	if (vis[v]) {
		if (vis[v] == 1) cyc.push_back(v);
		return;
	}
	vis[v] = 1;
	for (int u = 0; u < n; u++)
		if (u != v && adj(v, u))
			dfs(u);
	vis[v] = 2;
}
void rdfs(int v) {
	if (can[v]) return;
	can[v] = 1;
	for (int u = 0; u < n; u++)
		if (u != v && adj(u, v))
			rdfs(u);
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n;
	a.resize(n);
	b.resize(n);
	vis.resize(n, 0);
	can.resize(n, 0);

	ll ans = 0;
	for (auto &i : a) cin >> i;
	for (auto &i : b) cin >> i;

	for (int i = 0; i < n; i++)
		dfs(i);
	for (const auto &i : cyc) rdfs(i);
	for (int i = 0; i < n; i++)
		if (can[i]) ans += b[i];
	cout << ans << '\n';
}
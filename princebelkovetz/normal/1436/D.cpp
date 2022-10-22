#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <iomanip>
#include <cassert>
#include <queue>
using namespace std;
#define int long long
#define debug(x) cout << #x << " is " << x << '\n';
const int N = 1e6 + 2, mod = 1e9 + 7, mod2 = 998244353;
vector <vector <int>> g;
vector <int> leaf, sum, a, num;
void dfs(int v) {
	if (g[v].empty()) {
		leaf[v] = a[v];
		sum[v] = a[v];
		num[v] = 1;
		return;
	}
	sum[v] = a[v];
	for (auto u : g[v]) {
		dfs(u);
		leaf[v] = max(leaf[v], leaf[u]);
		sum[v] += sum[u];
		num[v] += num[u];
	}
	int got = (sum[v] + num[v] - 1) / num[v];
	leaf[v] = max(leaf[v], got);
}
signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(6);
	int n; cin >> n;
	g.resize(n + 1);
	leaf.resize(n + 1);
	sum.resize(n + 1);
	a.resize(n + 1);
	num.resize(n + 1);
	for (int i = 2; i <= n; ++i) {
		int p; cin >> p;
		g[p].push_back(i);
	}
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	dfs(1);
	cout << leaf[1] << '\n';
}
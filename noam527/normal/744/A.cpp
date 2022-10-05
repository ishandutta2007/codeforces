#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <string>
#include <time.h>
#include <stack>
#include <queue>
#include <random>
#include <fstream>
#define endl '\n'
#define flush fflush(stdout), cout.flush()
#define fast ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define debug cout << "ok" << endl
#define finish(x) return cout << x << endl, 0
typedef long long ll;
typedef long double ldb;
const int md = 998244353;
const ll hs = 199;
const ldb eps = 1e-9, pi = acos(-1);
using namespace std;

ll val(ll x) {
	return x * (x - 1) / 2;
}

int n, m, k;
vector<int> a, vis, sz;
vector<vector<int>> g;

int dfs(int v) {
	if (vis[v]) return 0;
	vis[v] = 1;
	int rtn = 1;
	for (auto &i : g[v]) rtn += dfs(i);
	return rtn;
}

int main() {
	fast;
	cin >> n >> m >> k;
	a.resize(k), vis.resize(n, 0), g.resize(n);
	for (int i = 0; i < k; i++) cin >> a[i];
	for (int i = 0, u, v; i < m; i++) {
		cin >> u >> v, --u, --v;
		g[u].push_back(v), g[v].push_back(u);
	}
	int tot = 0;
	for (auto &i : a) sz.push_back(dfs(--i)), tot += sz.back();
	sort(sz.begin(), sz.end());
	sz.back() += (n - tot);

	ll ans = 0;
	for (auto &i : sz) ans += val(i);
	cout << ans - m << endl;
}
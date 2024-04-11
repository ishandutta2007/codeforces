#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <string>
#include <cmath>
#include <set>
#include <map>
#include <queue>
#include <iterator>
#include <sstream>
#include <cassert>
#define int long long
#define ld long double
#define debug(x) cout << #x << " is " << x << endl;
using namespace std;
vector <vector <int>> a;
vector <bool> used;
vector <int> d, b, c, one, zero, dp, mn, done;
int ans = 0;
void dfs(int v) {
	used[v] = true;
	if (v == 1) mn[v] = d[v];
	for (auto u : a[v]) {
		if (used[u]) continue;
		mn[u] = min(mn[v], d[u]);
		dfs(u);
		one[v] += one[u];
		zero[v] += zero[u];
		done[v] += done[u];
	}
	if (b[v] == 0 and c[v] == 1) zero[v]++;
	if (b[v] == 1 and c[v] == 0) one[v]++;
	if (mn[v] == d[v]) {
		ans += 2 * d[v] * (min(zero[v], one[v]) - done[v]);
		done[v] = min(zero[v], one[v]);
	}
}
signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, cnt1 = 0, cntn1 = 0; cin >> n;
	a.resize(n + 1);
	used.resize(n + 1);
	d.resize(n + 1);
	b.resize(n + 1);
	c.resize(n + 1);
	one.resize(n + 1);
	zero.resize(n + 1);
	dp.resize(n + 1);
	mn.resize(n + 1);
	done.resize(n + 1);
	for (int i = 1; i <= n; ++i) {
		cin >> d[i] >> b[i] >> c[i];
		if (b[i]) cnt1++;
		if (c[i]) cntn1++;
	}
	for (int i = 0, u, v; i < n - 1; ++i) {
		cin >> u >> v;
		a[u].push_back(v);
		a[v].push_back(u);
	}
	if (cnt1 != cntn1) {
		cout << "-1\n";
		return 0;
	}
	dfs(1);
	cout << ans << '\n';
	return 0;
}
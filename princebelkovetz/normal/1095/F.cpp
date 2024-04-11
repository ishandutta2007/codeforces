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
vector <int> p, sz;
int get(int a) {
	return p[a] = p[a] == a ? a : get(p[a]);
}
bool unite(int a, int b) {
	a = get(a), b = get(b);
	if (a == b) return false;
	if (sz[a] < sz[b]) swap(a, b);
	p[b] = a;
	sz[a] += sz[b];
	return true;
}
signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(6);
	int n, m; cin >> n >> m;
	p.resize(n), sz.resize(n);
	vector <int> a(n);
	vector <vector <int>> e;
	for (auto& x : a) cin >> x;
	for (int i = 0; i < n; ++i)
		p[i] = i;
	int mn = 0;
	for (int i = 1; i < n; ++i)
		if (a[i] < a[mn])
			mn = i;
	for (int i = 0; i < n; ++i) {
		if (mn == i) continue;
		e.push_back({ a[i] + a[mn], i, mn });
	}
	for (int i = 0, u, v, w; i < m; ++i) {
		cin >> u >> v >> w;
		e.push_back({ w, u - 1, v - 1, });
	}
	sort(e.begin(), e.end());
	int ans = 0;
	for (auto x : e) {
		if (unite(x[1], x[2]))
			ans += x[0];
	}
	cout << ans << '\n';
	return 0;
}
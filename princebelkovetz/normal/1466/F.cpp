#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <cassert>
#include <map>
#include <set>
using namespace std;
#define debug(x) cout << #x << " is " << x << '\n';
#define int long long
const int bb = 62, mod = 1e9 + 7;
vector <int> p, sz;
int get(int a) {
	return p[a] = p[a] == a ? a : get(p[a]);
}
bool unite(int a, int b) {
	a = get(a), b = get(b);
	if (a == b) return false;
	if (sz[a] < sz[b]) swap(a, b);
	p[b] = a, sz[a] += sz[b];
	return true;
}
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout << fixed << setprecision(6);
	int n, m; cin >> n >> m;
	p.resize(m + 2), sz.resize(m + 2);
	for (int i = 0; i <= m + 1; ++i)
		p[i] = i, sz[i] = 1;
	vector <vector <int>> e;
	for (int i = 0, u, v; i < n; ++i) {
		int k; cin >> k;
		cin >> u;
		if (k > 1) cin >> v;
		else v = m + 1;
		e.push_back({ i, u, v });
	}
	sort(e.begin(), e.end());
	vector <int> inds;
	for (auto x : e) {
		if (unite(x[1], x[2])) {
			inds.push_back(x[0]);
		}
	}
	int res = 1;
	for (int i = 0; i < inds.size();
		++i, res = (res << 1) % mod) 
	{ }
	cout << res << ' ' << inds.size() << '\n';
	sort(inds.begin(), inds.end());
	for (auto x : inds) cout << x + 1 << ' ';
	cout << '\n';
	return 0;
}
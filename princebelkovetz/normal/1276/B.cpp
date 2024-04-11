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
struct dsu {
	vector <int> p, sz;
	void init(int n) {
		p.resize(n + 1);
		sz.resize(n + 1);
		for (int i = 1; i <= n; ++i)
			p[i] = i, sz[i] = 1;
	}
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
};
signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(6);
	int tt; cin >> tt;
	while (tt --> 0) {
		int n, m, a, b; 
		cin >> n >> m >> a >> b;
		dsu g; g.init(n);
		vector <vector <int>> e(n + 1);;
		g.sz[a] = 0, g.sz[b] = 0;
		for (int i = 0, u, v; i < m; ++i) {
			cin >> u >> v;
			if (a == u or a == v or b == u or b == v) {
				e[u].push_back(v);
				e[v].push_back(u);
			}
			else {
				g.unite(u, v);
			}
		}
		set <int> as, bs;
		for (auto x : e[a]) {
			as.insert(g.get(x));
		}
		for (auto x : e[b]) {
			bs.insert(g.get(x));
		}
		int ax = 0, bx = 0;
		for (auto x : as) {
			if (bs.find(x) == bs.end())
				ax += g.sz[x];
		}
		for (auto x : bs) {
			if (as.find(x) == as.end())
				bx += g.sz[x];
		}
		cout << ax * bx << '\n';
	}
}
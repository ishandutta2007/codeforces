#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <iomanip>
#include <queue>
#include <cassert>
#include <bitset>
#include <iomanip>
#include <deque>
#include <cassert>
#include <numeric>

using namespace std;

#define debug(x) cout << #x << " is " << x << '\n';
#define ld long double
#define int long long

const int mod = 1e9 + 7;

struct disjointSet {
	vector <int> p;
	disjointSet(int n) {
		p.resize(n);
		iota(p.begin(), p.end(), 0);
	}
	int get(int a) {
		return p[a] = p[a] == a ? a : get(p[a]);
	}
	bool unite(int a, int b) {
		a = get(a), b = get(b);
		if (a == b) return false;
		p[b] = a;
		return true;
	}
};

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int tt; cin >> tt;
	while (tt--) {
		int n, m; cin >> n >> m;
		int ans = 0;
		vector <vector <int>> e;
		for (int i = 0, u, v, w; i < m; ++i) {
			cin >> u >> v >> w;
			e.push_back({ u, v, w });
		}
		for (int i = 31; i >= 0; --i) {
			int cntEdges = 0;
			vector <vector <int>> newE;
			disjointSet dsu(n + 1);
			for (auto& x : e) {
				if (x[2] & (1ll << i)) continue;
				newE.push_back(x);
				cntEdges += dsu.unite(x[0], x[1]);
			}
			if (cntEdges == n - 1) {
				e = newE;
			} else {
				ans += (1ll << i);
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
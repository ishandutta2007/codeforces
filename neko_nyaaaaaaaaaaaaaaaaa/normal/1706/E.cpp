#include <bits/stdc++.h>
using namespace std;

#define mp make_pair

struct persistent_DSU {
	int n, version;

	vector<vector<pair<int, int>>> parent;
	vector<vector<pair<int, int>>> size;

	persistent_DSU(int n) {
		this->n = n; version = 0;
		parent.resize(n+1);
		size.resize(n+1);

		for (int i = 1; i <= n; i++) {
			parent[i].emplace_back(version, i);
			size[i].emplace_back(version, 1);
		}
	}

	int get_root(int u, int ver) {
		auto tmp = *(upper_bound(parent[u].begin(), parent[u].end(), mp(ver+1, 0)) - 1);
		int v, par; tie(v, par) = tmp;

		if (par != u) {
			return get_root(par, ver);
		} else {
			return par;
		}
	}

	int get_sz(int u, int ver) {
		u = get_root(u, ver);
		auto tmp = *(upper_bound(size[u].begin(), size[u].end(), mp(ver+1, 0)) - 1);
		int v, sz; tie(v, sz) = tmp;

		return sz;
	}

	int merge(int u, int v, int ver) {
		u = get_root(u, ver);
		v = get_root(v, ver);

		if (u == v) {
			return 0;
		}

		version = ver;
		
		int szu = size[u].back().second;
		int szv = size[v].back().second;

		if (szu > szv) {swap(u, v);}

		parent[u].push_back(mp(version, v));
		int new_sz = szu + szv;
		size[v].push_back(mp(version, new_sz));

		return version;
	}

	bool same(int u, int v, int ver) {
		u = get_root(u, ver);
		v = get_root(v, ver);

		return (u == v);
	}
};

struct RMQ {
	vector<vector<int>> tb;
	RMQ(vector<int> V) : tb(1, V) {
		for (int pw = 1, k = 1; pw * 2 <= (int)V.size(); pw *= 2, ++k) {
			tb.emplace_back((int)V.size() - pw * 2 + 1);
			for(int j = 0; j < (int)tb[k].size(); j++) {
				tb[k][j] = max(tb[k - 1][j], tb[k - 1][j + pw]);
			}
		}
	}
	int query(int a, int b) {
		int dep = 31 - __builtin_clz(b - a);
		return max(tb[dep][a], tb[dep][b - (1 << dep)]);
	}
};

void solve() {
	int n, m, q; cin >> n >> m >> q;
	persistent_DSU PD(n);
	for (int i = 1; i <= m; i++) {
		int u, v; cin >> u >> v;
		PD.merge(u, v, i);
	}

	vector<int> rs(n+1);
	for (int x = 1; x < n; x++) {
		int y = x+1;

		int lo = 0, hi = m+1;
		while (lo < hi) {
			int mid = (lo + hi)/2;

			if (PD.same(x, y, mid)) {
				hi = mid;
			} else {
				lo = mid+1;
			}
		}
		rs[x] = lo;
	}

	RMQ rq(rs);
	while (q--) {
		int l, r; cin >> l >> r;
		if (l == r) cout << "0 ";
		else cout << rq.query(l, r) << ' ';
	}
	cout << '\n';
}

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int t; cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}
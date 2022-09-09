// Created by Nikolay Budin

#ifdef DEBUG
#  define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
#define ff first
#define ss second
#define szof(x) ((int)x.size())
#ifndef LOCAL
#  define cerr __get_ce
#endif

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef unsigned long long ull;
int const INF = (int)1e9 + 1e3;
ll const INFL = (ll)1e18 + 1e6;
#ifdef LOCAL
	mt19937 tw(9450189);
#else
	mt19937 tw(chrono::high_resolution_clock::now().time_since_epoch().count());
#endif
uniform_int_distribution<ll> ll_distr;
ll rnd(ll a, ll b) { return ll_distr(tw) % (b - a + 1) + a; }

const int MOD = 998244353;

void add(int& a, int b) {
	a += b;
	if (a >= MOD) {
		a -= MOD;
	}
}

int sum(int a, int b) {
	add(a, b);
	return a;
}

int mult(int a, int b) {
	return (ll) a * b % MOD;
}

int mpow(int a, int b) {
	int ret = 1;
	while (b) {
		if (b & 1) {
			ret = mult(ret, a);
		}
		a = mult(a, a);
		b >>= 1;
	}
	return ret;
}

int inv(int num) {
	return mpow(num, MOD - 2);
}

void solve() {
	int n, q;
	cin >> n >> q;
	vector<vector<int>> graph(n);
	for (int i = 0; i < n - 1; ++i) {
		int a, b;
		cin >> a >> b;
		--a; --b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	vector<int> sz(n);
	vector<int> parent(n);
	vector<int> tin(n), tout(n);
	int tcnt = 0;
	function<void(int, int)> dfs = [&](int v, int p) {
		tin[v] = tcnt++;
		parent[v] = p;
		if (v != 0) {
			graph[v].erase(find(graph[v].begin(), graph[v].end(), p));
		}
		sz[v] = 1;
		for (int to : graph[v]) {
			dfs(to, v);
			sz[v] += sz[to];
		}
		sort(graph[v].begin(), graph[v].end(), [&](int a, int b) {
			return sz[a] > sz[b];
		});
		tout[v] = tcnt;
	};
	dfs(0, 0);

	const int SQRT = max((int) round(sqrt(n)), 1);

	int bpv = 1;
	while (bpv < n) {
		bpv *= 2;
	}
	vector<int> segtree(bpv * 2);

	auto segtree_add = [&](int l, int r, int val) {
		l += bpv; r += bpv;
		while (l < r) {
			if (l & 1) {
				add(segtree[l++], val);
			}
			if (r & 1) {
				add(segtree[--r], val);
			}
			l /= 2; r /= 2;
		}
	};

	auto segtree_get = [&](int pos) {
		pos += bpv;
		int ret = 0;
		while (pos) {
			add(ret, segtree[pos]);
			pos /= 2;
		}
		return ret;
	};

	auto add_node = [&](int v, int val) {
		segtree_add(tin[v], tout[v], val);
	};

	auto get_node = [&](int v) {
		return segtree_get(tin[v]);
	};

	int all_add = 0;
	int inv_n = inv(n);
	vector<int> add_here(n);
	for (int i = 0; i < q; ++i) {
		int t;
		cin >> t;
		if (t == 1) {
			int v, d;
			cin >> v >> d;
			--v;
			add(all_add, d);
			add(add_here[v], d);
			int coef = mult(d, mult(n - sz[v], inv_n));
			add(all_add, MOD - coef);
			add_node(v, coef);
			for (int u : graph[v]) {
				if (sz[u] < SQRT) {
					break;
				}
				coef = mult(d, mult(sz[u], inv_n));
				add_node(u, MOD - coef);
			}
		} else {
			int v;
			cin >> v;
			--v;
			int ans = sum(all_add, get_node(v));
			while (true) {
				int p = parent[v];
				if (p == v || sz[v] >= SQRT) {
					break;
				}
				int coef = mult(add_here[p], mult(sz[v], inv_n));
				add(ans, MOD - coef);
				v = p;
			}
			cout << ans << "\n";
		}
	}
}


int main() {
#ifdef LOCAL
	auto start_time = clock();
	cerr << setprecision(3) << fixed;
#endif
	cout << setprecision(15) << fixed;
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int test_count = 1;
	// cin >> test_count;
	for (int test = 1; test <= test_count; ++test) {
		solve();
	}
	
#ifdef LOCAL
	auto end_time = clock();
	cerr << "Execution time: " << (end_time - start_time) * (int)1e3 / CLOCKS_PER_SEC << " ms\n";
#endif
}
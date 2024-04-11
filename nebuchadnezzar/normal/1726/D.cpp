// Created by Nikolay Budin

#ifdef DEBUG
#  define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
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

using namespace __gnu_pbds;
template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename K, typename V> using ordered_map = tree<K, V, less<K>, rb_tree_tag, tree_order_statistics_node_update>;

int const INF = (int)1e9 + 1e3;
ll const INFL = (ll)1e18 + 1e6;
#ifdef LOCAL
	mt19937 tw(9450189);
#else
	mt19937 tw(chrono::high_resolution_clock::now().time_since_epoch().count());
#endif
uniform_int_distribution<ll> ll_distr;
ll rnd(ll a, ll b) { return ll_distr(tw) % (b - a + 1) + a; }


void solve() {
	int n, m;
	cin >> n >> m;

	vector<int> dsu(n);
	iota(dsu.begin(), dsu.end(), 0);
	auto get_root = [&](int v) {
		int mem = v;
		while (dsu[v] != v) {
			v = dsu[v];
		}
		while (dsu[mem] != mem) {
			int tmp = dsu[mem];
			dsu[mem] = v;
			mem = tmp;
		}
		return v;
	};

	auto unite = [&](int a, int b) {
		a = get_root(a);
		b = get_root(b);
		if (a == b) {
			return false;
		}
		dsu[b] = a;
		return true;
	};

	vector<pair<pii, int>> bad_edges, tree_edges;
	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		--a; --b;
		if (!unite(a, b)) {
			bad_edges.push_back({{a, b}, i});
		} else {
			tree_edges.push_back({{a, b}, i});
		}
	}

	int ans = n * 2 + 1;
	vector<bool> res(m);

	for (int mask = 0; mask < 1 << szof(bad_edges); ++mask) {
		int cur = n * 2;
		vector<bool> cur_res(m);
		iota(dsu.begin(), dsu.end(), 0);
		for (int i = 0; i < szof(bad_edges); ++i) {
			if (mask & (1 << i)) {
				cur -= unite(bad_edges[i].ff.ff, bad_edges[i].ff.ss);
				cur_res[bad_edges[i].ss] = 1;
			}
		}

		vector<pii> left;
		for (auto [e, ind] : tree_edges) {
			auto [a, b] = e;
			if (unite(a, b)) {
				--cur;
				cur_res[ind] = 1;
			} else {
				left.push_back({a, b});
			}
		}

		iota(dsu.begin(), dsu.end(), 0);
		for (int i = 0; i < szof(bad_edges); ++i) {
			if (!(mask & (1 << i))) {
				cur -= unite(bad_edges[i].ff.ff, bad_edges[i].ff.ss);
			}
		}

		for (auto [a, b] : left) {
			cur -= unite(a, b);
		}

		if (cur < ans) {
			ans = cur;
			res = cur_res;
		}
	}

	for (int i = 0; i < m; ++i) {
		cout << res[i];
	}
	cout << "\n";
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
	cin >> test_count;
	for (int test = 1; test <= test_count; ++test) {
		solve();
	}

#ifdef LOCAL
	auto end_time = clock();
	cerr << "Execution time: " << (end_time - start_time) * (int)1e3 / CLOCKS_PER_SEC << " ms\n";
#endif
}
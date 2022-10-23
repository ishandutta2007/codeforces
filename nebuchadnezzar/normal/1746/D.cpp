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
	int n, k;
	cin >> n >> k;
	vector<vector<int>> graph(n);
	for (int i = 1; i < n; ++i) {
		int p;
		cin >> p;
		--p;
		graph[p].push_back(i);
	}
	vector<int> coefs;
	for (int i = 0; i < n; ++i) {
		int num;
		cin >> num;
		coefs.push_back(num);
	}

	function<pair<ll, ll>(int, int)> dfs = [&](int v, int pn) {
		if (szof(graph[v]) == 0) {
			// cerr << v + 1 << " " << pn << " " << (ll) pn * coefs[v] << " " << coefs[v] << endl;
			return pair((ll) pn * coefs[v], (ll) coefs[v]);
		}

		ll ret = (ll) pn * coefs[v];
		int q = pn / szof(graph[v]);
		vector<ll> add;

		for (int to : graph[v]) {
			auto tmp = dfs(to, q);
			ret += tmp.ff;
			add.push_back(tmp.ss);
		}

		sort(add.rbegin(), add.rend());
		int last_ind = (pn % szof(graph[v]));
		ret += accumulate(add.begin(), add.begin() + last_ind, 0ll);

		// cerr << v + 1 << " " << pn << " " << ret << " " << coefs[v] + add[last_ind] << endl;
		return pair(ret, coefs[v] + add[last_ind]);
	};

	auto tmp = dfs(0, k);

	cout << tmp.ff << "\n";
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
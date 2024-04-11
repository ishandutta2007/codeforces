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
	vector<vector<int>> graph(n);
	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		--a; --b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	vector<int> parent(n, -1);
	vector<bool> used(n);
	vector<int> depth(n);
	vector<vector<int>> children(n);

	function<void(int)> dfs = [&](int v) {
		used[v] = true;
		for (int to : graph[v]) {
			if (!used[to]) {
				children[v].push_back(to);
				parent[to] = v;
				depth[to] = depth[v] + 1;
				dfs(to);
			}
		}
	};

	dfs(0);

	int q;
	cin >> q;
	vector<vector<int>> paths;
	vector<int> fl(n);
	for (int i = 0; i < q; ++i) {
		int a, b;
		cin >> a >> b;
		--a; --b;
		vector<int> pref, suff;
		while (depth[a] > depth[b]) {
			pref.push_back(a);
			fl[a] ^= 1;
			a = parent[a];
		}
		while (depth[b] > depth[a]) {
			suff.push_back(b);
			fl[b] ^= 1;
			b = parent[b];
		}
		while (a != b) {
			pref.push_back(a);
			fl[a] ^= 1;
			a = parent[a];
			suff.push_back(b);
			fl[b] ^= 1;
			b = parent[b];
		}
		pref.push_back(a);
		reverse(suff.begin(), suff.end());
		pref.insert(pref.end(), suff.begin(), suff.end());
		paths.push_back(pref);
	}

	if (*max_element(fl.begin(), fl.end()) == 0) {
		cout << "YES\n";
		for (auto& path : paths) {
			cout << szof(path) << "\n";
			for (int v : path) {
				cout << v + 1 << " ";
			}
			cout << "\n";
		}
		return;
	}

	cout << "NO\n";

	function<pii(int)> calc_ans = [&](int v) {
		pii ret = {INF, INF};
		ret.ff = 0;
		for (int to : children[v]) {
			auto tmp = calc_ans(to);
			pii new_ret = {INF, INF};
			new_ret.ff = min(ret.ff + tmp.ff, ret.ss + tmp.ss - 1);
			new_ret.ss = min(ret.ss + tmp.ff, ret.ff + tmp.ss);
			ret = new_ret;
		}
		if (fl[v] == 0) {
			return pii(ret.ff, min(ret.ff + 2, ret.ss + 1));
		} else {
			return pii(min(ret.ff + 1, ret.ss), min(ret.ff + 1, ret.ss));
		}
	};

	auto tmp = calc_ans(0);
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
	// cin >> test_count;
	for (int test = 1; test <= test_count; ++test) {
		solve();
	}

#ifdef LOCAL
	auto end_time = clock();
	cerr << "Execution time: " << (end_time - start_time) * (int)1e3 / CLOCKS_PER_SEC << " ms\n";
#endif
}
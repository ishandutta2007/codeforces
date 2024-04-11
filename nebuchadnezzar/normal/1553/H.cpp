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
	vector<int> arr;
	for (int i = 0; i < n; ++i) {
		int num;
		cin >> num;
		arr.push_back(num);
	}

	function<vector<pair<int, pii>>(vector<int>, int, string)> dfs = [&](vector<int> arr, int lvl, string q) {
		if (!szof(arr)) {
			return vector<pair<int, pii>>(1 << (lvl + 1), {INF, {INF, -INF}});
		}
		if (lvl == -1) {
			return vector<pair<int, pii>>(1, {INF, {0, 0}});
		}

		vector<int> to_left, to_right;
		for (int num : arr) {
			if (num & (1 << lvl)) {
				to_right.push_back(num ^ (1 << lvl));
			} else {
				to_left.push_back(num);
			}
		}

		auto from_left = dfs(to_left, lvl - 1, q + "0");
		auto from_right = dfs(to_right, lvl - 1, q + "1");

		vector<pair<int, pii>> ret(1 << (lvl + 1));
		for (int i = 0; i < 1 << lvl; ++i) {
			ret[i].ff = ret[i + (1 << lvl)].ff = min(min(from_left[i].ff, from_right[i].ff), INF);
			ret[i].ff = min(ret[i].ff, from_right[i].ss.ff + (1 << lvl) - from_left[i].ss.ss);
			ret[i + (1 << lvl)].ff = min(ret[i + (1 << lvl)].ff, from_left[i].ss.ff + (1 << lvl) - from_right[i].ss.ss);
			ret[i].ss.ff = min(from_left[i].ss.ff, from_right[i].ss.ff + (1 << lvl));
			ret[i].ss.ss = max(from_right[i].ss.ss + (1 << lvl), from_left[i].ss.ss);
			ret[i + (1 << lvl)].ss.ff = min(from_right[i].ss.ff, from_left[i].ss.ff + (1 << lvl));
			ret[i + (1 << lvl)].ss.ss = max(from_left[i].ss.ss + (1 << lvl), from_right[i].ss.ss);
		}

		// cerr << q << endl;
		// cerr << lvl << endl;
		// for (int num : arr) {
		// 	cerr << num << " ";
		// }
		// cerr << endl;
		// for (auto p : ret) {
		// 	cerr << p.ff << " " << p.ss.ff << " " << p.ss.ss << "    ";
		// }
		// cerr << endl;

		return ret;
	};

	auto res = dfs(arr, k - 1, "");

	for (int i = 0; i < (1 << k); i++) {
		cout << res[i].ff << " ";
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
	// cin >> test_count;
	for (int test = 1; test <= test_count; ++test) {
		solve();
	}

#ifdef LOCAL
	auto end_time = clock();
	cerr << "Execution time: " << (end_time - start_time) * (int)1e3 / CLOCKS_PER_SEC << " ms\n";
#endif
}
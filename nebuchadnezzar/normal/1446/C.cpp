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

struct node {
	int go[2], here;
	node() : here(0) {
		go[0] = go[1] = -1;
	}
};

void solve() {
	int n;
	cin >> n;
	vector<node> trie;
	auto add_node = [&]() {
		trie.push_back(node());
		return szof(trie) - 1;
	};
	int rt = add_node();
	for (int i = 0; i < n; ++i) {
		int num;
		cin >> num;
		int cur = rt;
		for (int j = 29; j >= 0; --j) {
			int d = (num >> j) & 1;
			if (trie[cur].go[d] == -1) {
				trie[cur].go[d] = add_node();
			}
			cur = trie[cur].go[d];
		}
		trie[cur].here = 1;
	}

	function<tuple<int, int, int, int>(int)> dfs = [&](int v) {
		tuple<int, int, int, int> ret = {0, INF, INF, INF};
		if (trie[v].here) {
			ret = {1, 0, INF, INF};
			return ret;
		}
		bool fl = false;
		for (int d = 0; d < 2; ++d) {
			if (trie[v].go[d] != -1) {
				auto tmp = dfs(trie[v].go[d]);
				if (!fl) {
					ret = tmp;
					fl = true;
				} else {
					int n0 = get<0>(ret) + get<0>(tmp);
					int n1 = min(get<0>(ret) + get<1>(tmp), get<1>(ret) + get<0>(tmp));
					int n2 = min({get<0>(ret) + get<2>(tmp), get<1>(ret) + get<2>(tmp), get<2>(ret) + get<0>(tmp), get<2>(ret) + get<1>(tmp), get<2>(ret) + get<2>(tmp)});
					int n3 = min({get<0>(ret) + get<3>(tmp), get<1>(ret) + get<1>(tmp), get<1>(ret) + get<3>(tmp), get<2>(ret) + get<3>(tmp), get<3>(ret) + get<0>(tmp), get<3>(ret) + get<1>(tmp), get<3>(ret) + get<2>(tmp)});
					ret = {n0, n1, n2, n3};
				}
			}
		}
		return ret;
	};

	auto tmp = dfs(rt);
	int ans = min({get<0>(tmp), get<1>(tmp), get<2>(tmp), get<3>(tmp)});
	cout << ans << "\n";
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
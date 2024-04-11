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
	int n;
	cin >> n;
	map<int, pair<int, set<int>>> by_val;
	vector<int> help;
	vector<int> help_ind(n);
	for (int i = 0; i < n; ++i) {
		int num;
		cin >> num;
		if (!by_val.count(num)) {
			by_val[num] = {szof(help), {}};
			help.push_back(num);
		}
		by_val[num].ss.insert(i);
		help_ind[i] = by_val[num].ff;
	}

	auto move_to = [&](int from, int to) {
		auto& p_from = by_val[from];
		if (!by_val.count(to)) {
			by_val[to] = {szof(help), {}};
			help.push_back(to);
		}
		auto& p_to = by_val[to];
		if (szof(p_from.ss) > szof(p_to.ss)) {
			swap(p_from, p_to);
			help[p_to.ff] = to;
		}
		for (int ind : p_from.ss) {
			help_ind[ind] = p_to.ff;
			p_to.ss.insert(ind);
		}
		by_val.erase(from);
	};

	auto get_val = [&](int ind) {
		return help[help_ind[ind]];
	};

	int q;
	cin >> q;
	for (int i = 0; i < q; ++i) {
		int t;
		cin >> t;
		if (t == 1) {
			int k, w;
			cin >> k >> w;
			--k;
			int cur_val = get_val(k);
			by_val[cur_val].ss.erase(k);
			if (!by_val.count(w)) {
				by_val[w] = {szof(help), {}};
				help.push_back(w);
			}
			by_val[w].ss.insert(k);
			help_ind[k] = by_val[w].ff;
		} else if (t == 2) {
			int k;
			cin >> k;
			--k;
			cout << get_val(k) << "\n";
		} else {
			int l, r;
			cin >> l >> r;
			int mid = (l + r) / 2;
			while (true) {
				auto it = by_val.lower_bound(l);
				if (it == by_val.end() || it->ff > r) {
					break;
				}
				if (it->ff <= mid) {
					move_to(it->ff, l - 1);
				} else {
					move_to(it->ff, r + 1);
				}
			}
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
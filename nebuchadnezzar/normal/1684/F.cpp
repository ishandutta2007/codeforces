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

pii comb(pii a, pii b) {
	return {min(a.ff, b.ff), max(a.ss, b.ss)};
}

void solve() {
	int n, m;
	cin >> n >> m;
	vector<int> arr;
	for (int i = 0; i < n; ++i) {
		int num;
		cin >> num;
		arr.push_back(num);
	}

	vector<pii> segs;
	int bpv = 1;
	while (bpv < n) {
		bpv *= 2;
	}
	vector<pii> segtree(bpv * 2, {INF, -INF});
	auto segtree_upd = [&](int l, int r, pii val) {
		l += bpv; r += bpv;
		while (l < r) {
			if (l & 1) {
				segtree[l] = comb(segtree[l], val);
				++l;
			}
			if (r & 1) {
				--r;
				segtree[r] = comb(segtree[r], val);
			}
			l /= 2; r /= 2;
		}
	};

	for (int i = 0; i < m; ++i) {
		int l, r;
		cin >> l >> r;
		--l;
		segs.push_back({l, r});
		segtree_upd(l, r, {l, r});
	}

	for (int i = 1; i < bpv; ++i) {
		segtree[i * 2] = comb(segtree[i * 2], segtree[i]);
		segtree[i * 2 + 1] = comb(segtree[i * 2 + 1], segtree[i]);
	}

	auto cur_arr = arr;
	int cnt = INF;
	int sp_l = 0, sp_r = n;
	map<int, set<int>> where;
	for (int i = 0; i < n; ++i) {
		cur_arr[i] = cnt++;
		where[cur_arr[i]].insert(i);
	}

	auto try_change = [&](int pos, int val) {
		int was = cur_arr[pos];
		cur_arr[pos] = val;
		where[was].erase(pos);
		auto it = where[val].insert(pos).ff;
		auto [l, r] = segtree[pos + bpv];
		if (it != where[val].begin()) {
			auto it2 = it;
			--it2;
			if (l <= *it2) {
				where[val].erase(pos);
				where[was].insert(pos);
				cur_arr[pos] = was;
				return false;
			}
		}
		auto it2 = it;
		++it2;
		if (it2 != where[val].end()) {
			if (*it2 < r) {
				where[val].erase(pos);
				where[was].insert(pos);
				cur_arr[pos] = was;
				return false;
			}
		}
		// cerr << "changed" << endl;
		// for (int num : cur_arr) {
		// 	if (num >= INF) {
		// 		cerr << -1 << " ";
		// 	} else {
		// 		cerr << num << " ";
		// 	}
		// }
		// cerr << endl;
		return true;
	};

	int ans = n;

	for (sp_l = 0; sp_l < n; ++sp_l) {
		while (sp_l < sp_r) {
			if (try_change(sp_r - 1, arr[sp_r - 1])) {
				--sp_r;
			} else {
				break;
			}
		}
		ans = min(ans, sp_r - sp_l);
		if (!ans) {
			break;
		}
		bool ok = false;
		while (sp_r < n) {
			if (try_change(sp_l, arr[sp_l])) {
				ok = true;
				break;
			}
			assert(try_change(sp_r, cnt++));
			++sp_r;
		}
		if (try_change(sp_l, arr[sp_l])) {
			ok = true;
		}
		if (!ok) {
			break;
		}
	}

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
	cin >> test_count;
	for (int test = 1; test <= test_count; ++test) {
		solve();
	}

#ifdef LOCAL
	auto end_time = clock();
	cerr << "Execution time: " << (end_time - start_time) * (int)1e3 / CLOCKS_PER_SEC << " ms\n";
#endif
}
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
	vector<int> arr;
	vector<ll> pref = {0};
	vector<map<ll, vector<int>>> pos_by_val(2);
	for (int i = 0; i < n; ++i) {
		int num;
		cin >> num;
		arr.push_back(num);
		pref.push_back(num - pref.back());
	}

	int bpv = 1;
	while (bpv <= n) {
		bpv *= 2;
	}

	vector<vector<ll>> segtree(2, vector<ll>(bpv * 2, INFL));
	for (int i = 0; i <= n; ++i) {
		segtree[i % 2][bpv + i] = pref[i];
		pos_by_val[i % 2][pref[i]].push_back(i);
	}

	for (int i = bpv - 1; i > 0; --i) {
		segtree[0][i] = min(segtree[0][i * 2], segtree[0][i * 2 + 1]);
		segtree[1][i] = min(segtree[1][i * 2], segtree[1][i * 2 + 1]);
	}

	auto segtree_set = [&](int t, int pos, ll val) {
		pos += bpv;
		segtree[t][pos] = val;
		pos /= 2;
		while (pos) {
			segtree[t][pos] = min(segtree[t][pos * 2], segtree[t][pos * 2 + 1]);
			pos /= 2;
		}
	};

	function<int(int, int, int, int, ll)> segtree_find_less = [&](int t, int v, int vl, int vr, ll val) {
		if (segtree[t][v] >= val) {
			return vr;
		}
		if (vl + 1 == vr) {
			return vl;
		}
		int vm = (vl + vr) / 2;
		int ret = segtree_find_less(t, v * 2, vl, vm, val);
		if (ret == vm) {
			return segtree_find_less(t, v * 2 + 1, vm, vr, val);
		}
		return ret;
	};

	ll ans = 0;

	for (int l = 0; l < n; ++l) {
		int to = n;
		ll val = pref[l];
		to = min(to, segtree_find_less(l % 2, 1, 0, bpv, val));
		to = min(to, segtree_find_less(1 - l % 2, 1, 0, bpv, -val));
		segtree_set(0, l, INFL);
		segtree_set(1, l, INFL);
		auto& arr1 = pos_by_val[l % 2][val];
		ans += upper_bound(arr1.begin(), arr1.end(), to) - lower_bound(arr1.begin(), arr1.end(), l + 1);
		auto& arr2 = pos_by_val[1 - l % 2][-val];
		ans += upper_bound(arr2.begin(), arr2.end(), to) - lower_bound(arr2.begin(), arr2.end(), l);
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
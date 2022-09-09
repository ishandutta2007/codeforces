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
	vector<vector<int>> arr;
	vector<vector<ll>> pref;
	for (int i = 0; i < n; ++i) {
		int t;
		cin >> t;
		arr.push_back({});
		for (int j = 0; j < t; ++j) {
			int num;
			cin >> num;
			arr[i].push_back(num);
		}
		if (szof(arr[i]) > k) {
			arr[i].resize(k);
		}
		pref.push_back({0});
		for (int num : arr[i]) {
			pref[i].push_back(pref[i].back() + num);
		}
	}

	int bpv = 1;
	int bp = 1;
	while (bpv < n) {
		bpv *= 2;
		++bp;
	}

	vector<vector<pair<int, ll>>> here(bpv * 2);

	auto add_seg = [&](int l, int r, int sz, ll val) {
		l += bpv; r += bpv;
		while (l < r) {
			if (l & 1) {
				here[l++].push_back({sz, val});
			}
			if (r & 1) {
				here[--r].push_back({sz, val});
			}
			l /= 2; r /= 2;
		}
	};

	for (int i = 0; i < n; ++i) {
		add_seg(0, i, szof(arr[i]), pref[i].back());
		add_seg(i + 1, n, szof(arr[i]), pref[i].back());
	}

	vector<vector<ll>> mem_layers(bp, vector<ll>(k + 1));
	vector<ll> dp(k + 1, -INFL);
	dp[0] = 0;
	ll ans = 0;

	function<void(int, int, int, int)> dfs = [&](int v, int vl, int vr, int d) {
		copy(dp.begin(), dp.end(), mem_layers[d].begin());
		for (auto obj : here[v]) {
			for (int i = k - obj.ff; i >= 0; --i) {
				dp[i + obj.ff] = max(dp[i + obj.ff], dp[i] + obj.ss);
			}
		}
		if (vl + 1 == vr) {
			if (vl < n) {
				// cerr << vl << endl;
				// for (auto num : dp) {
				// 	cerr << num << " ";
				// }
				// cerr << endl;
				for (int i = 0; i < szof(pref[vl]); ++i) {
					ans = max(ans, dp[k - i] + pref[vl][i]);
				}
			}
			copy(mem_layers[d].begin(), mem_layers[d].end(), dp.begin());
			return;
		}

		int vm = (vl + vr) / 2;
		dfs(v * 2, vl, vm, d + 1);
		dfs(v * 2 + 1, vm, vr, d + 1);
		copy(mem_layers[d].begin(), mem_layers[d].end(), dp.begin());
	};

	dfs(1, 0, bpv, 0);

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
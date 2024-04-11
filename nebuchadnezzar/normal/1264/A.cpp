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
	map<int, int> cnt;
	for (int i = 0; i < n; ++i) {
		int num;
		cin >> num;
		cnt[num]++;
	}
	vector<int> arr;
	for (auto p : cnt) {
		arr.push_back(p.ss);
	}
	reverse(arr.begin(), arr.end());
	vector<int> pref = {0};
	for (int num : arr) {
		pref.push_back(pref.back() + num);
	}
	int cur = 0;
	pair<int, tuple<int, int, int>> ans = {0, {0, 0, 0}};
	for (int i = 0; i < szof(arr); ++i) {
		cur += arr[i];
		assert(pref[i + 1] == cur);
		int pos = upper_bound(pref.begin() + i + 1, pref.end(), cur + cur) - pref.begin() - 1;
		if (pos == szof(arr)) {
			break;
		}
		int pos2 = upper_bound(pref.begin() + pos + 1, pref.end(), pref[pos + 1] + cur) - pref.begin() - 1;
		if (pos2 == szof(arr)) {
			break;
		}
		// cerr << i << " " << pos << " " << pos2 << endl;
		if (pref[pos2 + 1] * 2 > n) {
			break;
		}
		pos2 = upper_bound(pref.begin(), pref.end(), n / 2) - pref.begin() - 2;
		ans = max(ans, {pref[pos2 + 1], {pref[i + 1], pref[pos + 1] - pref[i + 1], pref[pos2 + 1] - pref[pos + 1]}});
	}
	cout << get<0>(ans.ss) << " " << get<1>(ans.ss) << " " << get<2>(ans.ss) << "\n";
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
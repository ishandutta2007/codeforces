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
	for (int i = 0; i < n; ++i) {
		int num;
		cin >> num;
		arr.push_back(num);
	}

	int x;
	cin >> x;
	for (int i = 0; i < n; ++i) {
		arr[i] -= x;
	}
	vector<ll> pref = {0};
	vector<pair<ll, int>> st;
	vector<pii> segs;
	for (int i = 0; i < n; ++i) {
		pref.push_back(pref.back() + arr[i]);
		if (i > 0) {
			pair<ll, int> el = {-pref[i - 1], i - 1};
			while (szof(st) && st.back().ff >= el.ff) {
				st.pop_back();
			}
			st.push_back(el);
			// for (auto p : st) {
			// 	cerr << p.ff << " " << p.ss << "   ";
			// }
			// cerr << endl;
			auto it = lower_bound(st.begin(), st.end(), pair<ll, int>(-pref.back(), -1));
			if (it != st.begin()) {
				--it;
				segs.push_back({it->ss, i + 1});
			}
		}
	}

	sort(segs.begin(), segs.end(), [&](auto& a, auto& b) {
		return a.ss < b.ss;
	});

	int last = -1;
	int ans = 0;

	for (auto [l, r] : segs) {
		if (last < l) {
			++ans;
			last = r - 1;
		}
	}

	cout << n - ans << "\n";
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
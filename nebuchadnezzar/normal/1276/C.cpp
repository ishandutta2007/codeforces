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
	vector<int> amounts;
	for (auto p : cnt) {
		amounts.push_back(p.ss);
	}
	sort(amounts.begin(), amounts.end());
	vector<int> pref = {0};
	for (int num : amounts) {
		pref.push_back(pref.back() + num);
	}
	tuple<int, int, int> ans = {0, 0, 0};
	for (int w = 1; w <= n; ++w) {
		int pos = lower_bound(amounts.begin(), amounts.end(), w) - amounts.begin();
		int maxs = pref[pos] + (szof(amounts) - pos) * w;
		int maxh = maxs / w;
		if (w > maxh) {
			continue;
		}
		ans = max(ans, {w * maxh, w, maxh});
	}
	auto [res, w, h] = ans;
	cout << res << "\n" << w << " " << h << "\n";
	vector<vector<int>> outp(w, vector<int>(h, -1));
	vector<int> order;
	vector<pii> qwe;
	for (auto p : cnt) {
		qwe.push_back({min(p.ss, w), p.ff});
	}

	sort(qwe.begin(), qwe.end());
	for (auto p : qwe) {
		for (int i = 0; i < p.ff; ++i) {
			order.push_back(p.ss);
		}
	}

	for (int i = 0; i < w; ++i) {
		if (outp[i][0] == -1) {
			int x = i, y = 0;
			while (outp[x][y] == -1) {
				outp[x][y] = order.back();
				order.pop_back();
				x = (x + 1) % w;
				y = (y + 1) % h;
			}
		}
	}

	for (int i = 0; i < w; ++i) {
		for (int j = 0; j < h; ++j) {
			cout << outp[i][j] << " ";
		}
		cout << "\n";
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
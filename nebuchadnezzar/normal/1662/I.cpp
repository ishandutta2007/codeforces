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
	vector<int> weight;
	for (int i = 0; i < n; ++i) {
		int num;
		cin >> num;
		weight.push_back(num);
	}
	vector<int> locations;
	for (int i = 0; i < m; ++i) {
		int x;
		cin >> x;
		locations.push_back(x);
	}

	sort(locations.begin(), locations.end());
	ll ans = 0;

	{
		ll tmp = 0;
		for (int i = 0; i < n; ++i) {
			if (i * 100 < locations[0]) {
				tmp += weight[i];
			}
		}
		ans = max(ans, tmp);

		tmp = 0;
		for (int i = 0; i < n; ++i) {
			if (i * 100 > locations[m - 1]) {
				tmp += weight[i];
			}
		}
		ans = max(ans, tmp);
	}

	int cnt = 0;
	for (int i = 0; i < m - 1; ++i) {
		vector<pii> have;
		while (cnt < n && cnt * 100 <= locations[i]) {
			++cnt;
		}
		vector<ll> pref = {0};
		while (cnt < n && cnt * 100 < locations[i + 1]) {
			have.push_back({cnt * 100, weight[cnt]});
			pref.push_back(pref.back() + weight[cnt]);
			++cnt;
		}
		for (int j = 0; j < szof(have); ++j) {
			// x - have[j].ff < have[j].ff - locations[i]
			// x < have[j].ff * 2 - locations[i]
			int x = have[j].ff * 2 - locations[i];
			// locations[i + 1] - have[q].ff > have[q].ff - x
			// have[q].ff < (locations[i + 1] + x) / 2
			int q = lower_bound(have.begin(), have.end(), pii((locations[i + 1] + x + 1) / 2, -1)) - have.begin();
			if (j < q) {
				ans = max(ans, pref[q] - pref[j]);
			}
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
	// cin >> test_count;
	for (int test = 1; test <= test_count; ++test) {
		solve();
	}

#ifdef LOCAL
	auto end_time = clock();
	cerr << "Execution time: " << (end_time - start_time) * (int)1e3 / CLOCKS_PER_SEC << " ms\n";
#endif
}
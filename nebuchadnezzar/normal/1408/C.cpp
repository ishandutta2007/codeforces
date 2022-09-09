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
	int n, l;
	cin >> n >> l;
	vector<int> arr;
	arr.push_back(0);
	for (int i = 0; i < n; ++i) {
		int x;
		cin >> x;
		arr.push_back(x);
	}
	arr.push_back(l);

	int pos1 = 0;
	int v1 = 1;
	double t1 = 0;
	int pos2 = szof(arr) - 1;
	int v2 = 1;
	double t2 = 0;
	double ans = 1e100;
	while (pos1 <= pos2) {
		// cerr << pos1 << " " << v1 << " " << t1 << " " << pos2 << " " << v2 << " " << t2 << endl;
		if (pos1 <= pos2) {
			double x1 = arr[pos1] - v1 * t1;
			double x2 = arr[pos2] + v2 * t2;
			ans = min(ans, (x2 - x1) / (v1 + v2));
		}
		if (pos1 == pos2) {
			break;
		}
		double next_t1 = t1 + (arr[pos1 + 1] - arr[pos1]) / (double) v1;
		double next_t2 = t2 + (arr[pos2] - arr[pos2 - 1]) / (double) v2;

		if (next_t1 < next_t2) {
			t1 = next_t1;
			++pos1;
			++v1;
		} else {
			t2 = next_t2;
			--pos2;
			++v2;
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
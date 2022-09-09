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
	vector<map<int, int>> inp;

	for (int i = 0; i < n; ++i) {
		int num;
		cin >> num;
		map<int, int> cnt;
		for (int j = 2; j * j <= num; ++j) {
			while (num % j == 0) {
				cnt[j]++;
				num /= j;
			}
		}
		if (num > 1) {
			cnt[num]++;
		}
		
		inp.push_back(cnt);
	}

	set<int> primes;

	for (int i = 0; i < 2; ++i) {
		for (auto p : inp[i]) {
			primes.insert(p.ff);
		}
	}

	ll ans = 1;

	for (int p : primes) {
		int lowest = INF, second_lowest = INF;
		auto add = [&](int val) {
			if (val < lowest) {
				second_lowest = lowest;
				lowest = val;
			} else if (val < second_lowest) {
				second_lowest = val;
			}
		};
		for (int i = 0; i < n; ++i) {
			if (!inp[i].count(p)) {
				add(0);
			} else {
				add(inp[i][p]);
			}
		}

		for (int i = 0; i < second_lowest; ++i) {
			ans *= p;
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
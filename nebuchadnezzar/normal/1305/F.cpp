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
auto start_clock = clock();

bool is_prime(int num) {
	for (int i = 2; i * i <= num; ++i) {
		if (num % i == 0) {
			return false;
		}
	}
	return true;
}


void solve() {
	int n;
	cin >> n;
	vector<ll> arr;
	ll tot_gcd = 0;
	for (int i = 0; i < n; ++i) {
		ll num;
		cin >> num;
		tot_gcd = __gcd(tot_gcd, num);
		arr.push_back(num);
	}

	set<ll> checked;

	auto calc = [&](ll p) {
		if (!checked.insert(p).ss) {
			return INFL;
		}
		ll ret = 0;
		for (ll num : arr) {
			ll tmp = num % p;
			if (tmp == num) {
				ret += p - num;
			} else {
				ret += min(p - tmp, tmp);
			}
		}
		return ret;
	};

	int ans = INF;
	if (tot_gcd != 1) {
		ans = 0;
	}

	for (int i = 2; i < 300; ++i) {
		if (is_prime(i)) {
			ans = min((ll) ans, calc(i));
		}
	}

	while (clock() - start_clock < CLOCKS_PER_SEC * 2.3) {
		ll tmp = arr[rnd(0, n - 1)] + rnd(-1, 1);
		if (tmp <= 0) {
			continue;
		}
		for (ll i = 2; i * i <= tmp; ++i) {
			if (tmp % i == 0) {
				ans = min((ll) ans, calc(i));
				while (tmp % i == 0) {
					tmp /= i;
				}
			}
		}
		if (tmp > 1) {
			ans = min((ll) ans, calc(tmp));
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
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

bool check(ll n, ll k) {
	if (k > INF || k == 1) {
		return false;
	}
	ll tmp = k * (k + 1) / 2;
	return tmp <= n && (n - tmp) % k == 0;
}

vector<int> primes;

void solve() {
	ll n;
	cin >> n;
	ll q = n;
	while (q % 2 == 0) {
		q /= 2;
	}
	ll x = n / q * 2;
	for (ll k = 1; ; ++k) {
		int cnt = 0;
		if (k * x < INF) {
			++cnt;
			ll tmp = k * x * (k * x + 1) / 2;
			if (tmp <= n && (n - tmp) % (k * x) == 0) {
				assert(check(n, k * x));
				cout << k * x << "\n";
				return;
			}
		}

		if (k * k <= q) {
			++cnt;
			if (check(n, k)) {
				cout << k << "\n";
				return;
			}
			if (check(n, q / k)) {
				cout << q / k << "\n";
				return;
			}
		}

		if (!cnt) {
			break;
		}
	}

	cout << "-1\n";
}

bool is_prime(int num) {
	for (int i = 2; i * i <= num; ++i) {
		if (num % i == 0) {
			return false;
		}
	}
	return true;
}

int main() {
#ifdef LOCAL
	auto start_time = clock();
	cerr << setprecision(3) << fixed;
#endif
	cout << setprecision(15) << fixed;
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	for (int i = 3; i < 1e5; ++i) {
		if (is_prime(i)) {
			primes.push_back(i);
		}
	}

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
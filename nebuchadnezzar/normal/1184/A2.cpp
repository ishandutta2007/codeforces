// Created by Nikolay Budin

#ifdef DEBUG
#  define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
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
	string s;
	cin >> s;

	int ans = 0;

	auto check = [&](int l) {
		int num = n / l;
		vector<int> res(num);
		for (int i = 0; i < n; ++i) {
			res[i % num] ^= s[i] - '0';
		}
		for (int i = 0; i < num; ++i) {
			if (res[i]) {
				return;
			}
		}
		for (int i = 1; i <= l; ++i) {
			if (__gcd(i, l) == 1) {
				// cerr << l << " " << i << endl;
				++ans;
			}
		}
	};

	for (int i = 1; i * i <= n; ++i) {
		if (n % i == 0) {
			check(i);
			if (n / i > i) {
				check(n / i);
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
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
	ll k;
	cin >> k;
	--k;
	ll sum = 0;
	ll sumpln = 0;
	ll amount = 9;
	int ln;
	for (ln = 1; ; ++ln) {
		if (sum + sumpln * amount + amount * (amount + 1) / 2 * ln > k) {
			break;
		}
		sum += sumpln * amount + amount * (amount + 1) / 2 * ln;
		sumpln += amount * ln;
		amount *= 10;
	}
	ll l = 0, r = amount;
	while (r - l > 1) {
		ll mid = (l + r) / 2;
		if (sum + sumpln * mid + mid * (mid + 1) / 2 * ln > k) {
			r = mid;
		} else {
			l = mid;
		}
	}
	sum += sumpln * l + l * (l + 1) / 2 * ln;
	l = 0, r = k - sum + 5;
	ll lastres = 0;
	while (r - l > 1) {
		ll mid = (l + r) / 2;
		ll res = 0;
		for (ll from = 1, len = 1; ; from *= 10, ++len) {
			if (from * 10 > mid) {
				res += (mid - from + 1) * len;
				break;
			} else {
				res += from * 9 * len;
			}
		}
		if (sum + res > k) {
			r = mid;
		} else {
			lastres = res;
			l = mid;
		}
	}
	sum += lastres;
	ll tmp = r;
	vector<int> rarr;
	while (tmp) {
		rarr.push_back(tmp % 10);
		tmp /= 10;
	}
	reverse(rarr.begin(), rarr.end());
	cout << rarr[k - sum] << "\n";
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
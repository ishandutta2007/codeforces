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
	vector<int> arr;
	for (int i = 0; i < n; ++i) {
		int p;
		cin >> p;
		arr.push_back(p);
	}

	int x, a;
	cin >> x >> a;
	int y, b;
	cin >> y >> b;

	if (x > y) {
		swap(x, y);
		swap(a, b);
	}

	ll k;
	cin >> k;

	int l = 0, r = n + 1;
	vector<int> tmp(n);
	ll lcm = (ll) a * b / __gcd(a, b);
	while (r - l > 1) {
		int mid = (l + r) / 2;
		copy(arr.begin(), arr.end(), tmp.begin());
		int nab = mid / lcm;
		int na = mid / a - nab;
		int nb = mid / b - nab;
		nth_element(tmp.begin(), tmp.end() - na - nb - nab, tmp.end());
		nth_element(tmp.end() - na - nb - nab, tmp.end() - nb - nab, tmp.end());
		nth_element(tmp.end() - nb - nab, tmp.end() - nab, tmp.end());
		ll sum = 0;
		for (int i = n - na - nb - nab; i < n - nb - nab; ++i) {
			sum += tmp[i] / 100 * x;
		}
		for (int i = n - nb - nab; i < n - nab; ++i) {
			sum += tmp[i] / 100 * y;
		}
		for (int i = n - nab; i < n; ++i) {
			sum += tmp[i] / 100 * (x + y);
		}

		if (sum >= k) {
			r = mid;
		} else {
			l = mid;
		}
	}

	if (r == n + 1) {
		cout << "-1\n";
	} else {
		cout << r << "\n";
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
	cin >> test_count;
	for (int test = 1; test <= test_count; ++test) {
		solve();
	}
	
#ifdef LOCAL
	auto end_time = clock();
	cerr << "Execution time: " << (end_time - start_time) * (int)1e3 / CLOCKS_PER_SEC << " ms\n";
#endif
}
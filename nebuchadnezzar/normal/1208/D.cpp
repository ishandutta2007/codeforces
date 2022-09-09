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
	vector<ll> arr;
	for (int i = 0; i < n; ++i) {
		ll num;
		cin >> num;
		arr.push_back(num);
	}

	vector<ll> data(n);

	auto addval = [&](int pos, ll val) {
		while (pos < n) {
			data[pos] += val;
			pos |= (pos + 1);
		}
	};

	auto getsum = [&](int pos) {
		ll ret = 0;
		while (pos) {
			ret += data[pos - 1];
			pos = pos & (pos - 1);
		}
		return ret;
	};

	for (int i = 0; i < n; ++i) {
		addval(i, i + 1);
	}

	vector<int> ans(n);

	for (int i = n - 1; i >= 0; --i) {
		int l = 0, r = n;
		while (r - l > 1) {
			int mid = (l + r) / 2;
			if (getsum(mid) > arr[i]) {
				r = mid;
			} else {
				l = mid;
			}
		}
		ans[i] = l;
		addval(l, -l - 1);
	}

	for (int ind : ans) {
		cout << ind + 1 << " ";
	}
	cout << "\n";
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
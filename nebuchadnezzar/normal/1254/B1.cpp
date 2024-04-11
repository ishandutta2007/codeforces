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
		int num;
		cin >> num;
		arr.push_back(num);
	}

	ll ans = INFL;
	ll sum = accumulate(arr.begin(), arr.end(), 0ll);
	vector<int> tmp_arr(n);
	auto calc = [&](ll in_one) {
		copy(arr.begin(), arr.end(), tmp_arr.begin());
		for (int& num : tmp_arr) {
			num %= in_one;
		}
		int pos = 0;
		ll res = 0;
		int groups = accumulate(tmp_arr.begin(), tmp_arr.end(), 0ll) / in_one;
		for (int i = 0; i < groups; ++i) {
			ll cur = 0;
			int from = pos;
			while (cur < in_one) {
				cur += tmp_arr[pos];
				++pos;
			}
			int left = cur - in_one;
			--pos;
			tmp_arr[pos] -= left;
			int l = from, r = pos;
			// cerr << l << " " << r << endl;
			ll sum_l = 0, sum_r = 0;
			while (l < r) {
				if (sum_l + tmp_arr[l] < sum_r + tmp_arr[r]) {
					sum_l += tmp_arr[l];
					++l;
				} else {
					sum_r += tmp_arr[r];
					--r;
				}
			}
			for (int j = from; j <= pos; ++j) {
				res += (ll) tmp_arr[j] * abs(j - l);
				if (res > ans) {
					return res;
				}
				tmp_arr[j] = 0;
			}

			tmp_arr[pos] = left;
		}
		// cerr << "calc " << in_one << " " << res << endl;
		return res;
	};


	for (ll num = 1; num * num <= sum; ++num) {
		if (sum % num == 0) {
			if (num != 1) {
				ans = min(ans, calc(num));
			}
			if (num * num < sum && sum / num != 1) {
				ans = min(ans, calc(sum / num));
			}
		}
	}

	if (ans != INFL) {
		cout << ans << "\n";
	} else {
		cout << "-1\n";
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
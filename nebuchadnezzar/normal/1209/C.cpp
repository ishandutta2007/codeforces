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
	vector<int> arr;
	for (char c : s) {
		arr.push_back(c - '0');
	}
	for (int d = 0; d < 10; ++d) {
		vector<int> arr1, arr2;
		int last1 = -1, first2 = n;
		vector<int> ans(n);
		for (int i = 0; i < n; ++i) {
			if (arr[i] < d) {
				last1 = i;
				arr1.push_back(arr[i]);
				ans[i] = 1;
			}
			if (d < arr[i]) {
				if (first2 == n) {
					first2 = i;
				}
				arr2.push_back(arr[i]);
				ans[i] = 2;
			}
		}
		if (!is_sorted(arr1.begin(), arr1.end()) || !is_sorted(arr2.begin(), arr2.end())) {
			continue;
		}
		bool ok = true;
		for (int i = 0; i < n; ++i) {
			if (arr[i] == d) {
				if (i < first2) {
					ans[i] = 2;
				} else if (last1 < i) {
					ans[i] = 1;
				} else {
					ok = false;
					break;
				}
			}
		}

		if (!ok) {
			continue;
		}

		for (int num : ans) {
			cout << num;
		}
		cout << "\n";
		return;
	}
	cout << "-\n";
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
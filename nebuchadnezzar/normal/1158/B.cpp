// Created by Nikolay Budin

#ifdef LOCAL
#  define _GLIBCXX_DEBUG
#else
#  define cerr __get_ce
#endif
#include <bits/stdc++.h>
#define ff first
#define ss second
#define szof(x) ((int)x.size())

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
	int n, k;
	cin >> n >> k;
	// assert(n % 2 == k % 2);
	// for (int i = 0; i < 1 << n; ++i) {
	// 	vector<int> s(n);
	// 	for (int j = 0; j < n; ++j) {
	// 		s[j] = (i >> j) & 1;
	// 	}
	// 	vector<map<vector<int>, int>> have(n + 1);
	// 	for (int j = 0; j < n; ++j) {
	// 		vector<int> cur;
	// 		for (int q = j; q < n; ++q) {
	// 			cur.push_back(s[q]);
	// 			have[szof(cur)][cur]++;
	// 		}
	// 	}
	// 	for (int j = 1; j <= n; ++j) {
	// 		bool found = false;
	// 		for (auto p : have[j]) {
	// 			if (p.ss == 1) {
	// 				found = true;
	// 				break;
	// 			}
	// 		}
	// 		if (found && j < k) {
	// 			break;
	// 		}
	// 		if (j == k && !found) {
	// 			break;
	// 		}
	// 		if (j == k) {
	// 			for (int num : s) {
	// 				cerr << num;
	// 			}
	// 			cerr << endl;
	// 			break;
	// 		}
	// 	}
	// }
	vector<int> ans;
	if (k == 1) {
		ans.resize(n);
		ans[0] = 1;
	} else {
		for (int i = 0; i < n; ++i) {
			if (i % ((n - k) / 2 + 1) == 0) {
				ans.push_back(1);
			} else {
				ans.push_back(0);
			}
		}
	}

	for (int num : ans) {
		cout << num;
	}
	cout << endl;

	// vector<map<vector<int>, int>> have(n + 1);
	// for (int j = 0; j < n; ++j) {
	// 	vector<int> cur;
	// 	for (int q = j; q < n; ++q) {
	// 		cur.push_back(ans[q]);
	// 		have[szof(cur)][cur]++;
	// 	}
	// }
	// for (int j = 1; j <= n; ++j) {
	// 	bool found = false;
	// 	for (auto p : have[j]) {
	// 		if (p.ss == 1) {
	// 			found = true;
	// 			break;
	// 		}
	// 	}
	// 	if (found && j < k) {
	// 		assert(false);
	// 	}
	// 	if (j == k && !found) {
	// 		assert(false);
	// 	}
	// 	if (j == k) {
	// 		break;
	// 	}
	// }
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
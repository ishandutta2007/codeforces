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

	vector<vector<int>> groups(1, vector<int>(n + 1));
	iota(groups[0].begin(), groups[0].end(), 0);
	vector<vector<int>> ans(n + 1, vector<int>(n, -1));
	for (int i = 0; i < n; ++i) {
		while (szof(groups) && szof(groups.back()) == 1) {
			groups.pop_back();
		}
		assert(szof(groups));
		int cnt = 0;
		int pos;
		for (pos = 0; pos < szof(groups.back()) - 1 && cnt < arr[i]; ++pos) {
			ans[groups.back()[pos]][i] = 1;
			++cnt;
		}
		vector<int> tmp;
		while (szof(groups.back()) > pos) {
			int el = groups.back().back();
			ans[el][i] = 0;
			tmp.push_back(el);
			groups.back().pop_back();
		}
		groups.push_back(tmp);
		for (int j = 0; j < n + 1; ++j) {
			if (ans[j][i] == -1) {
				if (cnt < arr[i]) {
					ans[j][i] = 1;
					++cnt;
				} else {
					ans[j][i] = 0;
				}
			}
		}
	}
	while (szof(groups) && szof(groups.back()) == 1) {
		groups.pop_back();
	}
	assert(!szof(groups));

	cout << n + 1 << "\n";
	for (int i = 0; i < n + 1; ++i) {
		for (int j = 0; j < n; ++j) {
			cout << ans[i][j];
		}
		cout << "\n";
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
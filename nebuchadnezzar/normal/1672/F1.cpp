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
	map<int, vector<int>> by_val;
	for (int i = 0; i < n; ++i) {
		int num;
		cin >> num;
		by_val[num].push_back(i);
		arr.push_back(num);
	}
	vector<int> cycle;
	set<pii> have;
	for (auto& v : by_val) {
		have.insert({szof(v.ss), v.ff});
	}

	while (szof(have)) {
		auto it = --have.end();
		if (szof(have) > 1 && szof(cycle)) {
			auto it2 = it;
			--it2;
			if (arr[cycle.back()] == it->ss || (szof(cycle) == n - 2 && arr[cycle.back()] != it2->ss && arr[cycle.front()] == it2->ss)) {
				it = it2;
			}
		}
		int val = it->ss;
		have.erase(it);
		cycle.push_back(by_val[val].back());
		by_val[val].pop_back();
		if (szof(by_val[val])) {
			have.insert({szof(by_val[val]), val});
		}
	}

	vector<int> ans(n);
	for (int i = 0; i < n; ++i) {
		int next = (i + 1) % n;
		ans[cycle[i]] = arr[cycle[next]];
	}

	for (int i = 0; i < n; ++i) {
		cout << ans[i] << " ";
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
	cin >> test_count;
	for (int test = 1; test <= test_count; ++test) {
		solve();
	}
	
#ifdef LOCAL
	auto end_time = clock();
	cerr << "Execution time: " << (end_time - start_time) * (int)1e3 / CLOCKS_PER_SEC << " ms\n";
#endif
}
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
	vector<pii> inp;
	for (int i = 0; i < n; ++i) {
		int d;
		cin >> d;
		inp.push_back({d, i});
	}

	sort(inp.rbegin(), inp.rend());
	vector<int> order;
	vector<pii> edges;
	for (auto p : inp) {
		if (szof(order)) {
			edges.push_back({order.back(), p.ss * 2});
		}
		order.push_back(p.ss * 2);
	}
	for (int i = 0; i < n; ++i) {
		auto p = inp[i];
		int to = i + p.ff;
		edges.push_back({p.ss * 2 + 1, order[to - 1]});
		if (to == szof(order)) {
			order.push_back(p.ss * 2 + 1);
		}
	}

	for (auto e : edges) {
		cout << e.ff + 1 << " " << e.ss + 1 << "\n";
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
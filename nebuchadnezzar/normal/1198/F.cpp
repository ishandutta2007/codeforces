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
	int n;
	cin >> n;
	vector<pii> inp;
	for (int i = 0; i < n; ++i) {
		int num;
		cin >> num;
		inp.push_back({num, i});
	}

	vector<int> ans(n);
	while (clock() < 0.4 * CLOCKS_PER_SEC) {
		shuffle(inp.begin(), inp.end(), tw);
		int part1 = 0, part2 = 0;
		for (auto p : inp) {
			if (part1 == 0 || p.ff % part1 != 0) {
				ans[p.ss] = 0;
				part1 = __gcd(part1, p.ff);
			} else {
				ans[p.ss] = 1;
				part2 = __gcd(part2, p.ff);
			}
		}
		if (part1 == 1 && part2 == 1) {
			cout << "YES\n";
			for (int num : ans) {
				cout << num + 1 << " ";
			}
			cout << "\n";
			return;
		}
	}

	cout << "NO\n";
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
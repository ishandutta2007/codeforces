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
	string s;
	cin >> s;
	int cnt = 0;
	for (char c : s) {
		if (c != 'a') {
			++cnt;
		}
	}

	if (cnt % 2 == 1) {
		cout << ":(\n";
		return;
	}

	string s1 = "", s2 = "";
	string tmp = "";

	int cnt2 = 0;
	for (char c : s) {
		if (cnt2 < cnt / 2 || (cnt2 == cnt / 2 && c == 'a')) {
			s1 += c;
			if (c != 'a') {
				tmp += c;
				++cnt2;
			}
		} else {
			s2 += c;
			++cnt2;
		}
	}

	if (tmp != s2) {
		cout << ":(\n";
		return;
	}
	cout << s1 << "\n";
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
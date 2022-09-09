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
	int a, b;
	cin >> a >> b;
	string s;
	cin >> s;
	vector<int> segs;
	int from = 0;
	for (int i = 0; i <= szof(s); ++i) {
		if (i == szof(s) || s[i] == 'X') {
			if (from < i) {
				segs.push_back(i - from);
			}
			from = i + 1;
		}
	}
	multiset<int> have;
	for (int l : segs) {
		if (l >= b) {
			have.insert(l);
		}
	}

	for (int l : segs) {
		if (l >= a) {
			auto mem = have;
			have.erase(have.find(l));
			for (int i = 0; i + a <= l; ++i) {
				if (i >= b) {
					have.insert(i);
				}
				if (l - i - a >= b) {
					have.insert(l - i - a);
				}
				if (!szof(have)) {
					cout << "YES\n";
					return;
				}
				if (*--have.end() >= b * 2) {
					// :(
				} else {
					if (*have.begin() < a) {
						// :(
					} else {
						if (szof(have) % 2 == 0) {
							cout << "YES\n";
							return;
						}
					}
				}

				if (i >= b) {
					have.erase(have.find(i));
				}
				if (l - i - a >= b) {
					have.erase(have.find(l - i - a));
				}
			}

			have.insert(l);

			assert(mem == have);
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
	cin >> test_count;
	for (int test = 1; test <= test_count; ++test) {
		solve();
	}
	
#ifdef LOCAL
	auto end_time = clock();
	cerr << "Execution time: " << (end_time - start_time) * (int)1e3 / CLOCKS_PER_SEC << " ms\n";
#endif
}
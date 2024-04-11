// Created by Nikolay Budin

#ifdef LOCAL
#  define _GLIBCXX_DEBUG
#else
// #  define cerr __get_ce
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

void solve(string s);

void stress() {
	for (int test = 0; ; ++test) {
		if (test % 1000 == 0) {
			cerr << "test " << test << endl;
		}
		string s;
		// cin >> s;
		int len = rnd(2, 100);
		char prev = 'd';
		for (int i = 0; i < len; ++i) {
			char c;
			while (true) {
				c = 'a' + rnd(0, 2);
				if (c != prev) {
					break;
				}
			}
			s += c;
			prev = c;
		}

		solve(s);
	}
}

void solve(string s) {
	if (szof(s) < 20) {
		for (int i = 0; i < 1 << szof(s); ++i) {
			string res = "";
			for (int j = 0; j < szof(s); ++j) {
				if (i & (1 << j)) {
					res += s[j];
				}
			}
			string rev = res;
			reverse(rev.begin(), rev.end());
			if (res == rev && szof(res) >= szof(s) / 2) {
				cout << res << "\n";
				return;
			}
		}

		cout << "-1\n";
		return;
	}

	for (int pos = max(0, szof(s) / 2 - 5); pos < min(szof(s) / 2 + 5, szof(s)); ++pos) {
		string res = "";
		res += s[pos];
		int l = pos - 1;
		int r = pos + 1;
		while (0 <= l && r < szof(s)) {
			if (s[l] == s[r]) {
				res += s[r];
				--l; ++r;
				continue;
			}
			bool found = false;
			int l0 = l, r0 = r;
			while (0 < l0 || r0 < szof(s) - 1) {
				if (l0 < szof(s) - r0 - 1) {
					++r0;
					for (int l1 = l; l1 >= l0; --l1) {
						if (s[l1] == s[r0]) {
							l = l1;
							r = r0;
							found = true;
							break;
						}
					}
				} else {
					--l0;
					for (int r1 = r; r1 <= r0; ++r1) {
						if (s[l0] == s[r1]) {
							l = l0;
							r = r1;
							found = true;
							break;
						}
					}
				}

				if (found) {
					break;
				}
			}

			if (!found) {
				break;
			}

			assert(s[l] == s[r]);
			res += s[r];
			--l; ++r;
		}

		if (szof(res) * 2 - 1 >= szof(s) / 2) {
			string tmp = res;
			reverse(tmp.begin(), tmp.end());
			tmp.pop_back();
			string ans = tmp + res;
			assert(szof(ans) >= szof(s) / 2);
			int cnt = 0;
			for (int q = 0; q < szof(s); ++q) {
				if (cnt < szof(ans) && ans[cnt] == s[q]) {
					++cnt;
				}
			}
			assert(cnt == szof(ans));
			cout << ans << "\n";
			return;
		}
	}

	cout << "-1\n";
	assert(false);
}


int main() {
#ifdef LOCAL
	auto start_time = clock();
	cerr << setprecision(3) << fixed;
#endif
	cout << setprecision(15) << fixed;
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	// stress();

	int test_count = 1;
	// cin >> test_count;
	for (int test = 1; test <= test_count; ++test) {
		string s;
		cin >> s;
		solve(s);
	}
	
#ifdef LOCAL
	auto end_time = clock();
	cerr << "Execution time: " << (end_time - start_time) * (int)1e3 / CLOCKS_PER_SEC << " ms\n";
#endif
}
// Created by Nikolay Budin

#ifdef DEBUG
#  define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
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

using namespace __gnu_pbds;
template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename K, typename V> using ordered_map = tree<K, V, less<K>, rb_tree_tag, tree_order_statistics_node_update>;

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
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	string s;
	cin >> s;
	if (count(s.begin(), s.end(), 'A') != a + c + d) {
		cout << "NO\n";
		return;
	}
	if (count(s.begin(), s.end(), 'B') != b + c + d) {
		cout << "NO\n";
		return;
	}

	int cnt_ab = 0;
	int cnt_ba = 0;
	vector<int> type1, type0, type2;

	auto f = [&](string part) {
		// cerr << part << endl;
		vector<pii> ret;
		if (part[0] == 'A') {
			if (szof(part) % 2 == 0) {
				cnt_ab += szof(part) / 2;
				type0.push_back(szof(part) / 2);
			} else {
				cnt_ab += szof(part) / 2;
				type1.push_back(szof(part) / 2);
			}
		} else {
			if (szof(part) % 2 == 0) {
				cnt_ab += szof(part) / 2 - 1;
				type2.push_back(szof(part) / 2 - 1);
				if (szof(part) == 2) {
					++cnt_ba;
				}
			} else {
				cnt_ab += szof(part) / 2;
				type1.push_back(szof(part) / 2);
			}
		}
	};

	string last;
	for (int i = 0; i <= szof(s); ++i) {
		if (szof(last) && (i == szof(s) || last.back() == s[i])) {
			f(last);
			last.clear();
		}
		if (i < szof(s)) {
			last += s[i];
		}
	}

	sort(type2.rbegin(), type2.rend());
	sort(type0.begin(), type0.end());

	while (cnt_ab > c) {
		if (szof(type2)) {
			int num = type2.back();
			type2.pop_back();
			for (int i = 0; i < num && cnt_ab > c; ++i) {
				--cnt_ab;
				++cnt_ba;
				if (i == num - 1) {
					++cnt_ba;
				}
			}
		} else if (szof(type1)) {
			int num = type1.back();
			type1.pop_back();
			for (int i = 0; i < num && cnt_ab > c; ++i) {
				--cnt_ab;
				++cnt_ba;
			}
		} else if (szof(type0)) {
			int num = type0.back();
			type0.pop_back();
			for (int i = 0; i < num && cnt_ab > c; ++i) {
				--cnt_ab;
				if (i) {
					++cnt_ba;
				}
			}
		} else {
			assert(false);
		}
	}

	if (cnt_ab >= c && cnt_ba >= d) {
		cout << "YES\n";
	} else {
		cout << "NO\n";
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
	cin >> test_count;
	for (int test = 1; test <= test_count; ++test) {
		solve();
	}

#ifdef LOCAL
	auto end_time = clock();
	cerr << "Execution time: " << (end_time - start_time) * (int)1e3 / CLOCKS_PER_SEC << " ms\n";
#endif
}
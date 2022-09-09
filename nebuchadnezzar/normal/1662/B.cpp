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

vector<int> get_cnt(string s) {
	vector<int> ret(26);
	for (char c : s) {
		ret[c - 'A']++;
	}
	return ret;
}

void solve() {
	string s1, s2, s3;
	cin >> s1 >> s2 >> s3;
	auto cnta = get_cnt(s1);
	auto cntb = get_cnt(s2);
	auto cntc = get_cnt(s3);

	vector<pair<char, char>> ans;
	// for (int i = 0; i < 26; ++i) {
	// 	int q = min({cnta[i], cntb[i], cntc[i]});
	// 	for (int j = 0; j < q; ++j) {
	// 		ans.push_back({'A' + i, 'A' + i});
	// 	}
	// 	cnta[i] -= q;
	// 	cntb[i] -= q;
	// 	cntc[i] -= q;
	// }

	vector<char> eq_bc;
	vector<char> eq_ab, eq_ac;
	for (int i = 0; i < 26; ++i) {
		while (true) {
			if (cnta[i] < cntb[i] && cnta[i] < cntc[i]) {
				if (min(cntb[i], cntc[i]) == 0) {
					break;
				}
				eq_bc.push_back('A' + i);
				cntb[i]--; cntc[i]--;
			} else if (cntb[i] <= cnta[i] && cntb[i] < cntc[i]) {
				if (min(cnta[i], cntc[i]) == 0) {
					break;
				}
				eq_ac.push_back('A' + i);
				cnta[i]--; cntc[i]--;
			} else if (cntc[i] <= cnta[i] && cntc[i] <= cntb[i]) {
				if (min(cnta[i], cntb[i]) == 0) {
					break;
				}
				eq_ab.push_back('A' + i);
				cnta[i]--; cntb[i]--;
			} else {
				assert(false);
			}
		}
	}

	for (int i = 0; i < 26; ++i) {
		while (cnta[i] && szof(eq_bc)) {
			// cerr << "a " << (char) ('A' + i) << " bc " << eq_bc.back() << endl;
			ans.push_back({'A' + i, eq_bc.back()});
			eq_bc.pop_back();
			--cnta[i];
		}

		while (cntb[i] && szof(eq_ac)) {
			// cerr << "b " << (char) ('A' + i) << " ac " << eq_ac.back() << endl;
			ans.push_back({'A' + i, eq_ac.back()});
			eq_ac.pop_back();
			--cntb[i];
		}

		while (cntc[i] && szof(eq_ab)) {
			// cerr << "c " << (char) ('A' + i) << " ab " << eq_ab.back() << endl;
			ans.push_back({'A' + i, eq_ab.back()});
			eq_ab.pop_back();
			--cntc[i];
		}
	}

	// assert(szof(eq_ab) == szof(eq_bc) && szof(eq_bc) == szof(eq_ac));

	while(szof(eq_ab) && szof(eq_ac) && szof(eq_bc)) {
		char x = eq_ab.back();
		eq_ab.pop_back();
		char y = eq_ac.back();
		eq_ac.pop_back();
		char z = eq_bc.back();
		eq_bc.pop_back();

		ans.push_back({x, y});
		ans.push_back({x, z});
	}

	for (char c : eq_ab) {
		cnta[c - 'A']++;
		cntb[c - 'A']++;
	}

	for (char c : eq_ac) {
		cnta[c - 'A']++;
		cntc[c - 'A']++;
	}

	for (char c : eq_bc) {
		cntb[c - 'A']++;
		cntc[c - 'A']++;
	}

	vector<vector<char>> left(3);
	for (int i = 0; i < 26; ++i) {
		for (int j = 0; j < cnta[i]; ++j) {
			left[0].push_back('A' + i);
		}
		for (int j = 0; j < cntb[i]; ++j) {
			left[1].push_back('A' + i);
		}
		for (int j = 0; j < cntc[i]; ++j) {
			left[2].push_back('A' + i);
		}
	}

	while (szof(left[0]) || szof(left[1]) || szof(left[2])) {
		sort(left.begin(), left.end(), [&](auto& a, auto& b) {
			return szof(a) > szof(b);
		});
		char x = left[0].back();
		left[0].pop_back();
		char y = x;
		if (szof(left[1])) {
			y = left[1].back();
			left[1].pop_back();
		}
		ans.push_back({x, y});
	}

	cout << szof(ans) << "\n";
	for (auto [a, b] : ans) {
		cout << a << b << "\n";
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
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
	string s;
	cin >> s;
	for (char& c : s) {
		if (c != 'o' && c != 'n' && c != 'e' && c != 't' && c != 'w') {
			c = 'a';
		}
	}

	map<string, int> inds;

	auto get_ind = [&](string s) {
		if (!inds.count(s)) {
			int tmp = szof(inds);
			inds[s] = tmp;
		}
		return inds[s];
	};

	vector<vector<int>> go(57, vector<int>(250, -1));

	function<void(string)> rec = [&](string s) {
		if (szof(s) == 3) {
			return;
		}
		int cur = get_ind(s);
		for (char c : "onetwa") {
			s += c;
			if (s == "one" || s == "two") {

			} else {
				if (szof(s) == 3) {
					auto tmp = s;
					tmp.erase(tmp.begin());
					go[cur][c] = get_ind(tmp);
				} else {
					go[cur][c] = get_ind(s);
					rec(s);
				}
			}
			s.pop_back();
		}
	};
	rec("");
	vector<vector<int>> dp(szof(s) + 1, vector<int>(szof(inds), INF));
	dp[0][0] = 0;
	vector<vector<pair<int, bool>>> from(szof(s) + 1, vector<pair<int, bool>>(szof(inds)));
	for (int i = 0; i < szof(s); ++i) {
		for (int j = 0; j < szof(inds); ++j) {
			int& val = dp[i + 1][j];
			if (val > dp[i][j] + 1) {
				val = dp[i][j] + 1;
				from[i + 1][j] = {j, 1};
			}
			
			if (go[j][s[i]] == -1) {
				continue;
			}
			int to = go[j][s[i]];
			int& val2 = dp[i + 1][to];
			if (val2 > dp[i][j]) {
				val2 = dp[i][j];
				from[i + 1][to] = {j, 0};
			}
		}
	}

	int best = INF;
	int mem = -1;
	for (int j = 0; j < szof(inds); ++j) {
		if (dp.back()[j] < best) {
			best = dp.back()[j];
			mem = j;
		}
	}

	cout << best << "\n";
	for (int i = szof(s); i > 0; --i) {
		auto [prev, fl] = from[i][mem];
		if (fl) {
			cout << i << " ";
		}
		mem = prev;
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
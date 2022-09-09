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
	string s, t;
	cin >> s >> t;
	vector<vector<vector<tuple<int, int, int, bool>>>> dp(szof(s) + 1, vector<vector<tuple<int, int, int, bool>>>(szof(t) + 1, vector<tuple<int, int, int, bool>>(szof(s) + szof(t) + 5, {INF, -1, -1, false})));
	dp[0][0][0] = {0, -1, -1, false};
	for (int i = 0; i <= szof(s); ++i) {
		for (int j = 0; j <= szof(t); ++j) {
			for (int qwe = 0; qwe < szof(dp[i][j]) * 2; ++qwe) {
				int bal;
				if (qwe < szof(dp[i][j])) {
					bal = qwe;
				} else {
					bal = szof(dp[i][j]) * 2 - 1 - qwe;
				}
				for (int next = 0; next < 2; ++next) {
					if ((bal == 0 && next) || (bal == szof(dp[i][j]) - 1 && !next)) {
						continue;
					}
					int ni = i;
					int nj = j;
					if (ni < szof(s) && s[ni] == "()"[next]) {
						++ni;
					}
					if (nj < szof(t) && t[nj] == "()"[next]) {
						++nj;
					}
					int nbal = bal;
					if (next == 0) {
						++nbal;
					} else {
						--nbal;
					}
					dp[ni][nj][nbal] = min(dp[ni][nj][nbal], {get<0>(dp[i][j][bal]) + 1, i, j, next});
				}
			}
		}
	}
	// cerr << get<0>(dp[szof(s)][szof(t)][0]) << endl;
	int pos_s = szof(s), pos_t = szof(t);
	int bal = 0;
	string ans = "";
	while (pos_s || pos_t || bal) {
		auto [d, ppos_s, ppos_t, br] = dp[pos_s][pos_t][bal];
		if (br == 0) {
			ans += '(';
			--bal;
		} else {
			ans += ')';
			++bal;
		}
		pos_s = ppos_s;
		pos_t = ppos_t;
	}
	reverse(ans.begin(), ans.end());
	cout << ans << "\n";
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
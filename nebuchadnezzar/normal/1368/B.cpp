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

const int MAXL = 50 * 10;

void solve() {
	ll k;
	cin >> k;
	string codeforces = "codeforces";
	vector<vector<ll>> dp(szof(codeforces) + 1, vector<ll>(MAXL));
	vector<vector<int>> from(szof(codeforces) + 1, vector<int>(MAXL));
	dp[0][0] = 1;
	for (int i = 0; i < szof(codeforces); ++i) {
		for (int j = 0; j < MAXL; ++j) {
			for (int add = 1; j + add < MAXL; ++add) {
				ll val;
				if ((double) dp[i][j] * add > k * 10) {
					val = k;
				} else {
					val = min(k, dp[i][j] * add);
				}
				if (dp[i + 1][j + add] < val) {
					dp[i + 1][j + add] = val;
					from[i + 1][j + add] = add;
				}
			}
		}
	}

	int ans = -1;
	for (int i = 0; i < MAXL; ++i) {
		if (dp[szof(codeforces)][i] >= k) {
			ans = i;
			break;
		}
	}

	assert(ans != -1);

	string outp = "";
	for (int i = szof(codeforces); i > 0; --i) {
		int cur = from[i][ans];
		outp += string(cur, codeforces[i - 1]);
		ans -= cur;
	}

	reverse(outp.begin(), outp.end());
	cout << outp << "\n";
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
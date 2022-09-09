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
	int n;
	cin >> n;
	string s;
	cin >> s;
	// int res = 0;
	// for (int j = 0; j < szof(s); ++j) {
	// 	cout << s[j];
	// 	res += s[j] - '0';
	// 	if (j < szof(s) - 1) {
	// 		cout << "+";
	// 	}
	// }
	// cout << "\n";
	// s = to_string(res);
	// cerr << s << endl;
	const int MAXV = 200000 * 9 + 12345;
	vector<int> cost(MAXV, INF);
	vector<pair<string, int>> next(MAXV);

	function<int(int)> calc = [&](int num) {
		if (num < 10) {
			next[num] = {to_string(num), num};
			return 0;
		}
		if (cost[num] != INF) {
			return cost[num];
		}
		string cur = to_string(num);
		for (int mask = 1; mask < 1 << (szof(cur) - 1); ++mask) {
			int res = 0;
			int val = 0;
			string val_str = "";
			string res_str = "";
			for (int i = 0; i < szof(cur); ++i) {
				val = val * 10 + cur[i] - '0';
				val_str += cur[i];
				if (i == szof(cur) - 1 || (mask & (1 << i))) {
					res_str += val_str + "+";
					res += val;
					val = 0;
					val_str = "";
				}
			}
			res_str.pop_back();
			// cerr << num << " " << res << " " << calc(res) + 1 << endl;
			if (cost[num] > calc(res) + 1) {
				cost[num] = calc(res) + 1;
				next[num] = {res_str, res};
			}
		}
		return cost[num];
	};

	int res = 0;
	for (char c : s) {
		res += c - '0';
	}

	vector<bool> plus(n, true);
	plus[n - 1] = false;

	auto print_ans = [&](int res) {
		for (int i = 0; i < n; ++i) {
			cout << s[i];
			if (plus[i]) {
				cout << "+";
			}
		}
		cout << "\n";
		for (int i = 1; i < 3; ++i) {
			cout << next[res].ff << "\n";
			res = next[res].ss;
		}
	};

	// cerr << res << " " << calc(res) << endl;

	if (calc(res) <= 2) {
		print_ans(res);
		return;
	}

	for (int i = 1; ; ++i) {
		if (calc(res + i * 9) <= 2) {
			// cerr << i << endl;
			int maxp = 0;
			int tmp = 1;
			while ((tmp - 1) / 9 <= i) {
				maxp++;
				tmp *= 10;
			}
			vector<int> pp = {1};
			for (int i = 0; i < maxp + 1; ++i) {
				pp.push_back(pp.back() * 10 + 1);
			}
			vector<vector<vector<int>>> dp(n, vector<vector<int>>(maxp, vector<int>(i + 1, 0)));
			dp[n - 1][0][0] = true;
			for (int j = n - 1; j > 0; --j) {
				for (int p = 0; p < maxp; ++p) {
					for (int val = 0; val <= i; ++val) {
						if (!dp[j][p][val]) {
							continue;
						}
						if (p < maxp - 1) {
							int nval = val + (s[j - 1] - '0') * pp[p];
							if (nval <= i) {
								dp[j - 1][p + 1][nval] = 1;
							}
						}
						dp[j - 1][0][val] = 1;
					}
				}
			}
			int cp = -1;
			for (int p = 0; p < maxp; ++p) {
				if (dp[0][p][i]) {
					cp = p;
					break;
				}
			}
			if (cp != -1) {
				// cerr << cp << endl;
				int val = i;
				for (int i = 0; i < n - 1; ++i) {
					if (cp) {
						plus[i] = false;
						// cerr << i << endl;
						val -= (s[i] - '0') * pp[cp - 1];
						--cp;
					} else {
						for (int p = 0; p < maxp; ++p) {
							if (dp[i + 1][p][val]) {
								cp = p;
								break;
							}
						}
						// cerr << cp << endl;
					}
				}
				print_ans(res + i * 9);
				break;
			}
		}
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
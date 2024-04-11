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

const int MOD = 1'000'000'007;

void add(int& a, int b) {
	a += b;
	if (a >= MOD) {
		a -= MOD;
	}
}

int sum(int a, int b) {
	add(a, b);
	return a;
}

int mult(int a, int b) {
	return (ll) a * b % MOD;
}

void solve() {
	int n, m;
	cin >> n >> m;
	vector<int> arr;
	vector<vector<int>> positions(n);
	for (int i = 0; i < n; ++i) {
		int num;
		cin >> num;
		--num;
		arr.push_back(num);
		positions[num].push_back(i);
	}

	vector<vector<int>> cows(n);

	for (int i = 0; i < m; ++i) {
		int f, h;
		cin >> f >> h;
		--f;
		if (h > szof(positions[f])) {
			continue;
		}
		cows[f].push_back(h);
	}

	vector<vector<int>> cnt_cows(n, vector<int>(n + 1));

	for (int i = 0; i < n; ++i) {
		sort(cows[i].begin(), cows[i].end());

		for (int num : cows[i]) {
			cnt_cows[i][num]++;
		}
		for (int j = 1; j <= n; ++j) {
			cnt_cows[i][j] += cnt_cows[i][j - 1];
		}
	}

	auto have_cow = [&](int i, int j) {
		return j && cnt_cows[i][j] != cnt_cows[i][j - 1];
	};

	m = szof(cows);

	vector<int> cnt(n);

	int best = 0;
	int ans = 1;

	for (int i = 0; i <= n; ++i) {
		int res = 0;
		int vars_left = 1, vars_right = 1;
		if (i == 0) {
			vars_left = 0;
		}
		if (i == n) {
			vars_right = 0;
		}
		for (int j = 0; j < n; ++j) {
			int a = cnt[j];
			int b = szof(positions[j]) - cnt[j];

			if (a > b) {
				swap(a, b);
			}

			if (szof(cows[j]) == 0 || cows[j][0] > b) {
				if (i && arr[i - 1] == j) {
					vars_left = 0;
				}
				if (i < n && arr[i] == j) {
					vars_right = 0;
				}
			} else if (szof(cows[j]) == 1 || !(cows[j][0] <= a && cows[j][1] <= b)) {
				res += 1;
				if (i && arr[i - 1] == j) {
					if (!have_cow(j, cnt[j])) {
						vars_left = 0;
					}
				} else {
					vars_left = mult(vars_left, sum(cnt_cows[j][a], cnt_cows[j][b]));
				}
				if (i != n && arr[i] == j) {
					if (!have_cow(j, szof(positions[j]) - cnt[j])) {
						vars_right = 0;
					}
				} else {
					vars_right = mult(vars_right, cnt_cows[j][szof(positions[j]) - cnt[j]]);
				}
			} else {
				res += 2;
				vars_right = 0;
				if (i && arr[i - 1] == j) {
					if (!have_cow(j, cnt[j])) {
						vars_left = 0;
					} else {
						int tmp2 = cnt_cows[j][szof(positions[j]) - cnt[j]];
						if (cnt[j] <= szof(positions[j]) - cnt[j]) {
							--tmp2;
						}
						vars_left = mult(vars_left, tmp2);
					}
				} else {
					int tmp1 = cnt_cows[j][a];
					int tmp2 = cnt_cows[j][b];
					vars_left = mult(vars_left, (tmp1 * (tmp1 - 1)) + tmp1 * (tmp2 - tmp1));
				}
			}
		}

		// cerr << i << " " << res << " " << vars_left << " " << vars_right << endl;

		int vars = sum(vars_left, vars_right);

		if (res > best) {
			best = res;
			ans = vars;
		} else if (res == best) {
			add(ans, vars);
		}

		if (i < n) {
			cnt[arr[i]]++;
		}
	}

	// cerr << ans << endl;

	if (best == 0) {
		cout << "0 1\n";
	} else {
		cout << best << " " << ans << "\n";
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
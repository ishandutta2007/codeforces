// Created by Nikolay Budin

#ifdef DEBUG
#  define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
#define ff first
#define ss second
#define szof(x) ((int)x.size())
#ifndef LOCAL
// #  define cerr __get_ce
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
	int n, k;
	cin >> n >> k;
	vector<vector<int>> graph(n);
	for (int i = 0; i < n - 1; ++i) {
		int a, b;
		cin >> a >> b;
		--a; --b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	if (k == 2) {
		cout << "Yes\n";
		vector<int> color(n);
		function<void(int, int, int)> dfs = [&](int v, int p, int col) {
			color[v] = col;
			for (int to : graph[v]) {
				if (to != p) {
					dfs(to, v, 1 - col);
				}
			}
		};
		dfs(0, 0, 0);
		for (int num : color) {
			cout << num + 1 << " ";
		}
		cout << "\n";
		return;
	}

	vector<int> ok(n);
	vector<int> maxd(n);

	function<void(int, int)> dfs = [&](int v, int p) {
		ok[v] = true;
		vector<int> tmp;
		for (int to : graph[v]) {
			if (to != p) {
				dfs(to, v);
				ok[v] &= ok[to];
				tmp.push_back(maxd[to] + 1);
			}
		}
		sort(tmp.begin(), tmp.end());
		if (szof(tmp) >= 2) {
			ok[v] &= tmp[szof(tmp) - 1] + tmp[szof(tmp) - 2] < k - 1;
		}
		if (szof(tmp)) {
			maxd[v] = tmp.back();
		}
	};

	dfs(0, 0);
	vector<int> ans(n);

	function<void(int, int, int, int)> color = [&](int v, int p, int col, int shift) {
		ans[v] = col;
		for (int to : graph[v]) {
			if (to != p) {
				color(to, v, (col + shift) % k, shift);
			}
		}
	};

	function<void(int, int, int)> push_down = [&](int v, int p, int maxd_p) {
		int cnt_not_ok = 0;
		set<pii> arr;
		for (int to : graph[v]) {
			if (to != p) {
				cnt_not_ok += !ok[to];
				arr.insert({maxd[to] + 1, to});
			}
		}
		if (v) {
			arr.insert({maxd_p + 1, p});
		}
		if (!cnt_not_ok) {
			int tmp = (--arr.end())->ff;
			// cerr << tmp << endl;
			auto it = arr.lower_bound({k - 1 - tmp, -INF});
			auto it2 = arr.end();
			int sum = 0;
			int cnt = 0;
			for (int i = 0; i < 4; ++i) {
				if (i >= 2) {
					sum += it2->ff;
					++cnt;
				}
				if (it2 == it) {
					break;
				}
				if (it2 == arr.begin()) {
					break;
				}
				--it2;
			}
			if (cnt < 2 || sum < k - 1) {
				int to_tmp = (--arr.end())->ss;
				cerr << "center " << v + 1 << endl;
				for (auto to : arr) {
					if (to.ff < k - 1 - tmp || to.ss == to_tmp) {
						cerr << to.ss + 1 << " " << 1 << endl;
						color(to.ss, v, 1, 1);
					} else {
						cerr << to.ss + 1 << " " << 2 << endl;
						color(to.ss, v, k - 1, k - 1);
					}
				}
				cout << "Yes\n";
				for (int c : ans) {
					cout << c + 1 << " ";
				}
				cout << "\n";
				exit(0);
			}
		}

		for (int to : graph[v]) {
			if (to != p) {
				arr.erase({maxd[to] + 1, to});
				cnt_not_ok -= !ok[to];

				if (!cnt_not_ok) {
					auto it = arr.end();
					int cnt = 0;
					int sum = 0;
					for (int i = 0; i < 2; ++i) {
						if (it == arr.begin()) {
							break;
						}
						--it;
						sum += it->ff;
						++cnt;
					}
					if (cnt < 2 || sum < k - 1) {
						int maxd_ch = 0;
						if (szof(arr)) {
							maxd_ch = (--arr.end())->ff;
						}
						push_down(to, v, maxd_ch);
					}
				}

				cnt_not_ok += !ok[to];
				arr.insert({maxd[to] + 1, to});
			}
		}
	};

	push_down(0, 0, -1);
	cout << "No\n";
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
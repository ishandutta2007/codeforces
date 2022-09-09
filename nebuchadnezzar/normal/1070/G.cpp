#ifdef LOCAL
#  define _GLIBCXX_DEBUG
#else
#  define cerr __get_ce
#endif
#include <bits/stdc++.h>
#define ff first
#define ss second
#define szof(x) ((int)x.size())

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
int const INF = (int)1e9 + 1e3;
ll const INFL = (ll)1e18 + 1e6;
mt19937 tw(9450189);
uniform_int_distribution<ll> ll_distr;
ll rnd(ll a, ll b) { return ll_distr(tw) % (b - a + 1) + a; }


void solve() {
	int n, m;
	cin >> n >> m;
	vector<pii> heroes(n, {-1, -1});
	for (int i = 0; i < m; ++i) {
		int pos, h;
		cin >> pos >> h;
		--pos;
		heroes[pos] = {i, h};
	}

	vector<int> arr;
	for (int i = 0; i < n; ++i) {
		int num;
		cin >> num;
		arr.push_back(num);
	}

	// for (auto p : heroes) {
	// 	cerr << p.ff << " " << p.ss << endl;
	// }


	for (int i = 0; i < n; ++i) {
		vector<int> cur_arr = arr;
		vector<int> order;
		vector<bool> used(n);
		bool fl = true;
		for (int k = i; k >= 0; --k) {
			if (heroes[k].ff != -1) {
				int curh = heroes[k].ss;
				bool can = true;
				for (int j = k; j <= i; ++j) {
					curh += cur_arr[j];
					if (curh < 0) {
						can = false;
						break;
					}
				}
				if (can) {
					fill(cur_arr.begin() + k, cur_arr.begin() + i + 1, 0);
					order.push_back(heroes[k].ff);
					used[k] = true;
				}
			}
		}

		for (int k = i + 1; k < n; ++k) {
			if (heroes[k].ff != -1) {
				int curh = heroes[k].ss;
				bool can = true;
				for (int j = k; j >= i; --j) {
					curh += cur_arr[j];
					// cerr << k << " " << j << " " << curh << endl;
					if (curh < 0) {
						can = false;
						break;
					}
				}
				if (can) {
					fill(cur_arr.begin() + i, cur_arr.begin() + k + 1, 0);
					order.push_back(heroes[k].ff);
					used[k] = true;
				}
			}
		}

		// cerr << "order:\n";
		// for (int num : order) {
		// 	cerr << num + 1 << " ";
		// }
		// cerr << endl;

		for (int k = 0; k < n; ++k) {
			if (!used[k] && heroes[k].ff != -1) {
				int curh = heroes[k].ss;
				bool can = true;
				int dir = 1;
				if (k > i) {
					dir = -1;
				}
				for (int j = k; ; j += dir) {
					curh += cur_arr[j];
					// cerr << k << " " << j << " " << curh << endl;
					if (curh < 0) {
						can = false;
						break;
					}
					if (j == i) {
						break;
					}
				}
				if (!can) {
					fl = false;
					break;
				}
				order.push_back(heroes[k].ff);
			}
		}


		if (fl) {
			cout << i + 1 << "\n";
			for (int num : order) {
				cout << num + 1 << " ";
			}
			cout << "\n";
			return;
		}

		cur_arr = arr;
		order.clear();
		fill(used.begin(), used.end(), 0);
		fl = true;

		for (int k = i; k < n; ++k) {
			if (heroes[k].ff != -1) {
				int curh = heroes[k].ss;
				bool can = true;
				for (int j = k; j >= i; --j) {
					curh += cur_arr[j];
					if (curh < 0) {
						can = false;
						break;
					}
				}
				if (can) {
					fill(cur_arr.begin() + i, cur_arr.begin() + k + 1, 0);
					order.push_back(heroes[k].ff);
					used[k] = true;
				}
			}
		}

		for (int k = i - 1; k >= 0; --k) {
			if (heroes[k].ff != -1) {
				int curh = heroes[k].ss;
				bool can = true;
				for (int j = k; j <= i; ++j) {
					curh += cur_arr[j];
					if (curh < 0) {
						can = false;
						break;
					}
				}
				if (can) {
					fill(cur_arr.begin() + k, cur_arr.begin() + i + 1, 0);
					order.push_back(heroes[k].ff);
					used[k] = true;
				}
			}
		}
		// cerr << "order:\n";
		// for (int num : order) {
		// 	cerr << num + 1 << " ";
		// }
		// cerr << endl;

		for (int k = 0; k < n; ++k) {
			if (!used[k] && heroes[k].ff != -1) {
				int curh = heroes[k].ss;
				bool can = true;
				int dir = 1;
				if (k > i) {
					dir = -1;
				}
				for (int j = k; ; j += dir) {
					curh += cur_arr[j];
					// cerr << k << " " << j << " " << curh << endl;
					if (curh < 0) {
						can = false;
						break;
					}
					if (j == i) {
						break;
					}
				}
				if (!can) {
					fl = false;
					break;
				}
				order.push_back(heroes[k].ff);
			}
		}

		if (fl) {
			cout << i + 1 << "\n";
			for (int num : order) {
				cout << num + 1 << " ";
			}
			cout << "\n";
			return;
		}
	}

	cout << "-1\n";
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
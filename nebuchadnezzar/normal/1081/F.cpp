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
int const INF = (int)1e9 + 1e3;
ll const INFL = (ll)1e18 + 1e6;
mt19937 tw(9450189);
uniform_int_distribution<ll> ll_distr;
ll rnd(ll a, ll b) { return ll_distr(tw) % (b - a + 1) + a; }

vector<int> arr, init_arr;
int cnt_steps = 0;


int ask(int l, int r) {
	#ifdef TEST
	++cnt_steps;
	assert(cnt_steps <= 10000);
	if (rnd(0, 1)) {
		for (int i = 0; i < r; ++i) {
			arr[i] ^= 1;
		}
	} else {
		for (int i = l; i < szof(arr); ++i) {
			arr[i] ^= 1;
		}
	}
	return accumulate(arr.begin(), arr.end(), 0);
	#endif
	cout << "? " << l + 1 << " " << r << endl;
	int num;
	cin >> num;
	return num;
}

void print_ans(vector<int> ans) {
	#ifdef TEST
	assert(ans == init_arr);
	return;
	#endif
	cout << "! ";
	for (int num : ans) {
		cout << num;
	}
	cout << endl;
}

void solve(int n, int t) {
	int all0 = t;
	int all1 = ask(0, n);
	ask(0, n);
	vector<int> ans(n, -1);
	if (abs(all0 - all1) != 1) {
		for (int i = 0; i < n; ++i) {
			bool found = false;
			while (true) {
				ask(i, i + 1);
				int tmp = ask(i, i + 1);
				if (found) {
					if (tmp == all0) {
						break;
					}
				} else {
					if (tmp != all0) {
						if (tmp > all1) {
							ans[i] = 1;
						} else {
							ans[i] = 0;
						}
						found = true;
					}
				}
			}
		}
		print_ans(ans);
		return;
	} else {
		vector<int> here(n - 1);
		for (int i = 0; i < n - 1; ++i) {
			// cerr << i << endl;
			bool found = false;
			while (true) {
				ask(i, i + 2);
				int tmp = ask(i, i + 2);
				if (found) {
					if (tmp == all0) {
						break;
					}
				} else {
					if (tmp != all0) {
						if (tmp > all1) {
							here[i] = 2;
						} else if (tmp == all1) {
							here[i] = 1;
						} else {
							here[i] = 0;
						}
						found = true;
					}
				}
			}
		}

		for (int i = 0; i < 100; ++i) {
			ask(0, 1);
			int tmp = ask(0, 1);
			if (tmp != all0) {
				if (all0 < all1) {
					ans[0] = 1;
				} else {
					ans[0] = 0;
				}
				break;
			}
		}

		if (ans[0] == -1) {
			if (all0 < all1) {
				ans[0] = 0;
			} else {
				ans[0] = 1;
			}
		}

		for (int i = 1; i < n; ++i) {
			ans[i] = here[i - 1] - ans[i - 1];
		}

		print_ans(ans);
	}
}

void solve0() {
	int n, t;
	cin >> n >> t;
	solve(n, t);
}

void stress() {
	for (int i = 0; i < 100000; ++i) {
		cerr << "run test #" << i + 1 << endl;
		int n = rnd(1, 300);
		init_arr.clear();
		for (int j = 0; j < n; ++j) {
			init_arr.push_back(rnd(0, 1));
		}
		arr = init_arr;
		cerr << n << endl;
		// for (int num : arr) {
		// 	cerr << num;
		// }
		// cerr << endl;
		cnt_steps = 0;
		solve(n, accumulate(arr.begin(), arr.end(), 0));
	}
}

int main() {
#ifdef LOCAL
	auto start_time = clock();
	cerr << setprecision(3) << fixed;
#endif
	cout << setprecision(15) << fixed;
	ios::sync_with_stdio(false);
	// cin.tie(nullptr);

	// stress();

	int test_count = 1;
	// cin >> test_count;
	for (int test = 1; test <= test_count; ++test) {
		solve0();
	}
	
#ifdef LOCAL
	auto end_time = clock();
	cerr << "Execution time: " << (end_time - start_time) * (int)1e3 / CLOCKS_PER_SEC << " ms\n";
#endif
}
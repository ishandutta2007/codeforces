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

int mpow(int a, int b) {
	int ret = 1;
	while (b) {
		if (b & 1) {
			ret = mult(ret, a);
		}
		a = mult(a, a);
		b /= 2;
	}
	return ret;
}

int inv(int num) {
	return mpow(num, MOD - 2);
}

vector<int> factorial, inv_factorial;

int cnk(int n, int k) {
	return mult(factorial[n], mult(inv_factorial[k], inv_factorial[n - k]));
}

void solve() {
	string sa, sb;
	cin >> sa >> sb;
	vector<int> a, b;
	for (char c : sa) {
		a.push_back(c - '0');
	}
	for (char c : sb) {
		b.push_back(c - '0');
	}


	vector<int> cnt(4);
	for (int i = 0; i < 4; ++i) {
		cin >> cnt[i];
	}
	int l = accumulate(cnt.begin(), cnt.end(), 0) + 1;

	factorial = {1};
	for (int i = 1; i < l + 5; ++i) {
		factorial.push_back(mult(factorial.back(), i));
	}

	inv_factorial.push_back(inv(factorial.back()));

	for (int i = l + 4; i > 0; --i) {
		inv_factorial.push_back(mult(inv_factorial.back(), i));
	}

	reverse(inv_factorial.begin(), inv_factorial.end());

	auto calc = [&](vector<int> num) {
		if (l > szof(num)) {
			return 0;
		}
		if (l < szof(num)) {
			num = vector<int>(l, 1);
		}

		vector<int> cur_cnt(4);
		int ret = 0;
		for (int i = l - 2; i >= 0; --i) {
			if (num[i] == 1) {
				cur_cnt[num[i + 1] * 2]++;

				bool ok = true;
				for (int j = 0; j < 4; ++j) {
					if (cur_cnt[j] > cnt[j]) {
						ok = false;
						break;
					}
				}

				if (ok) {
					int left00 = cnt[0] - cur_cnt[0];
					int left01 = cnt[1] - cur_cnt[1];
					int left10 = cnt[2] - cur_cnt[2];
					int left11 = cnt[3] - cur_cnt[3];
					// cerr << i << " " << left00 << " " << left01 << " " << left10 << " " << left11 << endl;
					if (left01 == 0) {
						if (left11 == 0 && left10 == 0) {
							add(ret, 1);
						}
					} else {
						if (left01 == left10 || left01 == left10 + 1) {
							add(ret, mult(cnk(left00 + left10, left10), cnk(left11 + left01 - 1, left01 - 1)));
						}
					}
				}

				cur_cnt[num[i + 1] * 2]--;
			}
			cur_cnt[num[i + 1] * 2 + num[i]]++;
		}

		if (cur_cnt == cnt) {
			add(ret, 1);
		}
		return ret;
	};

	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());

	for (int i = 0; ; ++i) {
		a[i] ^= 1;
		if (a[i] == 0) {
			break;
		}
	}
	while (szof(a) && a.back() == 0) {
		a.pop_back();
	}

	cout << sum(calc(b), MOD - calc(a)) << "\n";
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
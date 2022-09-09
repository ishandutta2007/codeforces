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

int MOD;

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

const int P = 239;

vector<int> calc_arrh(string s) {
	vector<int> ret = {0};
	for (char c : s) {
		ret.push_back(sum(mult(ret.back(), P), c));
	}
	return ret;
}

vector<int> pp = {1};

int get_hash(vector<int> const& arrh, int l, int r) {
	return sum(arrh[r], MOD - mult(arrh[l], pp[r - l]));
}

void solve() {
	int n;
	cin >> n;

	while (szof(pp) < n + 6) {
		pp.push_back(mult(pp.back(), P));
	}

	string s;
	cin >> s;
	vector<int> arr_h = calc_arrh(s);
	string rs = s;
	reverse(rs.begin(), rs.end());
	vector<int> arr_rh = calc_arrh(rs);

	auto calc_pal_hash = [&](int r, int len) {
		if (len <= r) {
			return get_hash(arr_h, 0, len);
		} else {
			return sum(mult(get_hash(arr_h, 0, r), pp[len - r]), get_hash(arr_rh, n - r, n - r + (len - r)));
		}
	};

	auto get_pal_ch = [&](int r, int pos) {
		if (pos < r) {
			return s[pos];
		} else {
			return rs[n - r + (pos - r)];
		}
	};

	int ans = 1;
	for (int i = 2; i <= n; ++i) {
		// cerr << ans << " " << i << endl;
		int l = 0, r = ans * 2 + 1;
		while (r - l > 1) {
			int mid = (l + r) / 2;
			if (calc_pal_hash(ans, mid) == calc_pal_hash(i, mid)) {
				l = mid;
			} else {
				r = mid;
			}
		}

		// cerr << l << endl;

		if (l < ans * 2 && get_pal_ch(ans, l) > get_pal_ch(i, l)) {
			ans = i;
		}
	}

	cout << s.substr(0, ans) << rs.substr(n - ans, ans) << "\n";
}


bool is_prime(int num) {
	for (int i = 2; i * i <= num; ++i) {
		if (num % i == 0) {
			return false;
		}
	}
	return true;
}

int main() {
#ifdef LOCAL
	auto start_time = clock();
	cerr << setprecision(3) << fixed;
#endif
	cout << setprecision(15) << fixed;
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	MOD = rnd(900000000, 1000000000);
	while (!is_prime(MOD)) {
		++MOD;
	}

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
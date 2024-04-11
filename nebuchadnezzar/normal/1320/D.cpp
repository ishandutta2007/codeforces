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

const int MOD = 998244353;
const int P = 239;

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
	int n;
	cin >> n;
	string s;
	cin >> s;
	vector<pair<int, char>> arrs;
	int from = 0;
	for (int i = 0; i < n; ++i) {
		if (s[i] == '0') {
			if ((i - from) % 2) {
				arrs.push_back({from, '1'});
			}
			arrs.push_back({i, '0'});
			from = i + 1;
		}
	}
	if ((n - from) % 2) {
		arrs.push_back({from, '1'});
	}
	vector<int> hashes = {0};
	for (auto p : arrs) {
		hashes.push_back(sum(mult(hashes.back(), P), p.ss));
	}
	vector<int> pp = {1};
	for (int i = 0; i < n + 5; ++i) {
		pp.push_back(mult(pp.back(), P));
	}

	auto get_hash = [&](int l, int r) {
		return sum(hashes[r], MOD - mult(hashes[l], pp[r - l]));
	};

	auto calc_hash = [&](int l, int r) {
		int lp = lower_bound(arrs.begin(), arrs.end(), pair<int, char>(l, 0)) - arrs.begin();
		int rp = lower_bound(arrs.begin(), arrs.end(), pair<int, char>(r, 0)) - arrs.begin() - 1;
		// cerr << "calc " << l << " " << r << endl;
		// cerr << lp << " " << rp << endl;
		if (lp > rp) {
			if ((r - l) % 2) {
				return (int) '1';
			} else {
				return 0;
			}
		}
		if (arrs[lp].ss == '1') {
			++lp;
		}
		if (lp > rp) {
			if ((r - l) % 2) {
				return (int) '1';
			} else {
				return 0;
			}
		}
		if (arrs[rp].ss == '1') {
			--rp;
		}
		int ret = get_hash(lp, rp + 1);
		if ((arrs[lp].ff - l) % 2) {
			add(ret, mult('1', pp[rp - lp + 1]));
		}
		if ((r - arrs[rp].ff - 1) % 2) {
			ret = sum(mult(ret, P), '1');
		}
		// cerr << l << " " << r << " " << ret << endl;
		return ret;
	};


	vector<int> pref = {0};
	for (char c : s) {
		pref.push_back(pref.back() + c - '0');
	}
	int q;
	cin >> q;
	for (int i = 0; i < q; ++i) {
		int l1, l2, len;
		cin >> l1 >> l2 >> len;
		--l1; --l2;
		if (pref[l1 + len] - pref[l1] != pref[l2 + len] - pref[l2]) {
			cout << "No\n";
			continue;
		}

		if (calc_hash(l1, l1 + len) == calc_hash(l2, l2 + len)) {
			cout << "Yes\n";
		} else {
			cout << "No\n";
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
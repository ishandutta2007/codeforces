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

const int P = 239;

void solve() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	vector<int> pp = {1};
	for (int i = 0; i < szof(s) + 6; ++i) {
		pp.push_back(mult(pp.back(), P));
	}
	vector<vector<int>> hashes(2 * szof(s));
	function<void(int, int, int)> build = [&](int v, int vl, int vr) {
		if (vr - vl == 1) {
			hashes[v] = {s[vl]};
			return;
		}
		int vm = (vl + vr) / 2;
		build(v * 2, vl, vm);
		build(v * 2 + 1, vm, vr);
		int half_mask = (vm - vl) - 1;

		// cerr << "v: " << v << endl;
		for (int mask = 0; mask < vr - vl; ++mask) {
			int hl = hashes[v * 2][mask & half_mask];
			int hr = hashes[v * 2 + 1][mask & half_mask];
			if (mask & (vm - vl)) {
				swap(hl, hr);
			}
			hashes[v].push_back(sum(mult(hl, pp[vm - vl]), hr));
			// cerr << hashes[v].back() << " ";
		}
		// cerr << endl;
	};

	build(1, 0, szof(s));

	function<int(int, int, int, int, int)> get_hash = [&](int v, int vl, int vr, int j, int l) {
		if (l == 0) {
			return 0;
		}
		if (vr - vl == l) {
			return hashes[v][j];
		}
		int vm = (vl + vr) / 2;
		int nj = j & (vm - vl - 1);
		if (j & (vm - vl)) {
			if (l >= vm - vl) {
				return sum(mult(hashes[v * 2 + 1][nj], pp[l - (vm - vl)]), get_hash(v * 2, vl, vm, nj, l - (vm - vl)));
			}
			return get_hash(v * 2 + 1, vm, vr, nj, l);
		} else {
			if (l >= vm - vl) {
				return sum(mult(hashes[v * 2][nj], pp[l - (vm - vl)]), get_hash(v * 2 + 1, vm, vr, nj, l - (vm - vl)));
			}
			return get_hash(v * 2, vl, vm, nj, l);
		}
	};

	auto get_ith = [&](int j, int i) {
		return s[j ^ i];
	};

	int best = 0;
	for (int i = 1; i < szof(s); ++i) {
		int l = 0, r = szof(s) + 1;
		while (r - l > 1) {
			int mid = (l + r) / 2;
			if (get_hash(1, 0, szof(s), best, mid) == get_hash(1, 0, szof(s), i, mid)) {
				l = mid;
			} else {
				r = mid;
			}
		}
		// cerr << best << " " << i << " " << l << endl;
		if (l < szof(s) && get_ith(best, l) > get_ith(i, l)) {
			best = i;
		}
	}

	string res(szof(s), ' ');
	for (int i = 0; i < szof(s); ++i) {
		res[i ^ best] = s[i];
	}

	cout << res << "\n";
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
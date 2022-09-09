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

vector<string> colors = {"white", "yellow", "green", "blue", "red", "orange"};

int get_color_ind(string col) {
	return find(colors.begin(), colors.end(), col) - colors.begin();
}

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

int mpow(int a, ll b) {
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

void solve() {
	int k, n;
	cin >> k >> n;
	map<ll, int> have_color;
	set<ll> nodes;
	for (int i = 0; i < n; ++i) {
		ll v;
		string col;
		cin >> v >> col;
		int c = get_color_ind(col);
		have_color[v] = c;
		while (v) {
			nodes.insert(v);
			v /= 2;
		}
	}

	function<vector<int>(ll, int)> dfs = [&](ll v, int h) {
		if (!nodes.count(v)) {
			int val = mpow(4, (1ll << h) - 2);
			return vector<int>(6, val);
		}
		vector<int> ret(6);
		if (h == 1) {
			if (have_color.count(v)) {
				ret[have_color[v]] = 1;
			} else {
				fill(ret.begin(), ret.end(), 1);
			}
			return ret;
		}

		auto left = dfs(v * 2, h - 1);
		auto right = dfs(v * 2 + 1, h - 1);
		for (int col = 0; col < 6; ++col) {
			if (have_color.count(v) && col != have_color[v]) {
				continue;
			}
			int varsl = 0, varsr = 0;
			for (int ocol = 0; ocol < 6; ++ocol) {
				if (ocol == col || ocol == (col ^ 1)) {
					continue;
				}
				add(varsl, left[ocol]);
				add(varsr, right[ocol]);
			}
			ret[col] = mult(varsl, varsr);
		}
		return ret;
	};

	auto res = dfs(1, k);
	int ans = 0;
	for (int i = 0; i < 6; ++i) {
		add(ans, res[i]);
	}
	cout << ans << "\n";
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
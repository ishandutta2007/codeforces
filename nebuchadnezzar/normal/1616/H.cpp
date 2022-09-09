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

struct node {
	int l, r;
	int sz;
	node() : l(-1), r(-1), sz(0) {}

	int& go(int b) {
		if (b == 0) {
			return l;
		}
		return r;
	}
};

const int MOD = 998244353;

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
	int n, k;
	cin >> n >> k;
	const int L = 30;
	vector<node> trie;
	trie.push_back(node());
	for (int i = 0; i < n; ++i) {
		int num;
		cin >> num;
		int v = 0;
		for (int j = L - 1; j >= 0; --j) {
			trie[v].sz++;
			int b = (num >> j) & 1;
			if (trie[v].go(b) == -1) {
				trie[v].go(b) = szof(trie);
				trie.push_back(node());
			}
			v = trie[v].go(b);
		}
		trie[v].sz++;
	}

	vector<int> p2 = {1};
	for (int i = 0; i < n; ++i) {
		p2.push_back(mult(p2.back(), 2));
	}

	int ans = 0;
	unordered_map<ll, int> mem;

	function<int(int, int, int)> calc_dp = [&](int v1, int v2, int d) {
		if (v1 == -1 && v2 == -1) {
			return 0;
		}
		if (v1 == -1) {
			// cerr << trie[v2].sz << endl;
			return sum(p2[trie[v2].sz], MOD - 1);
		}
		if (v2 == -1) {
			// cerr << trie[v1].sz << endl;
			return sum(p2[trie[v1].sz], MOD - 1);
		}

		if (mem.find((ll) v1 * INF + v2) != mem.end()) {
			return mem[(ll) v1 * INF + v2];
		}

		// cerr << v1 << " " << v2 << " " << d << " " << trie[v1].sz << " " << trie[v2].sz << endl;
		int& ret = mem[(ll) v1 * INF + v2];
		ret = 0;
		if (d == L) {
			ret = sum(p2[trie[v2].sz + trie[v1].sz], MOD - 1);
			return ret;
		}
		if (k & (1 << (L - 1 - d))) {
			ret = sum(mult(sum(calc_dp(trie[v1].l, trie[v2].r, d + 1), 1), sum(calc_dp(trie[v1].r, trie[v2].l, d + 1), 1)), MOD - 1);
			return ret;
		}
		if (trie[v1].l != -1 && trie[v1].r != -1) {
			add(ret, mult(sum(p2[trie[trie[v1].l].sz], MOD - 1), sum(p2[trie[trie[v1].r].sz], MOD - 1)));
		}
		if (trie[v2].l != -1 && trie[v2].r != -1) {
			add(ret, mult(sum(p2[trie[trie[v2].l].sz], MOD - 1), sum(p2[trie[trie[v2].r].sz], MOD - 1)));
		}
		
		add(ret, calc_dp(trie[v1].l, trie[v2].l, d + 1));
		add(ret, calc_dp(trie[v1].r, trie[v2].r, d + 1));
		return ret;
	};

	function<void(int, int)> dfs = [&](int v, int d) {
		if (d == L) {
			add(ans, sum(p2[trie[v].sz], MOD - 1));
			return;
		}
		if (k & (1 << (L - 1 - d))) {
			ans = max(ans, calc_dp(trie[v].l, trie[v].r, d + 1));
			return;
		}
		if (trie[v].l != -1) {
			dfs(trie[v].l, d + 1);
		}
		if (trie[v].r != -1) {
			dfs(trie[v].r, d + 1);
		}
	};

	dfs(0, 0);

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
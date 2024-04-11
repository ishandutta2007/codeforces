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

const int MAXN = 2e5 + 5;
vector<vector<pii>> prime_divs(MAXN);
vector<int> sieve(MAXN);

void solve() {
	int n;
	cin >> n;
	vector<vector<pair<int, pii>>> graph(n);
	for (int i = 0; i < n - 1; ++i) {
		int a, b, x, y;
		cin >> a >> b >> x >> y;
		--a; --b;
		int tmp = __gcd(x, y);
		x /= tmp; y /= tmp;
		graph[a].push_back({b, {x, y}});
		graph[b].push_back({a, {y, x}});
	}

	vector<int> cnt_primes(MAXN);
	int cur_val = 1;
	int ans = 0;

	auto make_divisible = [&](int num) {
		for (auto p : prime_divs[num]) {
			if (cnt_primes[p.ff] < p.ss) {
				int tmp = mpow(p.ff, p.ss - cnt_primes[p.ff]);
				ans = mult(ans, tmp);
				cur_val = mult(cur_val, tmp);
				cnt_primes[p.ff] = p.ss;
			}
		}
	};

	auto do_div_mult = [&](int num, int t) {
		if (t == -1) {
			cur_val = mult(cur_val, inv(num));
		} else {
			cur_val = mult(cur_val, num);
		}
		for (auto p : prime_divs[num]) {
			cnt_primes[p.ff] += p.ss * t;
		}
	};

	function<void(int, int)> dfs = [&](int v, int p) {
		// cerr << v << " " << cur_val << endl;
		add(ans, cur_val);
		for (auto to : graph[v]) {
			if (to.ff != p) {
				make_divisible(to.ss.ff);
				do_div_mult(to.ss.ff, -1);
				do_div_mult(to.ss.ss, 1);
				dfs(to.ff, v);
				do_div_mult(to.ss.ss, -1);
				do_div_mult(to.ss.ff, 1);
			}
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

	for (int i = 2; i < MAXN; ++i) {
		if (sieve[i] == 0) {
			for (int j = i; j < MAXN; j += i) {
				sieve[j] = i;
			}
		}
	}

	for (int i = 1; i < MAXN; ++i) {
		int tmp = i;
		map<int, int> cnt;
		while (tmp > 1) {
			cnt[sieve[tmp]]++;
			tmp /= sieve[tmp];
		}
		prime_divs[i] = vector<pii>(cnt.begin(), cnt.end());
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
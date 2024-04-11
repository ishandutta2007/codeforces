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

const int MAXV = 1e6 + 5;
vector<vector<int>> divs(MAXV);

void solve() {
	int primes = 0;
	vector<int> prime_ind(MAXV);
	for (int i = 2; i < MAXV; ++i) {
		if (!szof(divs[i])) {
			prime_ind[i] = primes;
			++primes;
			for (int j = i; j < MAXV; j += i) {
				divs[j].push_back(i);
			}
		}
	}


	int n, q;
	cin >> n >> q;
	vector<int> dsu(n + primes);
	iota(dsu.begin(), dsu.end(), 0);

	auto get_root = [&](int v) {
		int mem = v;
		while (dsu[v] != v) {
			v = dsu[v];
		}
		while (dsu[mem] != mem) {
			int tmp = dsu[mem];
			dsu[mem] = v;
			mem = tmp;
		}
		return v;
	};

	auto unite = [&](int a, int b) {
		a = get_root(a);
		b = get_root(b);
		if (a == b) {
			return;
		}
		dsu[a] = b;
	};

	vector<int> arr;
	for (int i = 0; i < n; ++i) {
		int num;
		cin >> num;
		arr.push_back(num);
		for (int p : divs[num]) {
			unite(i, n + prime_ind[p]);
		}
	}

	vector<set<int>> here(szof(dsu));
	vector<int> cur;
	for (int i = 0; i < n; ++i) {
		cur.clear();
		cur.push_back(get_root(i));
		int val = arr[i] + 1;
		for (int p : divs[val]) {
			cur.push_back(get_root(n + prime_ind[p]));
		}
		sort(cur.begin(), cur.end());
		cur.erase(unique(cur.begin(), cur.end()), cur.end());
		for (int v : cur) {
			for (int u : cur) {
				if (v != u) {
					here[v].insert(u);
				}
			}
		}
	}

	vector<int> ans(q, -1);

	for (int i = 0; i < q; ++i) {
		int s, t;
		cin >> s >> t;
		--s; --t;
		if (get_root(s) == get_root(t)) {
			ans[i] = 0;
		} else {
			if (arr[s] % 2 != arr[t] % 2) {
				ans[i] = 1;
			} else {
				int a = get_root(s), b = get_root(t);
				if (here[a].count(b)) {
					ans[i] = 1;
				} else {
					ans[i] = 2;
				}
			}
		}
	}

	for (int num : ans) {
		cout << num << "\n";
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
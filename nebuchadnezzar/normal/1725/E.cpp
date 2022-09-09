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


void solve() {
	int n;
	cin >> n;
	map<int, vector<int>> by_prime;
	for (int i = 0; i < n; ++i) {
		int num;
		cin >> num;
		for (int j = 2; j * j <= num; ++j) {
			if (num % j == 0) {
				by_prime[j].push_back(i);
				while (num % j == 0) {
					num /= j;
				}
			}
		}
		if (num > 1) {
			by_prime[num].push_back(i);
		}
	}

	vector<vector<int>> graph(n);
	for (int i = 0; i < n - 1; ++i) {
		int a, b;
		cin >> a >> b;
		--a; --b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	int bp = 1;
	while (1 << bp < n) {
		++bp;
	}

	vector<int> tin(n);
	vector<int> tout(n);
	int tcnt = 0;
	vector<int> depth(n);
	vector<vector<int>> binup(bp, vector<int>(n));

	function<void(int, int, int)> dfs = [&](int v, int p, int d) {
		tin[v] = tcnt++;
		depth[v] = d;
		binup[0][v] = p;
		for (int i = 1; i < bp; ++i) {
			binup[i][v] = binup[i - 1][binup[i - 1][v]];
		}

		for (int to : graph[v]) {
			if (to != p) {
				dfs(to, v, d + 1);
			}
		}

		tout[v] = tcnt;
	};

	dfs(0, 0, 0);

	auto get_lca = [&](int a, int b) {
		if (depth[a] > depth[b]) {
			swap(a, b);
		}
		for (int i = bp - 1; i >= 0; --i) {
			if (depth[a] <= depth[b] - (1 << i)) {
				b = binup[i][b];
			}
		}
		if (a == b) {
			return a;
		}
		for (int i = bp - 1; i >= 0; --i) {
			if (binup[i][a] != binup[i][b]) {
				a = binup[i][a];
				b = binup[i][b];
			}
		}
		return binup[0][a];
	};

	auto is_ancestor = [&](int a, int b) {
		return tin[a] <= tin[b] && tout[b] <= tout[a];
	};

	vector<int> marked(n);
	vector<vector<pii>> tree(n);

	function<tuple<pii, pii, int>(int)> calc = [&](int v) {
		pii n1 = {0, 0};
		pii n2 = {0, 0};
		int s = 0;
		if (marked[v]) {
			n1.ff = 1;
		}
		for (auto to : tree[v]) {
			auto [to_n1, to_n2, to_sum] = calc(to.ff);
			add(to_n1.ss, mult(to_n1.ff, to.ss));
			add(to_n2.ss, mult(to_n2.ff, to.ss));
			add(s, to_sum);
			add(s, sum(mult(n1.ff, to_n2.ss), mult(n1.ss, to_n2.ff)));
			add(s, sum(mult(n2.ff, to_n1.ss), mult(n2.ss, to_n1.ff)));
			pii nn1 = {sum(n1.ff, to_n1.ff), sum(n1.ss, to_n1.ss)};
			pii nn2 = {sum(sum(n2.ff, to_n2.ff), mult(n1.ff, to_n1.ff)), 
				sum(sum(n2.ss, to_n2.ss), sum(mult(n1.ff, to_n1.ss), mult(n1.ss, to_n1.ff)))};

			n1 = nn1;
			n2 = nn2;
		}

		tree[v].clear();
		marked[v] = 0;
		// cerr << v << " " << n1.ff << " " << n1.ss << " " << n2.ff << " " << n2.ss << " " << s << endl;
		return tuple(n1, n2, s);
	};

	int ans = 0;

	for (auto& p : by_prime) {
		vector<int> nodes = p.ss;
		// cerr << "prime " << p.ff << endl;
		for (int v : nodes) {
			// cerr << v << " ";
			marked[v] = 1;
		}
		// cerr << endl;
		sort(nodes.begin(), nodes.end(), [&](int a, int b) {
			return tin[a] < tin[b];
		});

		vector<int> st = {get_lca(nodes.front(), nodes.back())};
		for (int v : nodes) {
			int lca = get_lca(st.back(), v);
			int prev = -1;
			while (!is_ancestor(st.back(), lca)) {
				if (prev != -1) {
					tree[st.back()].push_back({prev, depth[prev] - depth[st.back()]});
				}
				prev = st.back();
				st.pop_back();
			}
			if (lca != st.back()) {
				st.push_back(lca);
			}
			if (prev != -1) {
				tree[st.back()].push_back({prev, depth[prev] - depth[st.back()]});
			}
			if (v != st.back()) {
				st.push_back(v);
			}
		}
		while (szof(st) >= 2) {
			int v = st.back();
			st.pop_back();
			tree[st.back()].push_back({v, depth[v] - depth[st.back()]});
		}

		auto res = calc(st.front());
		// cerr << get<2>(res) << endl;
		add(ans, get<2>(res));
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
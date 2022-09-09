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

void solve() {
	int n, m;
	cin >> n >> m;
	vector<vector<pii>> graph(n);
	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		--a; --b;
		graph[a].push_back({b, i});
		graph[b].push_back({a, i});
	}

	vector<int> lens;
	vector<bool> used(m);
	for (auto to : graph[0]) {
		if (!used[to.ss]) {
			int v = to.ff;
			used[to.ss] = true;
			int cnt = 1;
			while (v != 0) {
				++cnt;
				for (auto cto : graph[v]) {
					if (!used[cto.ss]) {
						v = cto.ff;
						used[cto.ss] = true;
						break;
					}
				}
			}

			lens.push_back(cnt);
		}
	}

	vector<int> dp(m * 2 + 1, 0), next(m * 2 + 1);
	dp[m] = 1;

	int bpv = 1, bp = 1;
	while (bpv < szof(lens)) {
		bpv *= 2;
		++bp;
	}

	vector<vector<int>> here(bpv * 2);

	auto add_seg = [&](int l, int r, int ind) {
		l += bpv; r += bpv;
		while (l < r) {
			if (l & 1) {
				here[l++].push_back(ind);
			}
			if (r & 1) {
				here[--r].push_back(ind);
			}
			l /= 2; r /= 2;
		}
	};

	for (int i = 0; i < szof(lens); ++i) {
		add_seg(0, i, i);
		add_seg(i + 1, bpv, i);
	}

	vector<vector<int>> mem_layers(bp, vector<int>(m * 2 + 1));

	int ans = 0;

	function<void(int, int, int, int)> dfs = [&](int v, int vl, int vr, int d) {
		copy(dp.begin(), dp.end(), mem_layers[d].begin());

		for (int ind : here[v]) {
			for (int i = 0; i < m * 2 + 1; ++i) {
				next[i] = dp[i];
				if (0 <= i - lens[ind]) {
					add(next[i], dp[i - lens[ind]]);
				}
				if (i + lens[ind] < m * 2 + 1) {
					add(next[i], dp[i + lens[ind]]);
				}
			}
			swap(next, dp);
		}

		if (vl + 1 == vr) {
			if (vl < szof(lens)) {
				for (int i = 1; i < lens[vl]; ++i) {
					int diff = i - (lens[vl] - i);
					add(ans, dp[m + diff]);
				}
				for (int i = 1; i < lens[vl] - 1; ++i) {
					int diff = i - (lens[vl] - i - 1);
					add(ans, dp[m + diff]);
				}
			}

			copy(mem_layers[d].begin(), mem_layers[d].end(), dp.begin());
			return;
		}

		int vm = (vl + vr) / 2;
		dfs(v * 2, vl, vm, d + 1);
		dfs(v * 2 + 1, vm, vr, d + 1);

		copy(mem_layers[d].begin(), mem_layers[d].end(), dp.begin());
	};

	dfs(1, 0, bpv, 0);

	dfs = [&](int v, int vl, int vr, int d) {
		copy(dp.begin(), dp.end(), mem_layers[d].begin());

		for (int ind : here[v]) {
			fill(next.begin(), next.end(), 0);
			for (int i = 0; i < m * 2 + 1; ++i) {
				if (0 <= i - lens[ind]) {
					add(next[i], dp[i - lens[ind]]);
				}
				if (i + lens[ind] < m * 2 + 1) {
					add(next[i], dp[i + lens[ind]]);
				}
			}
			swap(next, dp);
		}

		if (vl + 1 == vr) {
			if (vl < szof(lens)) {
				add(ans, mult(2, dp[m + lens[vl] - 1]));
			}

			copy(mem_layers[d].begin(), mem_layers[d].end(), dp.begin());
			return;
		}

		int vm = (vl + vr) / 2;
		dfs(v * 2, vl, vm, d + 1);
		dfs(v * 2 + 1, vm, vr, d + 1);

		copy(mem_layers[d].begin(), mem_layers[d].end(), dp.begin());
	};

	dfs(1, 0, bpv, 0);	

	for (int len : lens) {
		fill(next.begin(), next.end(), 0);
		for (int i = 0; i < m * 2 + 1; ++i) {
			if (0 <= i - len) {
				add(next[i], dp[i - len]);
			}
			if (i + len < m * 2 + 1) {
				add(next[i], dp[i + len]);
			}
		}
		swap(next, dp);
	}

	int inv2 = (MOD + 1) / 2;

	add(ans, mult(dp[m], inv2));

	cout << mult(2, ans) << "\n";
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
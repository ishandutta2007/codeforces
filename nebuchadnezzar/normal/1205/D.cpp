// Created by Nikolay Budin

#ifdef DEBUG
#  define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
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
int const INF = (int)1e9 + 1e3;
ll const INFL = (ll)1e18 + 1e6;
#ifdef LOCAL
	mt19937 tw(9450189);
#else
	mt19937 tw(chrono::high_resolution_clock::now().time_since_epoch().count());
#endif
uniform_int_distribution<ll> ll_distr;
ll rnd(ll a, ll b) { return ll_distr(tw) % (b - a + 1) + a; }


void solve() {
	int n;
	cin >> n;
	vector<vector<int>> graph(n);
	for (int i = 0; i < n - 1; ++i) {
		int a, b;
		cin >> a >> b;
		--a; --b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	vector<int> sz(n);
	vector<int> parent(n, -1);
	int best = INF, mem = -1;
	function<void(int, int)> dfs = [&](int v, int p) {
		sz[v] = 1;
		int worst = 0;
		for (int to : graph[v]) {
			if (to != p) {
				dfs(to, v);
				parent[to] = v;
				sz[v] += sz[to];
				worst = max(worst, sz[to]);
			}
		}
		worst = max(worst, n - sz[v]);
		if (worst < best) {
			best = worst;
			mem = v;
		}
	};
	dfs(0, 0);

	vector<pii> szs;
	for (int to : graph[mem]) {
		if (to != parent[mem]) {
			szs.push_back({sz[to], to});
		} else {
			szs.push_back({n - sz[mem], to});
			sz[to] = n - sz[mem];
		}
	}
	vector<int> dp(n + 1, -1);
	dp[0] = -2;
	for (pii p : szs) {
		for (int pos = n - p.ff; pos >= 0; --pos) {
			if (dp[pos] != -1 && dp[pos + p.ff] == -1) {
				dp[pos + p.ff] = p.ss;
			}
		}
	}
	int best_sz = INF;
	for (int i = n / 2; ; --i) {
		if (dp[i] != -1) {
			best_sz = i;
			break;
		}
	}
	vector<int> part1;
	while (best_sz) {
		part1.push_back(dp[best_sz]);
		best_sz -= sz[dp[best_sz]];
	}
	int cnt = 1;

	function<void(int, int, int, int&, int)> dfs_fill = [&](int v, int p, int d, int& cnt, int step) {
		int add = cnt - d;
		cout << p + 1 << " " << v + 1 << " " << add << "\n";
		cnt += step;
		d += add;
		for (int to : graph[v]) {
			if (to != p) {
				dfs_fill(to, v, d, cnt, step);
			}
		}
	};

	vector<bool> used(n);
	for (int v : part1) {
		dfs_fill(v, mem, 0, cnt, 1);
		used[v] = true;
	}
	int step = cnt;
	for (auto p : szs) {
		if (!used[p.ss]) {
			dfs_fill(p.ss, mem, 0, cnt, step);
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
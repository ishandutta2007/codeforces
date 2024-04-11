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
	int n, m;
	cin >> n >> m;
	vector<int> cost;
	ll sum = 0;
	for (int i = 0; i < n; ++i) {
		int num;
		cin >> num;
		sum += num;
		cost.push_back(num);
	}
	vector<vector<int>> graph(n);
	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		--a; --b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	int s;
	cin >> s;
	--s;

	vector<int> children(n);
	vector<int> parent(n, -1);
	vector<bool> good(n);
	vector<bool> used(n);

	function<void(int, int)> dfs = [&](int v, int p) {
		used[v] = true;
		for (int to : graph[v]) {
			if (!used[to]) {
				++children[v];
				parent[to] = v;
				dfs(to, v);
			} else if (to != p) {
				good[v] = true;
			}
		}
	};

	dfs(s, s);

	queue<int> qu;
	for (int i = 0; i < n; ++i) {
		if (!children[i] && i != s && !good[i]) {
			qu.push(i);
		}
	}

	vector<bool> removed(n);

	while (szof(qu)) {
		int v = qu.front();
		qu.pop();
		removed[v] = true;
		sum -= cost[v];
		--children[parent[v]];
		if (!children[parent[v]] && parent[v] != s && !good[parent[v]]) {
			qu.push(parent[v]);
		}
	}

	fill(used.begin(), used.end(), 0);

	function<ll(int)> find_best = [&](int v) {
		used[v] = true;
		ll ret = 0;
		for (int to : graph[v]) {
			if (!used[to]) {
				ret = max(ret, find_best(to));
			}
		}
		if (removed[v]) {
			ret += cost[v];
		}
		return ret;
	};

	cout << sum + find_best(s) << "\n";
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
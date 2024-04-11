// Created by Nikolay Budin

#ifdef LOCAL
#  define _GLIBCXX_DEBUG
#else
#  define cerr __get_ce
#endif
#include <bits/stdc++.h>
#define ff first
#define ss second
#define szof(x) ((int)x.size())

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
	int n;
	cin >> n;
	vector<vector<int>> graph(n);
	for (int i = 1; i < n; ++i) {
		int p;
		cin >> p;
		--p;
		graph[p].push_back(i);
	}

	vector<tuple<int, int, int>> d(n);

	function<void(int)> dfs = [&](int v) {
		if (!szof(graph[v])) {
			d[v] = {0, 1, 1};
			return;
		}
		vector<int> tmp(3);
		tmp[0] = 1;
		for (int to : graph[v]) {
			dfs(to);
			vector<int> next(3);
			for (int i = 0; i < 3; ++i) {
				add(next[i], mult(tmp[i], get<2>(d[to])));
				add(next[i], mult(tmp[i], get<0>(d[to])));
				add(next[min(2, i + 1)], mult(tmp[i], get<1>(d[to])));
			}
			swap(next, tmp);
			// cerr << v << endl;
			// for (int i = 0; i < 3; ++i) {
			// 	cerr << tmp[i] << " ";
			// }
			// cerr << endl;
		}

		get<2>(d[v]) = tmp[2];
		for (int i = 1; i < 3; ++i) {
			add(get<1>(d[v]), tmp[i]);
		}
		get<0>(d[v]) = tmp[0];
		// cerr << v << " " << get<0>(d[v]) << " " << get<1>(d[v]) << " " << get<2>(d[v]) << endl;
	};

	dfs(0);

	cout << sum(get<0>(d[0]), get<2>(d[0])) << "\n";
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
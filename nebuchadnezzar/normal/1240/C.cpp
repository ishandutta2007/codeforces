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
typedef pair<ll, ll> pll;
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
	int n, k;
	cin >> n >> k;
	vector<vector<pii>> graph(n);
	for (int i = 0; i < n - 1; ++i) {
		int a, b, c;
		cin >> a >> b >> c;
		--a; --b;
		graph[a].push_back({b, c});
		graph[b].push_back({a, c});
	}

	vector<pll> dp(n);

	function<void(int, int)> dfs = [&](int v, int p) {
		ll res = 0;
		vector<ll> vars;
		for (auto to : graph[v]) {
			if (to.ff != p) {
				dfs(to.ff, v);
				ll val1 = dp[to.ff].ff;
				ll val2 = dp[to.ff].ss + to.ss;
				if (val1 > val2) {
					res += val1;
				} else {
					res += val1;
					vars.push_back(val2 - val1);
				}
			}
		}
		if (szof(vars) <= k - 1) {
			for (auto num : vars) {
				res += num;
			}
			dp[v] = {res, res};
		} else {
			nth_element(vars.begin(), vars.end() - k, vars.end());
			for (int i = 0; i < k; ++i) {
				res += vars[szof(vars) - 1 - i];
			}
			dp[v] = {res, res - *min_element(vars.end() - k, vars.end())};
		}
	};

	dfs(0, 0);

	cout << dp[0].ff << "\n";
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
	cin >> test_count;
	for (int test = 1; test <= test_count; ++test) {
		solve();
	}
	
#ifdef LOCAL
	auto end_time = clock();
	cerr << "Execution time: " << (end_time - start_time) * (int)1e3 / CLOCKS_PER_SEC << " ms\n";
#endif
}
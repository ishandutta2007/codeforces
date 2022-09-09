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
	vector<pii> vals(n);
	vector<vector<int>> graph(n);
	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		--a; --b;
		if (a > b) {
			swap(a, b);
		}
		vals[a].ss++;
		vals[b].ff++;
		graph[a].push_back(b);
	}
	ll sum = 0;
	for (int i = 0; i < n; ++i) {
		sum += (ll) vals[i].ff * vals[i].ss;
	}
	cout << sum << "\n";
	int q;
	cin >> q;
	vector<int> neibs;
	for (int i = 0; i < q; ++i) {
		int v;
		cin >> v;
		--v;
		for (int u : graph[v]) {
			sum -= (ll) vals[u].ff * vals[u].ss;
			--vals[u].ff;
			++vals[u].ss;
			sum += (ll) vals[u].ff * vals[u].ss;
			graph[u].push_back(v);
		}
		sum -= (ll) vals[v].ff * vals[v].ss;
		vals[v].ff += vals[v].ss;
		vals[v].ss = 0;
		graph[v].clear();
		cout << sum << "\n";
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
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

const int P = 60;

void solve() {
	int n;
	cin >> n;
	vector<ll> arr;
	vector<vector<int>> here(P);
	for (int i = 0; i < n; ++i) {
		ll num;
		cin >> num;
		arr.push_back(num);
		for (int j = 0; j < P; ++j) {
			if (num & (1ll << j)) {
				here[j].push_back(i);
			}
		}
	}

	for (int i = 0; i < P; ++i) {
		if (szof(here[i]) >= 3) {
			cout << "3\n";
			return;
		}
	}

	// assert(n <= 120);

	vector<set<int>> graph(n);
	set<pii> edges;
	for (int i = 0; i < P; ++i) {
		for (int v : here[i]) {
			for (int u : here[i]) {
				if (v < u) {
					graph[v].insert(u);
					graph[u].insert(v);
					edges.insert({v, u});
				}
			}
		}
	}

	// assert(szof(edges) <= 120);

	vector<int> dist(n, INF);
	auto get_dist = [&](int a, int b) {
		dist[a] = 0;
		queue<int> qu;
		qu.push(a);
		vector<int> visited;
		while (szof(qu)) {
			int v = qu.front();
			qu.pop();
			visited.push_back(v);
			for (int to : graph[v]) {
				if (dist[to] > dist[v] + 1) {
					dist[to] = dist[v] + 1;
					qu.push(to);
				}
			}
		}
		int ret = dist[b];
		for (int v : visited) {
			dist[v] = INF;
		}
		return ret;
	};

	int ans = INF;
	for (auto [a, b] : edges) {
		graph[a].erase(b);
		graph[b].erase(a);
		ans = min(ans, get_dist(a, b) + 1);
		graph[a].insert(b);
		graph[b].insert(a);
	}

	if (ans == INF) {
		cout << "-1\n";
	} else {
		cout << ans << "\n";
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
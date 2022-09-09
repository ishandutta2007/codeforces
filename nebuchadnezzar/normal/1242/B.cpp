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
	vector<vector<int>> graph(n);
	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		--a; --b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	set<int> left;
	for (int i = 0; i < n; ++i) {
		left.insert(i);
	}
	int comps = 0;
	vector<int> to_add;
	for (int i = 0; i < n; ++i) {
		if (left.count(i)) {
			++comps;
			queue<int> qu;
			qu.push(i);
			left.erase(i);
			while (szof(qu)) {
				int v = qu.front();
				qu.pop();
				sort(graph[v].begin(), graph[v].end());
				int cnt = 0;
				to_add.clear();
				for (int u : left) {
					while (cnt < szof(graph[v]) && graph[v][cnt] < u) {
						++cnt;
					}
					if (cnt < szof(graph[v]) && graph[v][cnt] == u) {

					} else {
						to_add.push_back(u);
					}
				}
				for (int u : to_add) {
					qu.push(u);
					left.erase(u);
				}
			}
		}
	}

	cout << comps - 1 << "\n";
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
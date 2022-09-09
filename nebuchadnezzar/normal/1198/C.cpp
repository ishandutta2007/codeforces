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


void solve() {
	int n, m;
	cin >> n >> m;
	vector<int> matching;
	vector<set<pii>> graph(n * 3);
	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		--a; --b;
		graph[a].insert({b, i});
		graph[b].insert({a, i});
	}
	set<pii> left;
	for (int i = 0; i < n * 3; ++i) {
		left.insert({szof(graph[i]), i});
	}
	vector<int> indset;

	auto remove = [&](int v) {
		left.erase({szof(graph[v]), v});
		for (auto to : graph[v]) {
			left.erase({szof(graph[to.ff]), to.ff});
			graph[to.ff].erase({v, to.ss});
			left.insert({szof(graph[to.ff]), to.ff});
		}
	};

	while (szof(matching) < n) {
		int v = (--left.end())->ss;
		if (!szof(graph[v])) {
			for (auto p : left) {
				indset.push_back(p.ss);
				if (szof(indset) == n) {
					break;
				}
			}
			break;
		}
		matching.push_back(graph[v].begin()->ss);
		int u = graph[v].begin()->ff;
		remove(v);
		remove(u);
	}

	if (szof(matching) == n) {
		cout << "Matching\n";
		for (int ind : matching) {
			cout << ind + 1 << " ";
		}
		cout << "\n";
	} else if (szof(indset) == n) {
		cout << "IndSet\n";
		for (int ind : indset) {
			cout << ind + 1 << " ";
		}
		cout << "\n";
	} else {
		assert(false);
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
	cin >> test_count;
	for (int test = 1; test <= test_count; ++test) {
		solve();
	}
	
#ifdef LOCAL
	auto end_time = clock();
	cerr << "Execution time: " << (end_time - start_time) * (int)1e3 / CLOCKS_PER_SEC << " ms\n";
#endif
}
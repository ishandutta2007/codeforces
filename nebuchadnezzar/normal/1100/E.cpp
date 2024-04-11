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
int const INF = (int)1e9 + 1e3;
ll const INFL = (ll)1e18 + 1e6;
mt19937 tw(9450189);
uniform_int_distribution<ll> ll_distr;
ll rnd(ll a, ll b) { return ll_distr(tw) % (b - a + 1) + a; }


void solve() {
	int n, m;
	cin >> n >> m;
	vector<pair<pii, pii>> edges;
	for (int i = 0; i < m; ++i) {
		int u, v, c;
		cin >> u >> v >> c;
		--u; --v;
		edges.push_back({{c, i}, {u, v}});
	}

	sort(edges.begin(), edges.end());

	int l = 0, r = m + 1;
	vector<vector<int>> graph(n);
	vector<int> used(n);

	function<bool(int)> dfs = [&](int v) {
		used[v] = 1;

		for (int to : graph[v]) {
			if (!used[to]) {
				if (dfs(to)) {
					return true;
				}
			} else if (used[to] == 1) {
				return true;
			}
		}

		used[v] = 2;
		return false;
	};

	while (r - l > 1) {
		int mid = (l + r) / 2;
		for (int i = 0; i < n; ++i) {
			graph[i].clear();
		}
		for (int i = 0; i < mid; ++i) {
			graph[edges[m - 1 - i].ss.ff].push_back(edges[m - 1 - i].ss.ss);
		}

		fill(used.begin(), used.end(), 0);

		bool fail = false;

		for (int i = 0; i < n; ++i) {
			if (!used[i]) {
				if (dfs(i)) {
					fail = true;
					break;
				}
			}
		}

		if (fail) {
			r = mid;
		} else {
			l = mid;
		}
	}

	if (l == m) {
		cout << "0 0\n";
		return;
	}

	for (int i = 0; i < n; ++i) {
		graph[i].clear();
	}

	for (int i = 0; i < l; ++i) {
		graph[edges[m - 1 - i].ss.ff].push_back(edges[m - 1 - i].ss.ss);
	}

	fill(used.begin(), used.end(), 0);

	vector<int> order;

	function<void(int)> topsort = [&](int v) {
		used[v] = true;
		for (int to : graph[v]) {
			if (!used[to]) {
				topsort(to);
			}
		}
		order.push_back(v);
	};

	for (int i = 0; i < n; ++i) {
		if (!used[i]) {
			topsort(i);
		}
	}

	vector<int> where(n);
	for (int i = 0; i < n; ++i) {
		where[order[i]] = i;
	}

	cout << edges[m - 1 - l].ff.ff << " ";

	vector<int> ans;
	for (int i = 0; i < m - l; ++i) {
		if (where[edges[i].ss.ff] < where[edges[i].ss.ss]) {
			ans.push_back(edges[i].ff.ss);
		}
	}

	cout << szof(ans) << "\n";
	for (int num : ans) {
		cout << num + 1 << " ";
	}
	cout << "\n";
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
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
	int n, m, k;
	cin >> n >> m >> k;
	vector<vector<int>> graph(n);
	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		--a; --b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	vector<vector<int>> tree(n);
	vector<bool> used(n);
	vector<int> dist(n);
	vector<int> parent(n);

	function<void(int)> dfs = [&](int v) {
		used[v] = true;
		for (int to : graph[v]) {
			if (!used[to]) {
				dist[to] = dist[v] + 1;
				parent[to] = v;
				dfs(to);
				tree[v].push_back(to);
			}
		}
	};

	dfs(0);

	int cnt = 0;
	vector<int> leafs;
	for (int i = 1; i < n; ++i) {
		if (!szof(tree[i])) {
			if (dist[i] + 1 >= (n + k - 1) / k) {
				vector<int> path;
				int cur = i;
				while (cur != 0) {
					path.push_back(cur);
					cur = parent[cur];
				}
				path.push_back(0);
				cout << "PATH\n";
				cout << szof(path) << "\n";
				for (int v : path) {
					cout << v + 1 << " ";
				}
				cout << "\n";
				return;
			}
			++cnt;
			leafs.push_back(i);
		}
	}

	assert(cnt >= k);

	cout << "CYCLES\n";

	for (int i = 0; i < k; ++i) {
		int best = -1;
		int mem = -1;
		int v = leafs[i];
		vector<int> bad;
		for (int to : graph[v]) {
			if (dist[to] + 1 < dist[v] && (dist[v] - dist[to] + 1) % 3 != 0) {
				if (best < dist[to]) {
					best = dist[to];
					mem = to;
				}
			} else if (dist[to] + 1 < dist[v]) {
				bad.push_back(to);
			}
		}
		if (mem != -1) {
			vector<int> path;
			int cur = v;
			while (cur != mem) {
				path.push_back(cur);
				cur = parent[cur];
			}
			path.push_back(mem);
			cout << szof(path) << "\n";
			for (int v : path) {
				cout << v + 1 << " ";
			}
			cout << "\n";
		} else {
			vector<int> path;
			path.push_back(v);
			assert(szof(bad) >= 2);
			sort(bad.begin(), bad.end());
			reverse(bad.begin(), bad.end());
			bad.resize(2);
			int cur = bad[0];
			while (cur != bad[1]) {
				path.push_back(cur);
				cur = parent[cur];
			}
			path.push_back(bad[1]);
			cout << szof(path) << "\n";
			for (int v : path) {
				cout << v + 1 << " ";
			}
			cout << "\n";
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
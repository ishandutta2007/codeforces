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
	vector<vector<int>> graph(n);
	for (int i = 0; i < m; ++i) {
		int k;
		cin >> k;
		vector<int> path;
		for (int j = 0; j < k; ++j) {
			int v;
			cin >> v;
			--v;
			path.push_back(v);
		}
		for (int j = 0; j < k - 1; ++j) {
			graph[path[j]].push_back(path[j + 1]);
			graph[path[j + 1]].push_back(path[j]);
		}
	}

	vector<vector<int>> dists;

	for (int i = 0; i < n; ++i) {
		vector<int> dist(n, INF);
		dist[i] = 0;
		queue<int> qu;
		qu.push(i);
		while (szof(qu)) {
			int v = qu.front();
			qu.pop();
			for (int to : graph[v]) {
				if (dist[to] > dist[v] + 1) {
					dist[to] = dist[v] + 1;
					qu.push(to);
				}
			}
		}

		dists.push_back(dist);
	}

	for (int i = 0; i < n; ++i) {
		vector<int> left;
		for (int j = 0; j < n; ++j)	{
			left.push_back(j);
		}

		int steps = 0;
		while (true) {
			int best = INF;
			vector<int> arr;
			for (int j = 0; j < n; ++j) {
				int cur = 0;
				for (int to : graph[j]) {
					int cnt = 0;
					for (int v : left) {
						if (dists[v][to] < dists[v][j]) {
							++cnt;
						}
					}
					cur = max(cur, cnt);
				}
				if (cur < best) {
					best = cur;
					arr = {j};
				} else if (cur == best) {
					arr.push_back(j);
				}
			}

			int mem = arr[rnd(0, szof(arr) - 1)];

			++steps;
			assert(steps <= 10);

			cout << mem + 1 << endl;
			string s;
			cin >> s;
			if (s == "FOUND") {
				break;
			} else {
				int better;
				cin >> better;
				--better;
				vector<int> next;
				for (int u : left) {
					if (dists[u][better] < dists[u][mem]) {
						next.push_back(u);
					}
				}
				swap(next, left);
			}
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
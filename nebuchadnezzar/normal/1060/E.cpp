#ifdef LOCAL
#  define _GLIBCXX_DEBUG
#  define _GLIBCXX_DEBUG_PEDANTIC
#endif

#include "bits/stdc++.h"
#define ff first
#define ss second
#define szof(_x) ((int) (_x).size())
#define TASK_NAME ""

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int INF = 1e9 + 7;
const ll INFL = 1e18 + 123;
const double PI = atan2(0, -1);
mt19937 tw(960172);
ll rnd(ll x, ll y) { static uniform_int_distribution<ll> d; return d(tw) % (y - x + 1) + x; }


void solve() {
	int n;
	cin >> n;
	vector<vector<int>> graph(n);
	for (int i = 0; i < n - 1; ++i) {
		int a, b;
		cin >> a >> b;
		--a; --b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	ll ans = 0;
	vector<pii> mem(n);
	vector<int> sz(n);

	function<pii(int, int)> dfs = [&](int v, int p) {
		pii cnt = {1, 0};
		sz[v] = 1;
		for (int to : graph[v]) {
			if (to != p) {
				pii tmp = dfs(to, v);
				sz[v] += sz[to];
				// ans += (ll) cnt.ss * (tmp.ff + tmp.ss);
				cnt.ff += tmp.ss;
				cnt.ss += tmp.ff;
			}
		}
		mem[v] = cnt;
		// cerr << v << " " << cnt.ff << " " << cnt.ss << endl;
		return cnt;
	};

	function<void(int, int, pii)> dfs2 = [&](int v, int p, pii cnt) {
		swap(cnt.ff, cnt.ss);
		cnt.ff += 1;
		// cerr << v << " " << cnt.ff << " " << cnt.ss << endl;
		/*pii down = cnt;
		for (int to : graph[v]) {
			if (to != p) {
				down.ff += mem[to].ss;
				down.ss += mem[to].ff;
			}
		}*/

		for (int to : graph[v]) {
			if (to != p) {
				ans += (ll) cnt.ff * sz[to] + (ll) mem[to].ff * (n - sz[to] - cnt.ff - cnt.ss);
				// down.ff -= mem[to].ss;
				// down.ss -= mem[to].ff;
				dfs2(to, v, cnt);
				// down.ff += mem[to].ss;
				// down.ss += mem[to].ff;

				cnt.ff += mem[to].ss;
				cnt.ss += mem[to].ff;
			}
		}
	};

	dfs(0, 0);
	dfs2(0, 0, {0, 0});
	cout << ans << "\n";
	
	/*vector<vector<int>> graph2(n);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < szof(graph[i]); ++j) {
			graph2[i].push_back(graph[i][j]);
			for (int k = j + 1; k < szof(graph[i]); ++k) {
				int a = graph[i][j];
				int b = graph[i][k];
				graph2[a].push_back(b);
				graph2[b].push_back(a);
			}
		}
	}

	function<vector<int>(int, vector<vector<int>> const&)> get_dist = [&](int v, vector<vector<int>> const& g) {
		vector<int> dist(n, INF);
		dist[v] = 0;
		queue<int> qu;
		qu.push(v);
		while (szof(qu)) {
			int u = qu.front();
			qu.pop();
			for (int to : g[u]) {
				if (dist[to] > dist[u] + 1) {
					dist[to] = dist[u] + 1;
					qu.push(to);
				}
			}
		}
		return dist;
	};

	ll sum = 0;
	for (int i = 0; i < n; ++i) {
		auto tmp = get_dist(i, graph2);
		for (int num : tmp) {
			sum += num;
		}
	}

	sum /= 2;

	if (sum != ans) {
		cout << ans << " " << sum << endl;
	}
	assert(sum == ans);*/
}


int main() {
	//freopen(TASK_NAME ".in", "r", stdin);
	//freopen(TASK_NAME ".out", "w", stdout);
	cerr << fixed << setprecision(15);
	cout << fixed << setprecision(15);
	ios::sync_with_stdio(false);

	int tests = 1;
	// cin >> tests;
	for (int it = 1; it <= tests; ++it) {
		solve();
	}
	
	#ifdef LOCAL
		cerr << "time: " << clock() << " ms\n";
	#endif
	return 0;
}
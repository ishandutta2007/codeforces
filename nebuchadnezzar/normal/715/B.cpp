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

vector<vector<pii>> graph;

ll get_dist(int s, int t) {
	vector<ll> dist(szof(graph), INFL);
	dist[s] = 0;
	set<pair<ll, int>> st;
	st.insert({0, s});
	while (szof(st)) {
		int v = st.begin()->ss;
		st.erase(st.begin());
		for (pii to : graph[v]) {
			if (dist[to.ff] > dist[v] + to.ss) {
				st.erase({dist[to.ff], to.ff});
				dist[to.ff] = dist[v] + to.ss;
				st.insert({dist[to.ff], to.ff});
			}
		}
	}
	return dist[t];
}


void solve() {
	int n, m, len, s, t;
	cin >> n >> m >> len >> s >> t;
	vector<tuple<int, int, int>> edges;
	for (int i = 0; i < m; ++i) {
		int u, v, w;
		cin >> u >> v >> w;
		edges.push_back({u, v, w});
	}

	int l = 0, r = len + 2;
	while (r - l > 1) {
		int mid = (l + r) / 2;
		graph = vector<vector<pii>>(n);
		for (auto e : edges) {
			int u, v, w;
			tie(u, v, w) = e;
			if (!w) {
				w = mid;
			}
			graph[u].push_back({v, w});
			graph[v].push_back({u, w});
		}

		ll d = get_dist(s, t);
		if (d == len) {
			cout << "YES\n";
			for (auto e : edges) {
				int u, v, w;
				tie(u, v, w) = e;
				if (!w) {
					w = mid;
				}
				cout << u << " " << v << " " << w << "\n";
			}
			return;
		}
		if (d < len) {
			l = mid;
		} else {
			r = mid;
		}
	}
	if (!l) {
		cout << "NO\n";
		return;
	}
	int mem = l;
	l = 0, r = m;
	while (r - l > 1) {
		int mid = (l + r) / 2;
		graph = vector<vector<pii>>(n);
		int cnt = 0;
		for (auto e : edges) {
			int u, v, w;
			tie(u, v, w) = e;
			if (!w) {
				w = mem + (cnt < mid);
				++cnt;
			}
			graph[u].push_back({v, w});
			graph[v].push_back({u, w});
		}

		ll d = get_dist(s, t);
		if (d == len) {
			cout << "YES\n";
			cnt = 0;
			for (auto e : edges) {
				int u, v, w;
				tie(u, v, w) = e;
				if (!w) {
					w = mem + (cnt < mid);
					++cnt;
				}
				cout << u << " " << v << " " << w << "\n";
			}
			return;
		}
		if (d < len) {
			l = mid;
		} else {
			r = mid;
		}
	}
	cout << "NO\n";
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
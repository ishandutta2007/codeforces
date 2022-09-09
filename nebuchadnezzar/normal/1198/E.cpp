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

struct edge {
	int f, c;
	edge(int _c) : f(0), c(_c) {}
};

vector<edge> edges;
vector<vector<pii>> graph;

int add_node() {
	graph.push_back({});
	return szof(graph) - 1;
}

void add_edge(int a, int b, int c) {
	graph[a].push_back({b, szof(edges)});
	edges.push_back(edge(c));
	graph[b].push_back({a, szof(edges)});
	edges.push_back(edge(0));
}

vector<int> vcnt, dist, qu;

int build_layers(int s, int t) {
	fill(dist.begin(), dist.end(), INF);
	dist[s] = 0;
	int l = 0, r = 0;
	qu[r++] = s;
	while (l < r) {
		int v = qu[l++];
		for (auto to : graph[v]) {
			if (edges[to.ss].f < edges[to.ss].c && dist[to.ff] > dist[v] + 1) {
				dist[to.ff] = dist[v] + 1;
				qu[r++] = to.ff;
			}
		}
	}

	if (dist[t] == INF) {
		return 0;
	}
	return 1;
}

int push_flow(int v, int t, int f) {
	if (v == t) {
		return f;
	}
	while (vcnt[v] < szof(graph[v])) {
		auto to = graph[v][vcnt[v]];
		if (dist[to.ff] == dist[v] + 1 && edges[to.ss].f < edges[to.ss].c) {
			int tmp = push_flow(to.ff, t, min(f, edges[to.ss].c - edges[to.ss].f));
			if (tmp) {
				edges[to.ss].f += tmp;
				edges[to.ss ^ 1].f -= tmp;
				return tmp;
			}
		}
		vcnt[v]++;
	}
	return 0;
}

void solve() {
	int n, m;
	cin >> n >> m;
	vector<tuple<int, int, int, int>> rects;
	vector<int> arrx, arry;
	arrx.push_back(0);
	arrx.push_back(n);
	arry.push_back(0);
	arry.push_back(n);
	for (int i = 0; i < m; ++i) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		--x1; --y1;
		arrx.push_back(x1);
		arrx.push_back(x2);
		arry.push_back(y1);
		arry.push_back(y2);
		rects.push_back({x1, y1, x2, y2});
	}

	sort(arrx.begin(), arrx.end());
	arrx.erase(unique(arrx.begin(), arrx.end()), arrx.end());

	sort(arry.begin(), arry.end());
	arry.erase(unique(arry.begin(), arry.end()), arry.end());

	vector<vector<int>> field(szof(arrx) - 1, vector<int>(szof(arry) - 1));

	for (auto [x1, y1, x2, y2] : rects) {
		int fromx = lower_bound(arrx.begin(), arrx.end(), x1) - arrx.begin();
		int tox = lower_bound(arrx.begin(), arrx.end(), x2) - arrx.begin();

		int fromy = lower_bound(arry.begin(), arry.end(), y1) - arry.begin();
		int toy = lower_bound(arry.begin(), arry.end(), y2) - arry.begin();

		for (int i = fromx; i < tox; ++i) {
			for (int j = fromy; j < toy; ++j) {
				field[i][j] = 1;
			}
		}
	}

	// vector<vector<int>> cost(szof(arrx), vector<int>(szof(arry), INF));
	int s = add_node();
	int t = add_node();
	vector<int> left, right;
	for (int i = 0; i < szof(arrx) - 1; ++i) {
		left.push_back(add_node());
		add_edge(s, left[i], arrx[i + 1] - arrx[i]);
	}
	for (int i = 0; i < szof(arry) - 1; ++i) {
		right.push_back(add_node());
		add_edge(right[i], t, arry[i + 1] - arry[i]);
	}

	for (int i = 0; i < szof(arrx) - 1; ++i) {
		for (int j = 0; j < szof(arry) - 1; ++j) {
			if (field[i][j]) {
				// cost[i + 1][j + 1] = min(arrx[i + 1] - arrx[i], arry[j + 1] - arry[j]);
				add_edge(left[i], right[j], INF);
			}
		}
	}

	int ans = 0;

	vcnt = dist = qu = vector<int>(szof(graph));

	while (build_layers(s, t)) {
		fill(vcnt.begin(), vcnt.end(), 0);
		while (true) {
			int tmp = push_flow(s, t, INF);
			if (!tmp) {
				break;
			}
			ans += tmp;
		}
	}

	cout << ans << "\n";
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
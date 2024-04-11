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

vector<int> dist, qu, vcnt;

bool build_layers(int s, int t) {
	fill(dist.begin(), dist.end(), INF);
	dist[s] = 0;
	int l = 0, r = 0;
	qu[r++] = s;
	while (l < r) {
		int v = qu[l++];
		for (pii to : graph[v]) {
			if (edges[to.ss].f < edges[to.ss].c && dist[to.ff] > dist[v] + 1) {
				dist[to.ff] = dist[v] + 1;
				qu[r++] = to.ff;
			}
		}
	}

	if (dist[t] == INF) {
		return false;
	}
	return true;
}

int push_flow(int v, int t, int f) {
	if (v == t) {
		return f;
	}
	while (vcnt[v] < szof(graph[v])) {
		pii to = graph[v][vcnt[v]];
		if (edges[to.ss].f < edges[to.ss].c && dist[to.ff] == dist[v] + 1) {
			int tmp = push_flow(to.ff, t, min(f, edges[to.ss].c - edges[to.ss].f));
			if (tmp) {
				edges[to.ss].f += tmp;
				edges[to.ss ^ 1].f -= tmp;
				return tmp;
			}
		}
		++vcnt[v];
	}
	return 0;
}

void solve() {
	int n, h, m;
	cin >> n >> h >> m;
	int s = add_node();
	int t = add_node();
	vector<vector<int>> buildings(n);
	for (int i = 0; i < n; ++i) {
		int prev = 0;
		for (int j = 1; j <= h; ++j) {
			buildings[i].push_back(add_node());
			add_edge(buildings[i][j - 1], t, j * j - prev);
			prev = j * j;
			if (j > 1) {
				add_edge(buildings[i][j - 2], buildings[i][j - 1], INF);
			}
		}
	}

	for (int i = 0; i < m; ++i) {
		int l, r, x, c;
		cin >> l >> r >> x >> c;
		if (x == h) {
			continue;
		}
		--l;
		int tmp = add_node();
		add_edge(s, tmp, c);
		for (int j = l; j < r; ++j) {
			add_edge(tmp, buildings[j][x], INF);
		}
	}

	dist = qu = vcnt = vector<int>(szof(graph));

	int f = 0;
	while (build_layers(s, t)) {
		fill(vcnt.begin(), vcnt.end(), 0);
		while (true) {
			int tmp = push_flow(s, t, INF);
			if (!tmp) {
				break;
			}
			f += tmp;
		}
	}

	cout << n * h * h - f << "\n";
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
// Created by Nikolay Budin

#ifdef DEBUG
#  define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
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

using namespace __gnu_pbds;
template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename K, typename V> using ordered_map = tree<K, V, less<K>, rb_tree_tag, tree_order_statistics_node_update>;

int const INF = (int)1e9 + 1e3;
ll const INFL = (ll)1e18 + 1e6;
#ifdef LOCAL
	mt19937 tw(9450189);
#else
	mt19937 tw(chrono::high_resolution_clock::now().time_since_epoch().count());
#endif
uniform_int_distribution<ll> ll_distr;
ll rnd(ll a, ll b) { return ll_distr(tw) % (b - a + 1) + a; }

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

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

vector<int> dist, vcnt, qu;

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
	return dist[t] != INF;
}

int push_flow(int v, int t, int f) {
	if (v == t) {
		return f;
	}
	int ret = 0;
	while (vcnt[v] < szof(graph[v])) {
		auto to = graph[v][vcnt[v]];
		if (edges[to.ss].f < edges[to.ss].c && dist[to.ff] == dist[v] + 1) {
			int tmp = push_flow(to.ff, t, min(f, edges[to.ss].c - edges[to.ss].f));
			if (tmp) {
				edges[to.ss].f += tmp;
				edges[to.ss ^ 1].f -= tmp;
				ret += tmp;
				f -= tmp;
				if (!f) {
					return ret;
				}
			}
		}
		++vcnt[v];
	}
	return ret;
}

void solve() {
	int n;
	cin >> n;
	vector<int> arr;
	ll white = 0, black = 0;
	ll tot = 0;
	for (int i = 0; i < n; ++i) {
		int num;
		cin >> num;
		arr.push_back(num);
		tot += num;
		if (i % 2) {
			white += num / 2;
			black += num - num / 2;
		} else {
			black += num / 2;
			white += num - num / 2;
		}
	}

	if (tot > 100000) {
		cout << min(white, black) << "\n";
		return;
	}

	int s = add_node();
	int t = add_node();

	map<pii, int> cells;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < arr[i]; ++j) {
			cells[{i, j}] = add_node();
		}
	}

	for (auto p : cells) {
		if ((p.ff.ff + p.ff.ss) % 2) {
			add_edge(s, p.ss, 1);
			for (int d = 0; d < 4; ++d) {
				int nx = p.ff.ff + dx[d];
				int ny = p.ff.ss + dy[d];
				if (cells.count({nx, ny})) {
					add_edge(p.ss, cells[{nx, ny}], 1);
				}
			}
		} else {
			add_edge(p.ss, t, 1);
		}
	}

	dist = vcnt = qu = vector<int>(szof(graph));

	ll ans = 0;

	while (build_layers(s, t)) {
		fill(vcnt.begin(), vcnt.end(), 0);
		while (true) {
			int f = push_flow(s, t, INF);
			if (!f) {
				break;
			}
			ans += f;
		}
	}

	// cerr << ans << " " << min(white, black) << endl;

	assert(ans == min(white, black));

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
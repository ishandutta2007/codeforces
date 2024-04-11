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

int build_layers(int s, int t) {
	fill(dist.begin(), dist.end(), INF);
	dist[s] = 0;
	int l = 0, r = 0;
	qu[r++] = s;
	fill(vcnt.begin(), vcnt.end(), 0);
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
		return 0;
	}
	return 1;
}

int push_flow(int v, int t, int f) {
	if (v == t) {
		return f;
	}
	while (vcnt[v] < szof(graph[v])) {
		pii to = graph[v][vcnt[v]];
		if (dist[to.ff] == dist[v] + 1 && edges[to.ss].f < edges[to.ss].c) {
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
	graph.clear();
	edges.clear();
	int n, m, k;
	cin >> n >> m >> k;
	vector<pii> gedges;
	int s = add_node();
	int t = add_node();
	vector<int> node_nodes;
	for (int i = 0; i < n; ++i) {
		node_nodes.push_back(add_node());
	}
	vector<int> edge_nodes;
	vector<int> deg(n);
	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		--a; --b;
		gedges.push_back({a, b});
		deg[a]++;
		deg[b]++;
		int tmp = add_node();
		edge_nodes.push_back(tmp);
		add_edge(s, tmp, 1);
		add_edge(tmp, node_nodes[a], 1);
		add_edge(tmp, node_nodes[b], 1);
	}

	int need = 0;
	for (int i = 0; i < n; ++i) {
		if (deg[i] > k * 2) {
			for (int j = 0; j < m; ++j) {
				cout << "0 ";
			}
			cout << "\n";
			return;
		}
		if (deg[i] <= k) {
			continue;
		}
		int tmp = deg[i] - k;
		tmp *= 2;
		assert(tmp <= deg[i]);
		add_edge(node_nodes[i], t, tmp);
		need += tmp;
	}

	dist = qu = vcnt = vector<int>(szof(graph));

	int f = 0;
	while (true) {
		if (!build_layers(s, t)) {
			break;
		}
		while (true) {
			int tmp = push_flow(s, t, INF);
			if (!tmp) {
				break;
			}
			f += tmp;
		}
	}

	if (f < need) {
		for (int i = 0; i < m; ++i) {
			cout << "0 ";
		}
		cout << "\n";
		return;
	}

	vector<vector<int>> here(n);

	for (int i = 0; i < m; ++i) {
		for (pii to : graph[edge_nodes[i]]) {
			if (to.ff != s && edges[to.ss].f) {
				if (to.ff == node_nodes[gedges[i].ff]) {
					here[gedges[i].ff].push_back(i);
				} else {
					here[gedges[i].ss].push_back(i);
				}
				break;
			}
		}
	}

	vector<int> outp(m);
	iota(outp.begin(), outp.end(), 12345);

	int cnt = 1;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < szof(here[i]); j += 2) {
			outp[here[i][j]] = cnt;
			outp[here[i][j + 1]] = cnt;
			++cnt;
		}
	}

	for (int num : outp) {
		cout << num << " ";
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
	cin >> test_count;
	for (int test = 1; test <= test_count; ++test) {
		solve();
	}
	
#ifdef LOCAL
	auto end_time = clock();
	cerr << "Execution time: " << (end_time - start_time) * (int)1e3 / CLOCKS_PER_SEC << " ms\n";
#endif
}
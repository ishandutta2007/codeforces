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
	int f, c, cost;
	edge(int _c, int _cost) : f(0), c(_c), cost(_cost) {}
};

vector<edge> edges;

vector<vector<pii>> graph;

int add_node() {
	graph.push_back({});
	return szof(graph) - 1;
}

void add_edge(int a, int b, int c, int cost) {
	graph[a].push_back({b, szof(edges)});
	edges.push_back(edge(c, cost));
	graph[b].push_back({a, szof(edges)});
	edges.push_back(edge(0, -cost));
}

vector<ll> dist;
vector<bool> in_queue;
vector<pii> from;

pair<int, ll> push_flow(int s, int t) {
	queue<int> qu;
	qu.push(s);
	fill(dist.begin(), dist.end(), INFL);
	dist[s] = 0;

	while (szof(qu)) {
		int v = qu.front();
		// cerr << v << endl;
		in_queue[v] = false;
		qu.pop();
		for (auto to : graph[v]) {
			// cerr << "to " << to.ff << " " << edges[to.ss].f << " " << edges[to.ss].c << " " << edges[to.ss].cost << endl;
			if (edges[to.ss].f < edges[to.ss].c && dist[to.ff] > dist[v] + edges[to.ss].cost) {
				dist[to.ff] = dist[v] + edges[to.ss].cost;
				from[to.ff] = {v, to.ss};
				if (!in_queue[to.ff]) {
					qu.push(to.ff);
					in_queue[to.ff] = true;
				}
			}
		}
	}

	if (dist[t] == INFL) {
		return {0, 0};
	}

	int f = INF;
	ll cost = 0;
	int cur = t;
	while (cur != s) {
		f = min(f, edges[from[cur].ss].c - edges[from[cur].ss].f);
		cur = from[cur].ff;
	}

	cur = t;
	while (cur != s) {
		edges[from[cur].ss].f += f;
		edges[from[cur].ss ^ 1].f -= f;
		cost += (ll) f * edges[from[cur].ss].cost;
		cur = from[cur].ff;
	}
	return {f, cost};
}

void solve() {
	int n, x, y;
	cin >> n >> x >> y;
	--x; --y;
	vector<int> cost;
	for (int i = 0; i < n; ++i) {
		int num;
		cin >> num;
		cost.push_back(num);
	}

	vector<vector<int>> graph1(n), graph2(n);

	for (int i = 0; i < n - 1; ++i) {
		int a, b;
		cin >> a >> b;
		--a; --b;
		graph1[a].push_back(b);
		graph1[b].push_back(a);
	}

	for (int i = 0; i < n - 1; ++i) {
		int a, b;
		cin >> a >> b;
		--a; --b;
		graph2[a].push_back(b);
		graph2[b].push_back(a);
	}

	int q1, q2;
	vector<int> here1(n, -1), here2(n, -1);
	cin >> q1;
	for (int i = 0; i < q1; ++i) {
		int v, q;
		cin >> v >> q;
		--v;
		here1[v] = q;
	}

	cin >> q2;
	for (int i = 0; i < q2; ++i) {
		int v, q;
		cin >> v >> q;
		--v;
		here2[v] = q;
	}

	if (here1[x] != here2[y]) {
		cout << "-1\n";
		return;
	}

	vector<pair<vector<int>, int>> groups;

	vector<int> visited;
	int sum = 0;

	function<void(int, int, vector<vector<int>> const&, vector<int> const&)> dfs0 = [&](int v, int p, vector<vector<int>> const& g, vector<int> const& here) {
		// cerr << v << " " << p << endl;
		visited.push_back(v);
		for (int to : g[v]) {
			if (to != p) {
				if (here[to] == -1) {
					dfs0(to, v, g, here);
				} else {
					sum += here[to];
				}
			}
		}
	};

	function<void(int, int, vector<vector<int>> const&, vector<int> const&)> dfs = [&](int v, int p, vector<vector<int>> const& g, vector<int> const& here) {
		if (here[v] != -1) {
			visited.clear();
			sum = 0;
			dfs0(v, p, g, here);
			if (sum > here[v]) {
				cout << "-1\n";
				exit(0);
			}
			groups.push_back({visited, here[v] - sum});
		}
		for (int to : g[v]) {
			if (to != p) {
				dfs(to, v, g, here);
			}
		}
	};

	int s = add_node();
	int t = add_node();

	vector<pii> node_nodes;
	for (int i = 0; i < n; ++i) {
		node_nodes.push_back({add_node(), add_node()});
		add_edge(node_nodes.back().ff, node_nodes.back().ss, 1, -cost[i]);
	}

	dfs(x, x, graph1, here1);
	for (auto& p : groups) {
		// cerr << "sum = " << p.ss << endl;
		// for (int v : p.ff) {
		// 	cerr << v + 1 << " ";
		// }
		// cerr << endl;
		int tmp = add_node();
		add_edge(s, tmp, p.ss, 0);
		for (int v : p.ff) {
			add_edge(tmp, node_nodes[v].ff, 1, 0);
		}
	}

	groups.clear();
	dfs(y, y, graph2, here2);
	for (auto& p : groups) {
		// cerr << "sum = " << p.ss << endl;
		// for (int v : p.ff) {
		// 	cerr << v + 1 << " ";
		// }
		// cerr << endl;
		int tmp = add_node();
		add_edge(tmp, t, p.ss, 0);
		for (int v : p.ff) {
			add_edge(node_nodes[v].ss, tmp, 1, 0);
		}
	}

	ll ans = 0;
	int f = 0;

	dist = vector<ll>(szof(graph));
	in_queue = vector<bool>(szof(graph));
	from = vector<pii>(szof(graph));

	while (true) {
		auto tmp = push_flow(s, t);
		if (!tmp.ff) {
			break;
		}
		f += tmp.ff;
		ans += tmp.ss;
	}

	// cerr << f << endl;

	if (f != here1[x] || f != here2[y]) {
		cout << "-1\n";
		return;
	}

	cout << -ans << "\n";
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
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

struct edge {
	int f, c;
	edge() : f(0), c(0) {}
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

vector<int> qu;
vector<int> vcnt;
vector<int> dist;

int build_layers(int s, int t) {
	int l = 0, r = 0;
	qu[r++] = s;
	fill(dist.begin(), dist.end(), INF);
	dist[s] = 0;
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
		auto& to = graph[v][vcnt[v]];
		if (edges[to.ss].f < edges[to.ss].c && dist[to.ff] == dist[v] + 1) {
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
	int n;
	cin >> n;
	map<int, vector<pii>> by_x, by_y;
	vector<pii> coords;
	for (int i = 0; i < n; ++i) {
		int x, y;
		cin >> x >> y;
		coords.push_back({x, y});
		// all.push_back({x, y});
		by_x[x].push_back({y, i});
		by_y[y].push_back({x, i});
	}

	vector<pii> hor_segs, ver_segs;

	for (auto& p : by_x) {
		sort(p.ss.begin(), p.ss.end());

		for (int i = 0; i < szof(p.ss) - 1; ++i) {
			ver_segs.push_back({p.ss[i].ss, p.ss[i + 1].ss});
		}
	}

	for (auto& p : by_y) {
		sort(p.ss.begin(), p.ss.end());

		for (int i = 0; i < szof(p.ss) - 1; ++i) {
			hor_segs.push_back({p.ss[i].ss, p.ss[i + 1].ss});
		}
	}

	int s = add_node();
	int t = add_node();
	vector<int> left_nodes, right_nodes;
	for (int i = 0; i < szof(ver_segs); ++i) {
		left_nodes.push_back(add_node());
		add_edge(s, left_nodes.back(), 1);
	}

	for (int i = 0; i < szof(hor_segs); ++i) {
		right_nodes.push_back(add_node());
		add_edge(right_nodes.back(), t, 1);
	}

	for (int i = 0; i < szof(ver_segs); ++i) {
		for (int j = 0; j < szof(hor_segs); ++j) {
			int a, b, c, d;
			tie(a, b) = ver_segs[i];
			tie(c, d) = hor_segs[j];
			if (coords[c].ff < coords[a].ff && coords[a].ff < coords[d].ff && 
				coords[a].ss < coords[c].ss && coords[c].ss < coords[b].ss) {
				add_edge(left_nodes[i], right_nodes[j], 1);
			}
		}
	}

	int f = 0;

	qu = dist = vcnt = vector<int>(szof(graph));

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

	queue<int> qu;
	vector<bool> used(szof(graph));

	for (pii to : graph[s]) {
		if (!edges[to.ss].f) {
			qu.push(to.ff);
			used[to.ff] = true;
		}
	}

	while (szof(qu)) {
		int v = qu.front();
		qu.pop();

		for (pii to : graph[v]) {
			if (to.ff != s && to.ff != t && edges[to.ss].f < edges[to.ss].c) {
				if (!used[to.ff]) {
					used[to.ff] = true;
					qu.push(to.ff);
				}
			}
		}
	}

	set<pii> take_ver, take_hor;

	for (int i = 2; i < szof(graph); ++i) {
		if (i < 2 + szof(left_nodes)) {
			if (used[i]) {
				take_ver.insert(ver_segs[i - 2]);
			}
		} else {
			if (!used[i]) {
				take_hor.insert(hor_segs[i - 2 - szof(left_nodes)]);
			}
		}
	}

	vector<pair<pii, pii>> ans;

	for (auto& p : by_y) {
		pii from = {p.ss.front().ff, p.ff};
		for (int i = 0; i < szof(p.ss) - 1; ++i) {
			if (!take_hor.count({p.ss[i].ss, p.ss[i + 1].ss})) {
				ans.push_back({from, {p.ss[i].ff, p.ff}});
				from = {p.ss[i + 1].ff, p.ff};
			}
		}
		ans.push_back({from, {p.ss.back().ff, p.ff}});
	}

	cout << szof(ans) << "\n";
	for (auto p : ans) {
		cout << p.ff.ff << " " << p.ff.ss << " " << p.ss.ff << " " << p.ss.ss << "\n";
	}

	ans = {};

	for (auto& p : by_x) {
		pii from = {p.ff, p.ss.front().ff};
		for (int i = 0; i < szof(p.ss) - 1; ++i) {
			if (!take_ver.count({p.ss[i].ss, p.ss[i + 1].ss})) {
				ans.push_back({from, {p.ff, p.ss[i].ff}});
				from = {p.ff, p.ss[i + 1].ff};
			}
		}
		ans.push_back({from, {p.ff, p.ss.back().ff}});
	}

	cout << szof(ans) << "\n";
	for (auto p : ans) {
		cout << p.ff.ff << " " << p.ff.ss << " " << p.ss.ff << " " << p.ss.ss << "\n";
	}
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
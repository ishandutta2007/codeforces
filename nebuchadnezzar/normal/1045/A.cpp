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
	while (l < r) {
		int v = qu[l++];
		for (auto to : graph[v]) {
			if (edges[to.ss].f < edges[to.ss].c && dist[to.ff] > dist[v] + 1) {
				dist[to.ff] = dist[v] + 1;
				qu[r++] = to.ff;
			}
		}
	}
	return dist[t] == INF ? 0 : 1;
}

int push_flow(int v, int t) {
	if (v == t) {
		return 1;
	}
	while (vcnt[v] < szof(graph[v])) {
		auto& to = graph[v][vcnt[v]];
		if (edges[to.ss].f < edges[to.ss].c && dist[to.ff] == dist[v] + 1) {
			int tmp = push_flow(to.ff, t);
			if (tmp) {
				edges[to.ss].f += 1;
				edges[to.ss ^ 1].f -= 1;
				return tmp;
			}
		}
		++vcnt[v];
	}
	return 0;
}

void solve() {
	int n, m;
	cin >> n >> m;
	int s = add_node();
	int t = add_node();
	vector<int> aims;
	map<int, int> aim_ind;
	for (int i = 0; i < m; ++i) {
		aims.push_back(add_node());
		aim_ind[aims[i]] = i;
		add_edge(aims[i], t, 1);
	}
	int bpv = 1;
	while (bpv < m) {
		bpv *= 2;
	}
	vector<int> segtree(bpv * 2, -1);
	for (int i = 0; i < m; ++i) {
		segtree[bpv + i] = aims[i];
	}
	for (int i = bpv - 1; i; --i) {
		if (segtree[i * 2] == -1 && segtree[i * 2 + 1] == -1) {
			segtree[i] = -1;
		} else if (segtree[i * 2] == -1 || segtree[i * 2 + 1] == -1) {
			segtree[i] = max(segtree[i * 2], segtree[i * 2 + 1]);
		} else {
			int v = add_node();
			segtree[i] = v;
			add_edge(v, segtree[i * 2], INF);
			add_edge(v, segtree[i * 2 + 1], INF);
		}
	}
	map<int, int> gun_ind;
	vector<int> arrt;
	vector<vector<int>> inp;
	for (int i = 0; i < n; ++i) {
		int ty;
		cin >> ty;
		arrt.push_back(ty);
		inp.push_back({});
		int tmp = add_node();
		add_edge(s, tmp, ty == 2 ? 2 : 1);
		gun_ind[tmp] = i;
		
		if (ty == 0) {
			int k;
			cin >> k;
			for (int j = 0; j < k; ++j) {
				int ind;
				cin >> ind;
				--ind;
				add_edge(tmp, aims[ind], 1);
			}
		} else if (ty == 1) {
			int l, r;
			cin >> l >> r;
			--l;
			l += bpv; r += bpv;
			while (l < r) {
				if (l & 1) {
					add_edge(tmp, segtree[l++], 1);
				}
				if (r & 1) {
					add_edge(tmp, segtree[--r], 1);
				}
				l /= 2; r /= 2;
			}
		} else {
			int a, b, c;
			cin >> a >> b >> c;
			--a; --b; --c;
			inp.back() = {a, b, c};
			add_edge(tmp, aims[a], 1);
			add_edge(tmp, aims[b], 1);
			add_edge(tmp, aims[c], 1);
		}
	}

	qu = dist = vcnt = vector<int>(szof(graph));

	int cnt = 0;
	while (build_layers(s, t)) {
		fill(vcnt.begin(), vcnt.end(), 0);
		while (push_flow(s, t)) {
			++cnt;
		}
	}

	map<int, set<int>> ans;
	vector<int> where(m, -1);

	vector<int> path;
	function<void(int, int)> find_path = [&](int v, int t) {
		path.push_back(v);
		if (v == t) {
			return;
		}
		while (edges[graph[v][vcnt[v]].ss].f <= 0) {
			++vcnt[v];
		}
		auto& to = graph[v][vcnt[v]];
		edges[to.ss].f--;
		find_path(to.ff, t);
	};

	fill(vcnt.begin(), vcnt.end(), 0);

	for (int i = 0; i < cnt; ++i) {
		path.clear();
		find_path(s, t);
		// for (int q : path) {
		// 	cerr << q << " ";
		// }
		// cerr << endl;
		int g = gun_ind[path[1]];
		int a = aim_ind[path[szof(path) - 2]];
		ans[g].insert(a);
		where[a] = g;
	}

	for (int i = 0; i < n; ++i) {
		if (arrt[i] == 2 && szof(ans[i]) == 1) {
			for (int v : inp[i]) {
				if (where[v] == -1) {
					ans[i].insert(v);
					where[v] = i;
					break;
				}
				if (where[v] != i) {
					ans[where[v]].erase(v);
					ans[i].insert(v);
					where[v] = i;
					break;
				}
			}
			assert(szof(ans[i]) == 2);
		}
	}

	cout << cnt << "\n";

	for (auto& p : ans) {
		for (int x : p.ss) {
			cout << p.ff + 1 << " " << x + 1 << "\n";
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
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
typedef pair<ll, ll> pll;
const int INF = 1e9 + 7;
const ll INFL = 1e18 + 123;
const double PI = atan2(0, -1);
mt19937 tw(960172);
ll rnd(ll x, ll y) { static uniform_int_distribution<ll> d; return d(tw) % (y - x + 1) + x; }

ll idiv(ll a, ll b) {
	ll ret = a / b;
	if (a < 0 && a % b != 0) {
		--ret;
	}
	return ret;
}

void solve() {
	int n, m;
	cin >> n >> m;
	vector<vector<pair<int, pii>>> graph(n);
	for (int i = 0; i < n - 1; ++i) {
		int u, v, a, b;
		cin >> u >> v >> a >> b;
		--u; --v;
		graph[u].push_back({v, {a, b}});
		graph[v].push_back({u, {a, b}});
	}

	vector<pair<pii, pii>> new_edges;
	int cnt = n;
	function<void(int, int)> dfs1 = [&](int v, int p) {
		vector<int> arr;
		for (int i = 0; i < szof(graph[v]); ++i) {
			if (graph[v][i].ff != p) {
				arr.push_back(i);
				dfs1(graph[v][i].ff, v);
			}
		}

		int prev = v;
		for (int i = 0; i < szof(arr); ++i) {
			auto& to = graph[v][arr[i]];
			new_edges.push_back({{prev, to.ff}, to.ss});
			if (i < szof(arr) - 2) {
				new_edges.push_back({{prev, cnt}, {0, 0}});
				prev = cnt++;
			}
		}
	};

	dfs1(0, 0);

	graph = vector<vector<pair<int, pii>>>(cnt);
	for (auto& e : new_edges) {
		graph[e.ff.ff].push_back({e.ff.ss, e.ss});
		graph[e.ff.ss].push_back({e.ff.ff, e.ss});
	}

	vector<bool> used(cnt);
	vector<int> sz(cnt);
	vector<int> parent(cnt);
	vector<int> visited;

	function<void(int, int)> calc_sizes = [&](int v, int p) {
		visited.push_back(v);
		sz[v] = 1;
		for (auto& to : graph[v]) {
			if (!used[to.ff] && to.ff != p) {
				parent[to.ff] = v;
				calc_sizes(to.ff, v);
				sz[v] += sz[to.ff];
			}
		}
	};

	vector<pll> polyline;

	function<void(int, int, pll)> dfs2 = [&](int v, int p, pll path) {
		bool go = false;
		for (auto& to : graph[v]) {
			if (!used[to.ff] && to.ff != p) {
				go = true;
				dfs2(to.ff, v, {path.ff + to.ss.ff, path.ss + to.ss.ss});
			}
		}
		if (!go) {
			polyline.push_back(path);
		}
	};

	function<void(vector<pll>&)> build_convex = [&](vector<pll>& arr) {
		sort(arr.begin(), arr.end());
		vector<pll> res;
		pll prev = arr.front();
		for (auto p : arr) {
			if (prev.ff != p.ff) {
				res.push_back(prev);
			}
			prev = p;
		}
		res.push_back(arr.back());
		swap(res, arr);
		res.clear();
		for (auto p : arr) {
			// cerr << "bc " << p.ff << " " << p.ss << endl;
			while (szof(res) >= 2) {
				auto& plast = res[szof(res) - 2];
				auto& last = res.back();
				ll x1 = idiv((plast.ss - last.ss), (last.ff - plast.ff));
				ll x2 = idiv((last.ss - p.ss), (p.ff - last.ff));
				// cerr << x1 << " " << x2 << endl;
				if (x1 >= x2) {
					// cerr << "pop" << endl;
					res.pop_back();
				} else {
					break;
				}
			}
			// cerr << "push" << endl;
			res.push_back(p);
		}
		swap(res, arr);
	};

	vector<pll> all = {{0, 0}};
	function<void(int)> rec = [&](int v) {
		// cerr << "rec " << v << endl;
		visited.clear();
		calc_sizes(v, -1);
		if (szof(visited) == 1) {
			return;
		}
		int best = INF;
		for (int u : visited) {
			if (parent[u] == -1) {
				continue;
			}
			int cur = max(sz[u], szof(visited) - sz[u]);
			if (cur < best) {
				best = cur;
				v = u;
			}
		}

		int par = parent[v];

		// cerr << "edge " << v << " " << par << endl;

		pll e = {0, 0};
		for (auto& to : graph[v]) {
			if (to.ff == par) {
				e = to.ss;
				break;
			}
		}
		polyline.clear();
		dfs2(v, par, e);

		build_convex(polyline);
		// for (auto& qwe : polyline) {
		// 	cerr << qwe.ff << " " << qwe.ss << endl;
		// }
		// cerr << "---" << endl;
		vector<pll> tmp;
		swap(tmp, polyline);
		dfs2(par, v, {0, 0});
		build_convex(polyline);
		// for (auto& qwe : polyline) {
		// 	cerr << qwe.ff << " " << qwe.ss << endl;
		// }
		int c1 = 0, c2 = 0;
		while (c1 < szof(tmp) - 1 && c2 < szof(polyline) - 1) {
			ll x1 = idiv((tmp[c1].ss - tmp[c1 + 1].ss), (tmp[c1 + 1].ff - tmp[c1].ff));
			ll x2 = idiv((polyline[c2].ss - polyline[c2 + 1].ss), (polyline[c2 + 1].ff - polyline[c2].ff));
			all.push_back({tmp[c1].ff + polyline[c2].ff, tmp[c1].ss + polyline[c2].ss});
			if (x1 < x2) {
				++c1;
			} else {
				++c2;
			}
		}

		while (c1 < szof(tmp) - 1) {
			all.push_back({tmp[c1].ff + polyline[c2].ff, tmp[c1].ss + polyline[c2].ss});
			++c1;
		}
		while (c2 < szof(polyline) - 1) {
			all.push_back({tmp[c1].ff + polyline[c2].ff, tmp[c1].ss + polyline[c2].ss});
			++c2;
		}

		all.push_back({tmp[c1].ff + polyline[c2].ff, tmp[c1].ss + polyline[c2].ss});

		used[v] = true;
		rec(par);
		used[par] = true;
		used[v] = false;
		rec(v);
		used[par] = false;
	};

	rec(0);
	// for (pll p : all) {
	// 	cerr << p.ff << " " << p.ss << endl;
	// }
	// cerr << "---" << endl;
	build_convex(all);
	// for (pll p : all) {
	// 	cerr << p.ff << " " << p.ss << endl;
	// }
	int c = 0;
	for (int i = 0; i < m; ++i) {
		while (c < szof(all) - 1 && all[c].ff * i + all[c].ss < all[c + 1].ff * i + all[c + 1].ss) {
			++c;
		}
		cout << all[c].ff * i + all[c].ss << " ";
	}
	cout << "\n";
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
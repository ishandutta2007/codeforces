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

// COPYPASTED FROM E-MAXX
namespace general_matching {
const int MAXN = 1005;
int n;
vector<int> g[MAXN];
int match[MAXN], p[MAXN], base[MAXN], q[MAXN];
bool used[MAXN], blossom[MAXN];

int lca(int a, int b) {
	bool used[MAXN] = {0};
	for (;;) {
		a = base[a];
		used[a] = true;
		if (match[a] == -1)
			break;
		a = p[match[a]];
	}
	for (;;) {
		b = base[b];
		if (used[b])
			return b;
		b = p[match[b]];
	}
}

void mark_path(int v, int b, int children) {
	while (base[v] != b) {
		blossom[base[v]] = blossom[base[match[v]]] = true;
		p[v] = children;
		children = match[v];
		v = p[match[v]];
	}
}

int find_path(int root) {
	memset(used, 0, sizeof used);
	memset(p, -1, sizeof p);
	for (int i = 0; i < n; ++i)
		base[i] = i;

	used[root] = true;
	int qh = 0, qt = 0;
	q[qt++] = root;
	while (qh < qt) {
		int v = q[qh++];
		for (size_t i = 0; i < g[v].size(); ++i) {
			int to = g[v][i];
			if (base[v] == base[to] || match[v] == to)
				continue;
			if (to == root || (match[to] != -1 && p[match[to]] != -1)) {
				int curbase = lca(v, to);
				memset(blossom, 0, sizeof blossom);
				mark_path(v, curbase, to);
				mark_path(to, curbase, v);
				for (int i = 0; i < n; ++i)
					if (blossom[base[i]]) {
						base[i] = curbase;
						if (!used[i]) {
							used[i] = true;
							q[qt++] = i;
						}
					}
			} else if (p[to] == -1) {
				p[to] = v;
				if (match[to] == -1)
					return to;
				to = match[to];
				used[to] = true;
				q[qt++] = to;
			}
		}
	}
	return -1;
}

vector<pair<int, int>> solve(int _n, vector<pair<int, int>> edges) {
	n = _n;
	for (int i = 0; i < n; i++)
		g[i].clear();
	for (auto o : edges) {
		g[o.first].push_back(o.second);
		g[o.second].push_back(o.first);
	}
	memset(match, -1, sizeof match);
	for (int i = 0; i < n; ++i) {
		if (match[i] == -1) {
			int v = find_path(i);
			while (v != -1) {
				int pv = p[v], ppv = match[pv];
				match[v] = pv, match[pv] = v;
				v = ppv;
			}
		}
	}
	vector<pair<int, int>> ans;
	for (int i = 0; i < n; i++) {
		if (match[i] > i) {
			ans.push_back(make_pair(i, match[i]));
		}
	}
	return ans;
}
} // namespace general_matching


const int MOD = 998244353;

int mult(int a, int b) {
	return (ll) a * b % MOD;
}

int mpow(int a, int b) {
	int ret = 1;
	while (b) {
		if (b & 1) {
			ret = mult(ret, a);
		}
		a = mult(a, a);
		b /= 2;
	}
	return ret;
}


void solve() {
	int n;
	cin >> n;
	vector<vector<int>> inp;
	for (int i = 0; i < n * 2; ++i) {
		vector<int> cur;
		for (int j = 0; j < n; ++j) {
			int num;
			cin >> num;
			--num;
			cur.push_back(num);
		}

		inp.push_back(cur);
	}

	vector<pii> edges;
	for (int i = 0; i < n * 2; ++i) {
		for (int j = i + 1; j < n * 2; ++j) {
			bool fl = false;
			for (int k = 0; k < n; ++k) {
				if (inp[i][k] == inp[j][k]) {
					fl = true;
					break;
				}
			}
			if (fl) {
				edges.push_back({i, j});
			}
		}
	}

	auto matching = general_matching::solve(n * 2, edges);
	// cerr << szof(matching) << endl;
	assert(szof(matching) == n);

	vector<pii> node_color(n * 2);
	for (int i = 0; i < n; ++i) {
		auto [a, b] = matching[i];
		node_color[a] = {i, 0};
		node_color[b] = {i, 1};
	}

	vector<vector<int>> graph(n * 2);
	for (auto e : edges) {
		auto [a, b] = e;
		if (node_color[a].ff != node_color[b].ff) {
			graph[node_color[a].ff * 2 + node_color[a].ss].push_back(node_color[b].ff * 2 + (node_color[b].ss ^ 1));
			graph[node_color[b].ff * 2 + node_color[b].ss].push_back(node_color[a].ff * 2 + (node_color[a].ss ^ 1));
		}
	}

	vector<bool> used(n * 2);

	function<void(int, vector<vector<int>> const&, vector<int>&)> dfs = [&](int v, vector<vector<int>> const& g, vector<int>& arr) {
		used[v] = true;
		for (int to : g[v]) {
			if (!used[to]) {
				dfs(to, g, arr);
			}
		}
		arr.push_back(v);
	};

	vector<int> order;
	for (int i = 0; i < n * 2; ++i) {
		if (!used[i]) {
			dfs(i, graph, order);
		}
	}

	vector<vector<int>> rgraph(n * 2);
	for (int i = 0; i < n * 2; ++i) {
		for (int to : graph[i]) {
			rgraph[to].push_back(i);
		}
	}

	reverse(order.begin(), order.end());
	fill(used.begin(), used.end(), 0);
	vector<int> color(n * 2);
	int cnt = 0;
	for (int v : order) {
		if (!used[v]) {
			vector<int> cur;
			dfs(v, rgraph, cur);
			for (int u : cur) {
				color[u] = cnt;
			}
			++cnt;
		}
	}

	for (int i = 0; i < n; ++i) {
		assert(color[i * 2] != color[i * 2 + 1]);
		if (color[i * 2] < color[i * 2 + 1]) {
			swap(matching[i].ff, matching[i].ss);
		}
	}

	vector<vector<int>> who(n, vector<int>(n));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			who[j][inp[matching[i].ff][j]] = i;
		}
	}

	int comp = 0;
	vector<bool> skip(n);
	for (int i = 0; i < n; ++i) {
		if (skip[i]) {
			continue;
		}
		vector<bool> used(n);
		vector<vector<int>> cnt(n, vector<int>(n));
		queue<int> qu;
		
		qu.push(i);
		used[i] = true;
		bool fail = false;
		while (szof(qu)) {
			int v = qu.front();
			qu.pop();
			for (int j = 0; j < n; ++j) {
				cnt[j][inp[matching[v].ss][j]]++;
				if (cnt[j][inp[matching[v].ss][j]] >= 2) {
					fail = true;
					break;
				}
				int to = who[j][inp[matching[v].ss][j]];
				if (!used[to]) {
					used[to] = true;
					qu.push(to);
				}
			}

			if (fail) {
				break;
			}
		}

		if (!fail) {
			++comp;
			for (int j = 0; j < n; ++j) {
				if (used[j]) {
					skip[j] = true;
				}
			}
		}
	}

	cout << mpow(2, comp) << "\n";

	for (int i = 0; i < n; ++i) {
		cout << matching[i].ff + 1 << " ";
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
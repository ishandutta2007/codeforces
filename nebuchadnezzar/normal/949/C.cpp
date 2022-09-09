#include "bits/stdc++.h"
#define ff first
#define ss second
#define szof(_x) ((int) (_x).size())
#define TASK_NAME ""

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef unsigned long long ull;
const int INF = 1e9 + 7;
const ll INFL = 1e18 + 123;
const double PI = atan2(0, -1);
mt19937 tw(960172);
ll rnd(ll x, ll y) { static uniform_int_distribution<ll> d; return d(tw) % (y - x + 1) + x; }

const int MAXN = 1e5 + 5;
vector<vector<int>> graph, rgraph;
bool used[MAXN];
ull mask[MAXN];
int sz[MAXN];

int dfs0(int v, vector<vector<int>> const& g, vector<int>& arr) {
	used[v] = true;
	//cerr << v << endl;
	for (int to : g[v]) {
		if (!used[to]) {
			dfs0(to, g, arr);
		}
	}
	arr.push_back(v);
	return 0;
}

int dfs(int v, int from) {
	used[v] = 1;
	mask[v] = 0;
	if (from <= v && v < from + 64) {
		mask[v] |= 1 << (v - from);
	}
	for (int to : graph[v]) {
		if (!used[to]) {
			dfs(to, from);
		}
		mask[v] |= mask[to];
	}
	return 0;
}

vector<int> ans;

int dfs2(int v) {
	used[v] = true;
	ans.push_back(v);
	for (int to : graph[v]) {
		if (!used[to]) {
			dfs2(to);
		}
	}
	return 0;
}

const int SZ = 1 << 22;
int arr[SZ];

inline int getb(ull num) {
	return arr[num & (SZ - 1)] + arr[(num >> 22) & (SZ - 1)] + arr[(num >> 44) & (SZ - 1)];
}

void solve() {
	for (int i = 0; i < SZ; ++i) {
		arr[i] = arr[i >> 1] + (i & 1);
	}
	int n, m, h;
	cin >> n >> m >> h;
	vector<int> times;
	for (int i = 0; i < n; ++i) {
		int num;
		cin >> num;
		times.push_back(num);
	}
	//vector<pii> edges;
	graph = vector<vector<int>>(n);
	rgraph = vector<vector<int>>(n);
	vector<pii> edges;
	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		--a; --b;
		if ((times[a] + 1) % h == times[b]) {
			graph[a].push_back(b);
			rgraph[b].push_back(a);
			//cerr << a << " " << b << endl;
			edges.push_back({a, b});
		}
		if ((times[b] + 1) % h == times[a]) {
			graph[b].push_back(a);
			rgraph[a].push_back(b);
			//cerr << b << " " << a << endl;
			edges.push_back({b, a});
		}
	}

	vector<int> order;
	for (int i = 0; i < n; ++i) {
		if (!used[i]) {
			dfs0(i, graph, order);
		}
	}

	reverse(order.begin(), order.end());

	vector<int> color(n);
	vector<vector<int>> of_color;
	int c = 0;
	fill(used, used + n, 0);
	for (int i : order) {
		if (!used[i]) {
			vector<int> now;
			dfs0(i, rgraph, now);
			for (int v : now) {
				color[v] = c;
			}
			of_color.push_back(now);
			++c;
		}
	}
	auto memgraph = graph;
	graph = vector<vector<int>>(c);
	for (pii e : edges) {
		if (color[e.ff] != color[e.ss]) {
			graph[color[e.ff]].push_back(color[e.ss]);
		}
	}

	for (int i = 0; i < c; ++i) {
		sort(graph[i].begin(), graph[i].end());
		graph[i].erase(unique(graph[i].begin(), graph[i].end()), graph[i].end());
	}



	//cerr << "here" << endl;

	/*
	graph = vector<vector<int>>(c);
	for (pii e : edges) {
		if (color[e.ff] != color[e.ss]) {
			graph[color[e.ff]].push_back();
		}
	}
	*/
	//cerr << c << endl;
	/*
	vector<ull> mask_of_color(c);
	reverse(order.begin(), order.end());
	for (int i = 0; i < n; i += 64) {
		fill(mask_of_color.begin(), mask_of_color.end(), 0);
		for (int j = i; j < i + 64 && j < n; ++j) {
			mask_of_color[color[j]] |= 1ull << (j - i);
		}
		for (int j = c - 1; j >= 0; --j) {
			for (int to : graph[j]) {
				mask_of_color[j] |= mask_of_color[to];
			}
			sz[j] += getb(mask_of_color[j]);
		}
	}*/
	int best = INF;
	int mem = -1;
	for (int i = 0; i < c; ++i) {
		//cerr << sz[i] << " ";
		if (szof(graph[i])) {
			continue;
		}
		if (best > szof(of_color[i])) {
			best = szof(of_color[i]);
			mem = i;
		}
	}

	mem = of_color[mem].front();
	//cerr << endl;

	fill(used, used + n, 0);
	graph = memgraph;
	dfs2(mem);
	cout << szof(ans) << "\n";
	for (int v : ans) {
		cout << v + 1 << " ";
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
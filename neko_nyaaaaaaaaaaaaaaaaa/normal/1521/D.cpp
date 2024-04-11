#include<bits/stdc++.h>
using namespace std;

struct Edge {
	int u, v;	// directed
	int capacity;
	int flow;
};

struct Flow {
	int n;
	int source, sink;

	vector<vector<int>> a;
	vector<Edge> E;

	vector<int> cur;
	vector<int> dist;

	Flow();
	Flow(int n, int s, int t) {
		this->n = n;
		source = s; sink = t;
		a.resize(n+1);
		cur.resize(n+1);
		dist.resize(n+1);
	}

	void add_edge(int u, int v, int c) {
		a[u].push_back(E.size());	E.push_back({u, v, c, 0});
		a[v].push_back(E.size());	E.push_back({v, u, 0, 0});
	}

	int bfs() {
		fill(dist.begin(), dist.end(), -1);

		queue<int> Q;
		Q.push(source); dist[source] = 0;

		while (!Q.empty()) {
			int u = Q.front(); Q.pop();

			for (int i = 0; i < a[u].size(); i++) {
				int id = a[u][i];
				int v = E[id].v;

				if (dist[v] < 0 && E[id].flow < E[id].capacity) {
					dist[v] = dist[u] + 1;
					Q.push(v);
				}
			}
		}

		return dist[sink] >= 0;
	}

	int dfs(int now, int flow) {
		if (flow == 0) return 0;
		if (now == sink) return flow;

		for (; cur[now] < a[now].size(); cur[now]++) {
			int id = a[now][cur[now]];
			int v = E[id].v;

			if (dist[v] == dist[now] + 1) {
				int delta = dfs(v, min(flow, E[id].capacity - E[id].flow));
				if (delta) {
					E[id].flow += delta;
					E[id^1].flow -= delta;

					return delta;
				}
			}
		}

		return 0;
	}

	pair<int, vector<Edge>> maxflow() {
		int ans = 0;
		while (bfs()) {
			fill(cur.begin(), cur.end(), 0);
			while (1) {
				int delta = dfs(source, 1e9);
				if (!delta) break;

				ans += delta;
			}
		}

		vector<Edge> network;   // list of edges in flow network
		for (Edge e: E) {
			if (e.flow > 0) {
				network.push_back(e);
			}
		}

		return make_pair(ans, network);
	}
};

struct DSU {
	vector<int> P, S;
	DSU(int n) {
		P.resize(n+1);
		S.resize(n+1, 1);
		for (int i = 1; i <= n; i++) P[i] = i;
	}
	
	int find(int x) {
		if (x == P[x]) return x;
		return P[x] = find(P[x]);
	}
	
	bool merge(int a, int b) {
		a = find(a); b = find(b);
		if (a == b) return 0;
		if (S[a] < S[b]) swap(a, b);
		
		S[a] += S[b];
		P[b] = a;
		return 1;
	}
	
	int same(int a, int b) {
		return find(a) == find(b);
	}
};

void dfs(int now, int prev, int c, vector<vector<int>> &g, vector<int> &col) {
	col[now] = c;
	for (int u: g[now]) {
		if (u != prev) {
			dfs(u, now, 1-c, g, col);
		}
	}
}

void solve() {
	int n; cin >> n;
	vector<vector<int>> g(n+1);

	vector<pair<int, int>> edges;
	for (int i = 1; i < n; i++) {
		int u, v; cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
		edges.emplace_back(u, v);
	}

	vector<int> col(n+1, -1);
	dfs(1, 0, 0, g, col);

	Flow f(n+2, 0, n+1);
	for (int i = 1; i <= n; i++) {
		if (col[i]) f.add_edge(i, n+1, 2);
		else f.add_edge(0, i, 2);
	}
	for (auto &[u, v]: edges) {
		if (col[u] > col[v]) swap(u, v);
		f.add_edge(u, v, 1);
	}

	set<pair<int, int>> deletes;
	for (auto [u, v]: edges) {
		deletes.insert({u, v});
	}
	auto [cnt, nw] = f.maxflow();
	for (Edge e: nw) {
		if (e.u == 0 || e.v == n+1) continue;
		deletes.erase(deletes.find({e.u, e.v}));
	}

	DSU d(n); vector<int> deg(n+1);
	for (auto [u, v]: edges) {
		if (deletes.find({u, v}) == deletes.end()) {
			d.merge(u, v); deg[u]++, deg[v]++;
		}
	}

	map<int, vector<int>> mp;
	for (int i = 1; i <= n; i++) {
		if (deg[i] == 1) {
			mp[d.find(i)].push_back(i);
		} else if (deg[i] == 0) {
			mp[i].push_back(i);
			mp[i].push_back(i);
		}
	}
 
	vector<pair<int, int>> chains;
	for (auto [val, vec]: mp) {
		chains.emplace_back(vec[0], vec[1]);
	}

	vector<pair<int, int>> adds;
	for (int i = 1; i < chains.size(); i++) {
		adds.emplace_back(chains[i-1].first, chains[i].second);
	}
	vector<pair<int, int>> delets(deletes.begin(), deletes.end());

	cout << delets.size() << '\n';
	for (int i = 0; i < delets.size(); i++) {
		cout << delets[i].first << ' ' << delets[i].second << ' ' << adds[i].first << ' ' << adds[i].second << '\n';
	}
}

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int t; cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}
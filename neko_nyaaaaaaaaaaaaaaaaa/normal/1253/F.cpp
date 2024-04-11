#include <bits/stdc++.h>
using namespace std;
 
const int MAXN = 100002;

struct DSU {
	int n, vers;
	vector<pair<int, int>> P[MAXN];
	vector<int> S;

	DSU(int n) {
		this->n = n; vers = 0;
		S.resize(n+1, 1);
		for (int i = 1; i <= n; i++) {
			P[i].emplace_back(vers, i);
		}
	}
	 
	int get_root(int u, int ver) {
		auto [v, par] = *(upper_bound(P[u].begin(), P[u].end(), make_pair(ver+1, 0)) - 1);

		if (par != u) {
			return get_root(par, ver);
		} else {
			return par;
		}
	}
	 
	int merge(int u, int v) {
		u = get_root(u, vers);
		v = get_root(v, vers);

		if (u == v) {
			return 0;
		}

		vers++;
		
		if (S[u] > S[v]) swap(u, v);
		P[u].emplace_back(vers, v);
		S[v] += S[u];

		return vers;
	}

	int same(int u, int v, int ver) {
		u = get_root(u, ver);
		v = get_root(v, ver);
		return u == v;
	}
};

const long long INF = 1e18;
 
int n, m, k, q;
vector<pair<int, int>> adj[MAXN];
vector<tuple<int, int, int>> edge;
vector<long long> dist(MAXN, INF);
vector<int> source(MAXN);
vector<int> start;
 
vector<tuple<long long, int, int>> dijkstra() {
	priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
	vector<int> vis(MAXN);

	for (int u: start) {
		dist[u] = 0;
		source[u] = u;
		pq.push({0, u});
	}

	while (pq.size()) {
		auto tmp = pq.top();
		int now = tmp.second, w = tmp.first;
		pq.pop();

		if (vis[now]) continue;
		vis[now] = 1;
 
		for (auto u: adj[now]) {
			if (!vis[u.first] && dist[now] + u.second < dist[u.first]) {
				dist[u.first] = dist[now] + u.second;
				source[u.first] = source[now];
				pq.push({dist[u.first], u.first});
			}
		}
	}

	vector<tuple<long long, int, int>> ans;
	for (int i = k+1; i <= n; i++) {
		ans.emplace_back(dist[i], i, source[i]);
	}
	for (auto [u, v, w]: edge) {
		if (source[u] != source[v]) ans.emplace_back(dist[u] + dist[v] + w, source[u], source[v]);
	} 
	return ans;
}
 
signed main() {
	ios::sync_with_stdio(0); cin.tie(0);
 
	cin >> n >> m >> k >> q;
	for (int i = 1; i <= k; i++) {
		start.push_back(i);
	}
	for (int i = 0; i < m; i++) {
		int x, y, w;
		cin >> x >> y >> w;
		edge.emplace_back(x, y, w);
		adj[x].push_back({y, w});
		adj[y].push_back({x, w});
	}
	vector<tuple<long long, int, int>> edges = dijkstra();

	sort(edges.begin(), edges.end());
	DSU d(n);

	vector<long long> mst(1);
	for (auto [w, u, v]: edges) {
		if (d.merge(u, v)) {
			mst.push_back(w);
		}
	}

	while (q--) {
		int u, v; cin >> u >> v;
		int lo = 1, hi = n - 1;
		while (lo < hi) {
			int mid = (lo + hi)/2;
			if (d.same(u, v, mid)) {
				hi = mid;
			} else {
				lo = mid + 1;
			}
		}
		cout << mst[lo] << '\n';
	}
 
	return 0;
}
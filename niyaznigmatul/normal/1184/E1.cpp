/**
 * Niyaz Nigmatullin
 */

#include <bits/stdc++.h>

using namespace std;

struct edge {
	int from;
	int to;
	int w;
	int id;
};

int const K = 20;

vector<int> pv;
vector<vector<edge>> te;
vector<int> depth, parent;
vector<vector<int>> pp, me, zz;

int get(int v) {
	return pv[v] == v ? v : (pv[v] = get(pv[v]));
}

int lca(int v, int u) {
	if (depth[v] > depth[u]) {
		std::swap(v, u);
	}
	for (int i = K - 1; i >= 0; i--) {
		if (depth[pp[i][u]] >= depth[v]) {
			u = pp[i][u];
		}
	}
	if (u == v) return u;
	for (int i = K - 1; i >= 0; i--) {
		if (pp[i][u] != pp[i][v]) {
			u = pp[i][u];
			v = pp[i][v];
		}
	}
	return parent[v];
}

void dfs(int v, int pv, int d, int edgeUp) {
	depth[v] = d;
	parent[v] = pv;
	pp[0][v] = pv < 0 ? v : pv;
	me[0][v] = edgeUp;
	for (int i = 1; i < K; i++) {
		pp[i][v] = pp[i - 1][pp[i - 1][v]];
		me[i][v] = max(me[i - 1][v], me[i - 1][pp[i - 1][v]]);
	}
	for (auto &e : te[v]) {
		if (e.to != pv) {
			dfs(e.to, v, d + 1, e.w);
		}
	}
}

void relax(int v, int u, int w) {
	if (v == u) return;
	int dd = depth[v] - depth[u];
	assert(dd >= 0);
	int k = 0;
	while ((1 << (k + 1)) <= dd) k++;
	assert(k < K);
	int to = depth[u] + (1 << k);
	int vv = v;
	for (int i = K - 1; i >= 0; i--) {
		if (depth[pp[i][vv]] >= to) {
			vv = pp[i][vv];
		}
	}
	zz[k][v] = min(zz[k][v], w);
	zz[k][vv] = min(zz[k][vv], w);
}

int const INF = 1 << 30;

int getMax(int v, int u) {
	int ans = -INF;
	for (int i = K - 1; i >= 0; i--) {
		if (depth[pp[i][v]] >= depth[u]) {
			ans = max(ans, me[i][v]);
			v = pp[i][v];
		}
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0);	
	int n, m;
	cin >> n >> m;
	pv.assign(n, 0);
	depth.assign(n, 0);
	parent.assign(n, 0);
	for (int i = 0; i < n; i++) pv[i] = i;
	vector<edge> edges(m);
	te.resize(n);
	vector<int> inTree(m);
	pp.assign(K, vector<int>(n));
	zz.assign(K, vector<int>(n));
	me.assign(K, vector<int>(n));
	for (int i = 0; i < m; i++) {
		int v, u, w;
		cin >> v >> u >> w;
		--v;
		--u;
		edges[i] = {v, u, w, i};
	}
	sort(edges.begin(), edges.end(), [](edge const &e, edge const &f) {
		return e.w < f.w;
	});
	for (int i = 0; i < m; i++) {
		int v = edges[i].from;
		int u = edges[i].to;
		int w = edges[i].w;
		if (get(v) != get(u)) {
			inTree[i] = true;
			te[v].push_back({v, u, w, i});
			te[u].push_back({u, v, w, i});
			pv[get(v)] = get(u);
		}
	}
	dfs(0, -1, 0, -INF);
	for (int i = 0; i < K; i++) {
		for (int j = 0; j < n; j++) {
			zz[i][j] = INF;
		}
	}
	vector<int> answer(m);
	for (int i = 0; i < m; i++) {
		if (inTree[i]) continue;
		int z = lca(edges[i].from, edges[i].to);
		relax(edges[i].from, z, edges[i].w);
		relax(edges[i].to, z, edges[i].w);
		answer[edges[i].id] = max(getMax(edges[i].from, z), getMax(edges[i].to, z));
	}
	for (int i = K - 1; i > 0; i--) {
		for (int v = 0; v < n; v++) {
			zz[i - 1][v] = min(zz[i - 1][v], zz[i][v]);
			zz[i - 1][pp[i - 1][v]] = min(zz[i - 1][pp[i - 1][v]], zz[i][v]);
		}
	}
	for (int i = 0; i < m; i++) {
		if (!inTree[i]) continue;
		// answer[edges[i].id] = INF;
		if (depth[edges[i].from] > depth[edges[i].to]) {
			answer[edges[i].id] = zz[0][edges[i].from];
		} else {
			answer[edges[i].id] = zz[0][edges[i].to];
		}
	}
	cout << min(1000000000, answer[0]) << endl;
	// for (int i : answer) {
	// 	// if (i == INF) continue;
	// 	cout << min(i, 1000000000) << '\n';
	// }
}
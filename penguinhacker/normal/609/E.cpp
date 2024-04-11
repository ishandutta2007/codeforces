#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

struct Edge {
	int u, v, w, ind;
	Edge(int u, int v, int w, int ind) : u(u), v(v), w(w), ind(ind) {}
	bool operator<(const Edge& other) const {return w < other.w;}
};

const int mxN = 200000;
int n, m, dep[mxN], anc[mxN][18], lift[mxN][18];
ll ans[mxN], mst = 0;
vector<pair<int, int>> adj[mxN];

struct DSU {
	int rank[mxN], p[mxN];
	DSU() {
		memset(rank, 0, sizeof(rank));
		iota(p, p+mxN, 0);
	}
	int find(int x) {return x==p[x]?x:p[x]=find(p[x]);}
	bool merge(int a, int b, int c) {
		a=find(a), b=find(b);
		if (a==b) return 0;
		if (rank[a]<rank[b]) swap(a, b);
		if (rank[a]==rank[b]) ++rank[a];
		p[b]=a;
		return 1;
		//cout << a << " " << b << " " << c << "\n";
	}
} dsu;

void dfs(int u = 0, int p = -1) {
	for (int i = 1; i < 18; ++i) {
		anc[u][i] = anc[anc[u][i - 1]][i - 1];
		lift[u][i] = max(lift[u][i - 1], lift[anc[u][i - 1]][i - 1]);
	}
	for (pair<int, int> v : adj[u]) {
		if (v.first != p) {
			dep[v.first] = dep[u] + 1;
			anc[v.first][0] = u;
			lift[v.first][0] = v.second;
			dfs(v.first, u);
		}
	}
}

int lca(int a, int b) {
	if (dep[a] > dep[b]) {
		swap(a, b);
	}
	for (int i = 17; ~i; --i) {
		if (dep[b] - (1 << i) >= dep[a]) {
			b = anc[b][i];
		}
	}
	if (a == b) {
		return a;
	}
	for (int i = 17; ~i; --i) {
		if (anc[a][i] != anc[b][i]) {
			a = anc[a][i];
			b = anc[b][i];
		}
	}
	return anc[a][0];
}

int path(int a, int l) {
	assert(dep[a] >= dep[l]);
	int ret = 0;
	for (int i = 17; ~i; --i) {
		if (dep[a] - (1 << i) >= dep[l]) {
			ret = max(ret, lift[a][i]);
			a = anc[a][i];
		}
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	vector<Edge> edges;
	for (int i = 0; i < m; ++i) {
		int a, b, c;
		cin >> a >> b >> c, --a, --b;
		edges.push_back(Edge(a, b, c, i));
	}
	sort(edges.begin(), edges.end());
	for (Edge& e : edges) {
		//cout << e.u << " " << e.v << " " << e.w << " " << e.ind << "\n";
		if (dsu.merge(e.u, e.v, e.w)) {
			adj[e.u].emplace_back(e.v, e.w);
			adj[e.v].emplace_back(e.u, e.w);
			mst += e.w;
			//cout << e.u << " " << e.v << " " << e.w << "\n";
		}
	}
	//cout << mst << "\n";
	//lift[0][0] = 1e9;
	dfs();
	for (Edge& e : edges) {
		int a = e.u, b = e.v, c = e.w, ind = e.ind;
		int l = lca(a, b);
		ans[ind] = mst + c - max(path(a, l), path(b, l));
	}
	for (int i = 0; i < m; ++i) {
		cout << ans[i] << "\n";
	}
	return 0;
}
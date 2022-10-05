#include <bits/stdc++.h>
#define finish(x) return cout << x << endl, 0
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7;
const ll inf = 4e18;
const int OO = 0;
const int OOO = 1;
using namespace std;

struct edge {
	int to;
	ll w;
	edge() {}
	edge(int tt, ll ww) {
		to = tt;
		w = ww;
	}
	bool operator < (const edge &a) const {
		return w > a.w;
	}
};

struct query {
	int u, v, i;
	query() {}
	query(int uu, int vv, int ii) {
		u = uu;
		v = vv;
		i = ii;
	}
};

int n, q;
vector<vector<edge>> g;
vector<vector<int>> tree;
vector<query> Q;
vector<ll> ans;

vector<int> vis;
vector<int> col;
int nxtcol = 0;

vector<ll> D1, D2;
vector<int> lstvis; int nxtlst = 1;

void dijkstra(int v, vector<ll> &dist) {
	priority_queue<edge> qu;
	qu.push(edge(v, 0));
	while (qu.size()) {
		edge x = qu.top();
		qu.pop();
		if (lstvis[x.to] == nxtlst) continue;
		lstvis[x.to] = nxtlst;
		dist[x.to] = x.w;
		for (const auto &i : g[x.to]) {
			if (lstvis[i.to] != nxtlst && !vis[i.to < n ? i.to : i.to - n]) {
				qu.push(edge(i.to, x.w + i.w));
			}
		}
	}
	nxtlst++;
}

int getsize(int v, int prev) {
	if (vis[v]) return 0;
	int sz = 1;
	for (const auto &i : tree[v])
		if (i != prev)
			sz += getsize(i, v);
	return sz;
}

int centroid(int v, int prev, int total, int &mn, int &node) {
	if (vis[v]) return 0;
	int sz = 1, mx = 1;
	for (const auto &i : tree[v])
		if (i != prev) {
			int tmp = centroid(i, v, total, mn, node);
			mx = max(mx, tmp);
			sz += tmp;
		}
	mx = max(mx, total - sz);
	if (mx < mn) {
		mn = mx;
		node = v;
	}
	return sz;
}

void cdfs(int v, int prev) {
	if (vis[v]) return;
	col[v] = nxtcol;
	for (const auto &i : tree[v])
		if (i != prev)
			cdfs(i, v);
}

void color(int v, int prev) {
	cdfs(v, prev);
	nxtcol++;
}

void work(int v, vector<query> &q) {
	if (vis[v] || !q.size()) return;
	if (OO) {
		cout << "starting work on " << v << '\n';
		cout << "with queries:\n";
		for (const auto &i : q) cout << i.u << " " << i.v << '\n'; cout << '\n';
	}
	int sz = getsize(v, -1);
	int mn = md;
	centroid(v, -1, sz, mn, v);

	if (OO) {
		cout << "centroid " << v << '\n';
	}

	dijkstra(v, D1);
	dijkstra(v + n, D2);
	if (OO) {
		cout << "D1:\n";
		for (const auto &i : D1) cout << i << " "; cout << '\n';
		cout << "D2:\n";
		for (const auto &i : D2) cout << i << " "; cout << '\n';
	}
	for (auto &i : q) {
		if (OO) {
			cout << "optimizing query " << i.u << " " << i.v << " with: ";
			cout << D1[i.u] + D1[i.v] << " " << D2[i.u] + D2[i.v] << '\n';
		}
		ans[i.i] = min(ans[i.i], D1[i.u] + D1[i.v]);
		ans[i.i] = min(ans[i.i], D2[i.u] + D2[i.v]);
	}
	vis[v] = 1;
	nxtcol = 0;
	vector<vector<query>> qs;
	for (const auto &i : tree[v]) {
		if (!vis[i]) {
			qs.push_back(vector<query>());
			color(i, v);
		}
	}
	for (auto &i : q)
		if (i.u % n != v && i.v % n != v && col[i.u % n] == col[i.v % n]) {
			qs[col[i.u % n]].push_back(i);
		}
	for (const auto &i : tree[v])
		if (!vis[i])
			work(i, qs[col[i]]);
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n;
	g.resize(2 * n);
	tree.resize(n);

	vis.resize(n, 0);
	col.resize(n, 0);

	D1.resize(2 * n, 0);
	D2.resize(2 * n, 0);
	lstvis.resize(2 * n, 0);

	for (int i = 0; i < n; i++) {
		ll w;
		cin >> w;
		g[i].push_back(edge(i + n, w));
		g[i + n].push_back(edge(i, w));
	}
	for (int i = 0, u, v; i < n - 1; i++) {
		ll w1, w2;
		cin >> u >> v >> w1 >> w2;
		--u, --v;
		tree[u].push_back(v);
		tree[v].push_back(u);
		g[u].push_back(edge(v, w1));
		g[v].push_back(edge(u, w1));
		g[u + n].push_back(edge(v + n, w2));
		g[v + n].push_back(edge(u + n, w2));
	}
	cin >> q;
	ans.resize(q, inf);
	for (int i = 0, u, v; i < q; i++) {
		cin >> u >> v;
		--u, --v;
		u = u / 2 + n * (u % 2);
		v = v / 2 + n * (v % 2);
		Q.push_back(query(u, v, i));
	}
	work(0, Q);
	for (const auto &i : ans) cout << i << '\n';
}
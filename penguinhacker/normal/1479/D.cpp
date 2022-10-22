#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long

const ull SEED = chrono::steady_clock::now().time_since_epoch().count();
mt19937_64 rng(SEED);

const int mxN = 300000;
int n, q, a[mxN], dep[mxN], anc[mxN][19];
ull val[mxN];
vector<int> adj[mxN];

struct Node {
	ull xum;
	Node* lc;
	Node* rc;
	Node(ull xum, Node* lc, Node* rc) : xum(xum), lc(lc), rc(rc) {}
	Node* edit(int p, int l, int r);
};

Node* null = new Node(0, NULL, NULL);
Node* seg[mxN];

Node* Node::edit(int p, int l, int r) {
	if (p < l || p > r) return this;
	if (l == r) return new Node(xum ^ val[l], null, null);
	int mid = (l + r) / 2;
	Node* ls = lc->edit(p, l, mid);
	Node* rs = rc->edit(p, mid + 1, r);
	return new Node(ls->xum ^ rs->xum, ls, rs);
}

void dfs(int u = 0, int p = -1) {
	for (int i = 1; i < 19; ++i) anc[u][i] = anc[anc[u][i - 1]][i - 1];
	seg[u] = (p == -1 ? null : seg[p])->edit(a[u], 0, n - 1);
	for (int v : adj[u]) if (v != p) {
		dep[v] = dep[u] + 1;
		anc[v][0] = u;
		dfs(v, u);
	}
}

int lca(int u, int v) {
	if (dep[u] > dep[v]) swap(u, v);
	for (int i = 18; ~i; --i) if (dep[v] - (1 << i) >= dep[u]) v = anc[v][i];
	if (u == v) return u;
	for (int i = 18; ~i; --i) if (anc[u][i] != anc[v][i]) u = anc[u][i], v = anc[v][i];
	return anc[u][0];
}

int qry(Node* a, Node* b, int c, int ql, int qr, int l = 0, int r = n - 1) {
	if (r < ql || l > qr) return -1;
	if ((a->xum ^ b->xum ^ (l <= c && c <= r ? val[c] : 0)) == 0) return -1;
	if (l == r) return l + 1;
	int mid = (l + r) / 2;
	int x = qry(a->lc, b->lc, c, ql, qr, l, mid);
	if (x != -1) return x;
	return qry(a->rc, b->rc, c, ql, qr, mid + 1, r);
}

void debug(Node* u, int l = 0, int r = n - 1) {
	cerr << "[" << l << ", " << r << "]: " << u->xum << "\n";
	if (l != r) {
		int mid = (l + r) / 2;
		debug(u->lc, l, mid);
		debug(u->rc, mid + 1, r);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> q;
	for (int i = 0; i < n; ++i) {
		cin >> a[i], --a[i];
		val[i] = rng();
	}
	for (int i = 1; i < n; ++i) {
		int a, b; cin >> a >> b, --a, --b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	null->lc = null->rc = null;
	dfs();
	for (int i = 0; i < q; ++i) {
		int u, v, ql, qr; cin >> u >> v >> ql >> qr, --u, --v, --ql, --qr;
		/*if (i == 0) {
			debug(seg[u]);
			cerr << "\n\n";
			debug(seg[v]);
		}*/
		cout << qry(seg[u], seg[v], a[lca(u, v)], ql, qr) << "\n";
		//if (i == 0) break;
	}
	return 0;
}
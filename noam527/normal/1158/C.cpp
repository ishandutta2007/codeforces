#include <bits/stdc++.h>
#define CHECK cout << "ok" << endl
#define finish(x) return cout << x << endl, 0
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7;
const ll inf = 1e18;
const int OO = 0;
const int OOO = 1;
using namespace std;

int n;
vector<int> a, ans;
vector<int> vis;

struct edge {
	int l, r, t;
	edge() {
		l = r = t = -1;
	}
	edge(int ll, int rr, int tt) {
		l = ll;
		r = rr;
		t = tt;
	}
	bool operator < (const edge &a) const {
		if (l != a.l) return l < a.l;
		return r < a.r;
	}
};

vector<edge> b;
vector<vector<int>> g;

edge merge(const edge &aa, const edge &bb) {
	if (aa.r > bb.r) return aa;
	return bb;
}

struct segtree {
	int n;
	vector<edge> t;
	segtree() {}
	segtree(const vector<edge> &aa, int size) {
		n = max(2, size);
		while (n != (n & -n)) n += (n & -n);
		t.resize(2 * n, edge());
		for (const auto &i : aa)
			t[i.l + n - 1] = i;
		for (int i = n - 2; i >= 0; i--)
			fix(i);
	}
	void init(const vector<edge> &aa, int size) {
		n = max(2, size);
		while (n != (n & -n)) n += (n & -n);
		t.resize(2 * n, edge());
		for (const auto &i : aa)
			t[i.l + n - 1] = i;
		for (int i = n - 2; i >= 0; i--)
			fix(i);
	}
	void clear() {
		t.clear();
	}
	void fix(int i) {
		if (t[2 * i + 1].r > t[2 * i + 2].r) t[i] = t[2 * i + 1];
		else t[i] = t[2 * i + 2];
	}
	void erase(int i) {
		i += n - 1;
		t[i] = edge();
		i = (i - 1) / 2;
		while (i) {
			fix(i);
			i = (i - 1) / 2;
		}
		fix(0);
	}
	edge query(int pos) {
		edge rtn = query(pos, 0, 0, n - 1);
		return rtn;
	}
	edge query(int pos, int node, int nl, int nr) {
		if (pos < nl) return edge();
		if (nr <= pos) return t[node];
		int mid = (nl + nr) / 2;
		return merge(query(pos, 2 * node + 1, nl, mid), query(pos, 2 * node + 2, mid + 1, nr));
	}
};

int nxt;
segtree T;

bool dfs(int v) {
	if (OO) cout << "on " << v << '\n';
	if (OO) cout << vis[v] << '\n';
	if (ans[v] != -1) return true;
	if (vis[v] == 1) return false;
	if (vis[v] == 2) return true;
	vis[v] = 1;
	edge e = T.query(v);
	if (OO) cout << "start " << e.l << " " << e.r << " " << e.t << '\n';
	while (e.r >= v) {
		T.erase(e.l);
		if (OO) cout << "using edge " << e.l << " " << e.r << " " << e.t << '\n';
		if (!dfs(e.t)) return false;
		e = T.query(v);
	}
	for (const auto &i : g[v]) {
		if (OO) cout << "using " << i << '\n';
		if (!dfs(i)) return false;
	}
	if (OO) cout << "finishing " << v << '\n';
	ans[v] = nxt--;
	vis[v] = 2;
	return true;
}

void solve() {
	cin >> n;
	a.resize(n);
	ans.resize(n);
	vis.resize(n);
	nxt = n;
	b.clear();
	T.clear();
	g.clear();
	g.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (a[i] != -1) {
			--a[i];
			if (i + 1 < a[i])
				b.push_back(edge(i + 1, a[i] - 1, i));
			if (a[i] < n)
				g[i].push_back(a[i]);
		}
	}
	if (OO) {
		cout << "b:\n";
		for (const auto &i : b) cout << i.l << " " << i.r << " " << i.t << '\n';
	}
	for (auto &i : ans) i = -1;
	for (auto &i : vis) i = 0;
	T.init(b, n);
	for (int i = 0; i < n; i++)
		if (!dfs(i)) {
			cout << -1 << '\n';
			return;
		}
	if (OO) {
		cout << "my ans:\n";
		for (const auto &i : ans) cout << i << " "; cout << '\n';
	}
	
	for (const auto &i : ans) cout << i << " "; cout << '\n';
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
}
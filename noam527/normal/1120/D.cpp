#include <bits/stdc++.h>
#define finish(x) return cout << x << endl, 0
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7;
const ll inf = 4e18;
const int OO = 0;
const int OOO = 1;
using namespace std;

struct dsu {
	int n;
	vector<int> p, r;
	dsu() {}
	dsu(int sz) {
		n = sz;
		p.resize(n);
		r.resize(n, 0);
		for (int i = 0; i < n; i++) p[i] = i;
	}
	int find(int x) {
		return x == p[x] ? x : p[x] = find(p[x]);
	}
	bool valid(int x, int y) {
		return find(x) != find(y);
	}
	bool unite(int x, int y) {
		x = find(x), y = find(y);
		if (x == y) return false;
		if (r[x] < r[y]) p[x] = y;
		else {
			p[y] = x;
			if (r[x] == r[y]) r[x]++;
		}
		return true;
	}
};

struct edge {
	ll w;
	int u, v, i;
	edge() {}
	edge(ll ww, int uu, int vv, int ii) {
		w = ww;
		u = uu;
		v = vv;
		i = ii;
	}
	bool operator < (const edge &a) const {
		return w < a.w;
	}
};

int n;
vector<int> w;
vector<vector<int>> g;
vector<int> st, en;
int tim = 0;

vector<edge> E;
dsu D;
ll ans = 0;
vector<int> good;

void dfs(int v, int prev) {
	st[v] = tim;
	if (prev != -1 && g[v].size() == 1) tim++;
	else {
		for (const auto &i : g[v])
			if (i != prev)
				dfs(i, v);
	}
	en[v] = tim;
}

void work(const vector<edge> &A) {
	for (const auto &i : A)
		if (D.valid(i.u, i.v))
			good.push_back(i.i);
	for (const auto &i : A)
		if (D.unite(i.u, i.v))
			ans += i.w;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n;
	w.resize(n);
	g.resize(n);
	st.resize(n);
	en.resize(n);
	D = dsu(n + 1);
	for (auto &i : w) cin >> i;
	for (int i = 0, u, v; i < n - 1; i++) {
		cin >> u >> v;
		--u, --v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(0, -1);
	for (int i = 0; i < n; i++)
		E.push_back(edge(w[i], st[i], en[i], i + 1));
	sort(E.begin(), E.end());
	vector<edge> tmp;
	for (int i = 0; i < E.size(); i++) {
		if (tmp.size() && tmp[0].w != E[i].w) {
			work(tmp);
			tmp.clear();
		}
		tmp.push_back(E[i]);
	}
	work(tmp);
	sort(good.begin(), good.end());

	cout << ans << " " << good.size() << '\n';
	for (const auto &i : good) cout << i << " "; cout << '\n';
}
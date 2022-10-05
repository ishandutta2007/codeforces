#include <bits/stdc++.h>
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7;
const ll inf = 3e18;
const int OO = 0;
using namespace std;

struct edge {
	int from, to, w;
	edge() {}
	edge(int ff, int tt, int ww) {
		from = ff;
		to = tt;
		w = ww;
	}
	bool operator < (const edge &e) const {
		return w > e.w;
	}
};

int n, m;
vector<vector<edge>> g;
vector<vector<edge>> t;
vector<int> comp;

ll mst() {
	set<int> need;
	vector<int> really(n, 1);
	for (int i = 0; i < n; i++)
		need.insert(need.end(), i);
	ll total = 0;
	priority_queue<edge> q;
	q.push(edge(-1, 0, 0));
	while (q.size()) {
		edge x = q.top();
		if (OO) cout << x.to << " " << x.w << '\n';
		q.pop();
		if (!really[x.to]) {
			continue;
		}
		if (x.from != -1) {
			t[x.from].push_back(edge(x.from, x.to, x.w));
			t[x.to].push_back(edge(x.to, x.from, x.w));
		}
		if (need.count(x.to))
			need.erase(x.to);
		really[x.to] = 0;
		total += x.w;
		auto it = need.begin();
		if (OO) {
			cout << "begin\n";
			for (const auto &i : need) cout << i << " "; cout << '\n';
		}
		for (const auto &i : g[x.to]) {
			while (it != need.end() && *it < i.to) {
				if (OO) cout << "zero to " << *it << '\n';
				q.push(edge(x.to, *it, 0));
				it++;
				need.erase(prev(it));
			}
			if (it != need.end() && *it == i.to) it++;
			q.push(i);
		}
		while (it != need.end()) {
			q.push(edge(x.to, *it, 0));
			it++;
			need.erase(prev(it));
		}
	}
	return total;
}

void dfs(int v, int col) {
	if (comp[v] != -1) return;
	comp[v] = col;
	for (const auto &i : t[v])
		if (i.w > 0)
			dfs(i.to, col);
}

bool cmp(const edge &a, const edge &b) {
	return a.to < b.to;
}

void solve() {
	cin >> n >> m;
	g.resize(n);
	t.resize(n);
	int xo = 0;
	for (int i = 0, u, v, w; i < m; i++) {
		cin >> u >> v >> w;
		u--, v--;
		xo ^= w;
		g[u].push_back(edge(u, v, w));
		g[v].push_back(edge(v, u, w));
	}
	if (n == 2) {
		if (m == 0) {
			cout << "0\n";
			return;
		}
		cout << g[0][0].w << '\n';
		return;
	}

	for (int i = 0; i < n; i++) {
		sort(g[i].begin(), g[i].end(), cmp);
	}
	ll res = mst();
	if (n > 650) {
		cout << res << '\n';
		return;
	}
	int zeros = n * (n - 1) / 2 - m;
	comp.resize(n, -1);
	int nxtcol = 0;
	for (int i = 0; i < n; i++) {
		if (comp[i] == -1) {
			dfs(i, nxtcol);
			nxtcol++;
		}
	}
	int intree = 0;
	for (int i = 0; i < n; i++) {
		for (const auto &j : t[i])
			if (j.w == 0) intree++;
	}
	intree /= 2;
	if (intree < zeros) {
		cout << res << '\n';
		return;
	}


	ll mn = inf;
	for (int i = 0; i < n; i++) {
		for (const auto &j : g[i]) {
			if (comp[i] != comp[j.to]) {
				mn = min(mn, (ll)j.w);
			}
		}
	}
	cout << min(res + xo, res + mn) << '\n';
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int tst = 1;
	//cin >> tst;
	while (tst--) solve();
}
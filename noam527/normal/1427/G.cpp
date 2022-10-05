#include <bits/stdc++.h>
#define finish(x) return cout << x << endl, 0
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7;
const ll inf = 2e18;
const int OO = 0;
const int OOO = 1;
using namespace std;

const int M1 = 1000, M2 = 1000000;

struct edge {
	int to, w;
	edge() {}
	edge(int v, int ww) {
		to = v;
		w = ww;
	}
};

int n;
int a[202][202];

vector<edge> base;
vector<edge> e;
vector<vector<int>> g;
vector<int> vis;
int nxtcol = 10;
int S, T;

int encode(int i, int j) {
	return n * i + j;
}

void addedge(int u, int v, int w1, int w2 = 0) {
	g[u].push_back(e.size());
	e.push_back(edge(v, w1));
	g[v].push_back(e.size());
	e.push_back(edge(u, w2));
}

void smallclear() {
	while (e.size() > base.size()) {
		g[e.back().to].pop_back();
		e.pop_back();
	}
	e = base;
}

bool dfs(int v, int col, int ww) {
	if (v == T) return true;
	if (vis[v] == col) return false;
	vis[v] = col;
	for (const auto &i : g[v]) {
		if (e[i].w >= ww) {
			if (dfs(e[i].to, col, ww)) {
				e[i].w -= ww;
				e[1 ^ i].w += ww;
				return true;
			}
		}
	}
	return false;
}

ll maxflow() {
	nxtcol++;
	ll res = 0;
	int ww = 1000000;
	while (ww > 0) {
		nxtcol++;
		while (dfs(S, nxtcol, ww)) {
			res += ww;
			nxtcol++;
		}
		ww /= 2;
	}
	return res;
}

void solve() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			cin >> a[i][j];
	}
	vector<int> vals;
	for (int i = 0; i < n; i++) {
		vals.push_back(a[i][0]);
		vals.push_back(a[i][n - 1]);
	}
	for (int j = 0; j < n; j++) {
		vals.push_back(a[0][j]);
		vals.push_back(a[n - 1][j]);
	}
	sort(vals.begin(), vals.end());
	vals.resize(unique(vals.begin(), vals.end()) - vals.begin());


	g.resize(n * n + 2);
	vis.resize(n * n + 2, 0);
	nxtcol = 10;
	S = n * n;
	T = n * n + 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int u, v;
			if (i + 1 < n && a[i][j] != -1 && a[i + 1][j] != -1) {
				u = encode(i, j);
				v = encode(i + 1, j);
				addedge(u, v, 1, 1);
			}
			if (j + 1 < n && a[i][j] != -1 && a[i][j + 1] != -1) {
				u = encode(i, j);
				v = encode(i, j + 1);
				addedge(u, v, 1, 1);
			}
		}
	}
	base = e;

	for (int i = 0; i < n; i++) {
		int v = encode(i, 0);
		addedge(v, T, M1, 0);

		v = encode(i, n - 1);
		addedge(v, T, M1, 0);
	}
	for (int j = 1; j < n - 1; j++) {
		int v = encode(0, j);
		addedge(v, T, M1, 0);

		v = encode(n - 1, j);
		addedge(v, T, M1, 0);
	}

	int badcnt = 0;


	ll ans = 0;
	ll prevflow = 0;
	for (int x = 0; x + 1 < vals.size(); x++) {
		int lo = vals[x], hi = vals[x + 1];
		for (int i = 0; i < n; i++) {
			int v = encode(i, 0);
			if (a[i][0] == lo)
				addedge(S, v, M2, 0), badcnt++;

			v = encode(i, n - 1);
			if (a[i][n - 1] == lo)
				addedge(S, v, M2, 0), badcnt++;
		}
		for (int j = 1; j < n - 1; j++) {
			int v = encode(0, j);
			if (a[0][j] == lo)
				addedge(S, v, M2, 0), badcnt++;

			v = encode(n - 1, j);
			if (a[n - 1][j] == lo)
				addedge(S, v, M2, 0), badcnt++;
		}


		ll m = maxflow();
		prevflow += m;
		if (OO) {
			cout << "with lo hi: " << lo << " " << hi << '\n';
			cout << "maxflow: " << prevflow << '\n';
		}
		ans += (prevflow - badcnt * M1) * ll(hi - lo);
	}
	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int tst = 1;
	//cin >> tst;
	while (tst--) {
		solve();
	}
}
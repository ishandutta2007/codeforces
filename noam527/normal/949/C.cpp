#include <bits/stdc++.h>
#define finish(x) return cout << x << endl, 0
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7;
const ll inf = 4e18;
const int OO = 1;
const int OOO = 1;
using namespace std;

int n, m, h;
vector<vector<int>> g, t;
vector<int> tt;
vector<int> vis;

vector<int> ans;

vector<int> col;
int nxtcol = 1;

void dfs1(int v, vector<int> &a) {
	if (vis[v]) return;
	vis[v] = 1;
	for (const auto &i : t[v])
		dfs1(i, a);
	a.push_back(v);
}

vector<int> toposort() {
	for (auto &i : vis) i = 0;
	vector<int> a;
	for (int i = 0; i < n; i++) dfs1(i, a);
	reverse(a.begin(), a.end());
	return a;
}

bool dfs2(int v, vector<int> &a) {
	if (vis[v]) {
		if (col[v] < nxtcol) return false;
		return true;
	}
	vis[v] = 1;
	col[v] = nxtcol;
	for (const auto &i : g[v])
		if (!dfs2(i, a)) return false;
	a.push_back(v);
	return true;
}

void addedge(int u, int v) {
	g[u].push_back(v);
	t[v].push_back(u);
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n >> m >> h;
	g.resize(n);
	t.resize(n);
	vis.resize(n, 0);
	tt.resize(n);
	for (auto &i : tt) cin >> i;
	for (int i = 0, u, v; i < m; i++) {
		cin >> u >> v;
		--u, --v;
		if ((tt[u] + 1) % h == tt[v]) addedge(u, v);
		if ((tt[v] + 1) % h == tt[u]) addedge(v, u);
	}
	vector<int> ord = toposort();
	vector<int> tmp;
	col.resize(n, 0);
	ans.resize(n + 1);

	for (auto &i : vis) i = 0;

	for (const auto &i : ord) {
		tmp.clear();
		bool f = dfs2(i, tmp);
		if (f) {
			if (ans.size() > tmp.size()) {
				ans = tmp;
			}
		}
		nxtcol++;
	}
	cout << ans.size() << '\n';
	for (const auto &i : ans) cout << i + 1 << " "; cout << '\n';
}
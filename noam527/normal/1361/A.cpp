#include <bits/stdc++.h>
#define finish(x) return cout << x << endl, 0
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7;
const ll inf = 2e18;
const int OO = 1;
const int OOO = 1;
using namespace std;

int mex(vector<int> &a) {
	sort(a.begin(), a.end());
	a.resize(unique(a.begin(), a.end()) - a.begin());
	for (int i = 0; i < a.size(); i++) {
		if (a[i] != i + 1)
			return i + 1;
	}
	return (int)a.size() + 1;
}

int n, m;
vector<vector<int>> g;
vector<vector<int>> col;

vector<int> c;

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n >> m;
	g.resize(n);
	col.resize(n + 5);
	for (int i = 0, u, v; i < m; i++) {
		cin >> u >> v;
		--u, --v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		col[x].push_back(i);
	}

	c.resize(n, -1);
	vector<int> ans;
	for (int i = 1; i <= n; i++) {
		for (const auto &v : col[i]) {
			ans.push_back(v);
			vector<int> tmp;
			for (const auto &u : g[v])
				if (c[u] != -1)
					tmp.push_back(c[u]);
			if (mex(tmp) != i) {
				finish(-1);
			}
			c[v] = i;
		}
	}
	for (const auto &i : ans) cout << i + 1 << " "; cout << endl;
}
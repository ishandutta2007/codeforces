#include <bits/stdc++.h>
#define endl '\n'
#define flush fflush(stdout), cout.flush()
#define fast ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define debug cout << "ok" << endl
#define finish(x) return cout << x << endl, 0
#define yesno(X) cout << ((X) ? "YES" : "NO") << endl
#define noyes(X) cout << ((X) ? "NO" : "YES") << endl
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7, inf = 1e9 + 7;
const ll hs = 199;
const ldb eps = 1e-9, pi = acos(-1);
using namespace std;

int n, d[100010] = {};
vector<vector<int>> g;

int dfs(int v, int prev = -1) {
	int rtn = v;
	for (const auto &i : g[v])
		if (i != prev)
			rtn = dfs(i, v);
	return rtn;
}

vector<vector<int>> ans;

int main() {
	fast;
	cin >> n;
	g.resize(n);
	for (int i = 0, u, v; i < n - 1; i++) {
		cin >> u >> v;
		--u, --v;
		g[u].push_back(v);
		g[v].push_back(u);
		d[u]++;
		d[v]++;
	}
	int at = 0;
	for (int i = 1; i < n; i++)
		if (d[i] > d[at]) at = i;
	int mx = 0;
	for (int i = 0; i < n; i++)
		if (i != at)
			mx = max(mx, d[i]);
	if (mx > 2) finish("No");
	cout << "Yes" << endl;
	for (const auto &i : g[at]) {
		ans.push_back(vector<int>());
		ans.back().push_back(at);
		ans.back().push_back(dfs(i, at));
	}
	cout << ans.size() << endl;
	for (const auto &i : ans) {
		for (const auto &j : i) cout << 1 + j << " "; cout << endl;
	}
}
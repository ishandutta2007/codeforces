#include <bits/stdc++.h>
#define finish(x) return cout << x << endl, 0
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7;
const ll inf = 2e18;
const int OO = 1;
const int OOO = 1;
using namespace std;

int n;
vector<vector<int>> g;
vector<int> col, par;

void dfs(int v, int pre, int c) {
	par[v] = pre;
	col[v] = c;
	for (const auto &i : g[v])
		if (i != pre)
			dfs(i, v, 1 ^ c);
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n;
	g.resize(n);
	col.resize(n, -1);
	par.resize(n, -1);
	for (int i = 0, u, v; i < n - 1; i++) {
		cin >> u >> v;
		--u, --v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	int r = 0;
	for (int i = 0; i < n; i++)
		if (g[i].size() > 1) {
			r = i;
			break;
		}
	dfs(r, -1, 0);
	vector<int> C, P;
	for (int i = 0; i < n; i++)
		if (g[i].size() == 1) {
			C.push_back(col[i]);
			P.push_back(par[i]);
		}
	int mn, mx;
	if (*max_element(C.begin(), C.end()) == *min_element(C.begin(), C.end()))
		mn = 1;
	else
		mn = 3;
	mx = n - 1 - P.size();
	sort(P.begin(), P.end());
	P.resize(unique(P.begin(), P.end()) - P.begin());
	mx += P.size();
	cout << mn << " " << mx << endl;
}
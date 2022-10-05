#include <bits/stdc++.h>
#define finish(x) return cout << x << endl, 0
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7;
const ll inf = 4e18;
const int OO = 0;
const int OOO = 1;
using namespace std;

int n;
vector<vector<int>> g;
vector<pair<int, int>> op;
int T;

void dfs(int v, int prev, int t) {
	if (OO) {
		cout << "start " << v << " " << t << endl;
	}
	op.emplace_back(v, t);
	int tt = t;
	int left = (v == 0 ? (int)g[v].size() : (int)g[v].size() - 1);
	for (int i = 0; i < g[v].size(); i++) {
		if (g[v][i] != prev) {
			int u = g[v][i];
			if (tt == T) {
				tt = t - left - 1;
				op.emplace_back(v, tt);
			}
			if (OO) {
				cout << "going " << u << " " << tt << endl;
			}
			dfs(u, v, tt + 1);
			tt++;
			op.emplace_back(v, tt);
			left--;
		}
	}
	if (v != 0 && tt + 1 != t) {
		op.emplace_back(v, t - 1);
	}
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n;
	g.resize(n);
	for (int i = 0, u, v; i < n - 1; i++) {
		cin >> u >> v;
		--u, --v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	T = 0;
	for (int i = 0; i < n; i++)
		T = max(T, (int)g[i].size());

	dfs(0, 0, 0);
	cout << op.size() << endl;
	for (const auto &i : op)
		cout << i.first + 1 << " " << i.second << endl;
}
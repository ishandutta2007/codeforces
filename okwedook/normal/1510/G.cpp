#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("sse4.2")

#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> G;
vector<int> max_d;
vector<int> max_dep;

vector<int> ans;

int k = 0;
int have = 0;
int need = 0;

int dfs1(int v, int p = -1) {
 	for (int to : G[v])
		if (to != p) {
			int d = dfs1(to, v);
			if (d + 1 > max_dep[v]) {
				max_dep[v] = d + 1;
				max_d[v] = to;
			}
		}
	return max_dep[v];
}

void dfs3(int v, int p = -1) {
	// cout << 3 << ' ' << v + 1 << endl;
	if (have == k)
		return;
	ans.push_back(v + 1);
	have++;
	need--;
	for (int to : G[v])
		if (to != p && need > 0) {
			dfs3(to, v);
			// cout << 33 << ' ' << v + 1 << endl;
			ans.push_back(v + 1);
		}
}

void dfs2(int v, int p = -1) {
	// cout << 2 << ' ' << v + 1 << endl;
	if (have == k)
		return;
	ans.push_back(v + 1);
	have++;
	for (int to : G[v])
		if (to != p && to != max_d[v] && need > 0) {
			dfs3(to, v);
			ans.push_back(v + 1);
			// cout << 22 << ' ' << v + 1 << endl;
		}
	
	if (have != k)
		dfs2(max_d[v], v);	
}

void solve() {
	ans.clear();
	int n;
	cin >> n >> k;
	G = vector<vector<int>> (n);
	max_d = vector<int> (n, -1);
	max_dep = vector<int> (n, 1);
	for (int i = 0; i < n - 1; ++i) {
		int u = i + 1;
		int v;
		cin >> v; v--;
		G[v].push_back(u);
		G[u].push_back(v);
	}
	dfs1(0);
	// for (auto i : max_dep) cout << i << ' '; cout << '\n';
	// for (auto i : max_d)   cout << i << ' '; cout << '\n';
	have = 0;
	need = max(0, k - max_dep[0]);

	dfs2(0);
	cout << ans.size() - 1 << '\n';
	for (int i : ans)
		cout << i << ' ';
	cout << '\n';
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;
	while (t--)
		solve();

	return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <string>
#include <time.h>
#include <queue>
#define last(x, y) (x)[(x).size() - (y)]
#define endl '\n'
#define flush fflush(stdout), cout.flush()
#define fast ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define debug cout << "ok" << endl
#define in(X) ((X) - '0')
#define finish(x) return cout << x << endl, 0
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7;
const ll hs = 199;
//const ldb eps = 1e-9, pi = acos(-1);
using namespace std;

int n;
vector<vector<int>> g, ssz;
vector<int> vis, ans;

void dfs(int v, int prev = -1) {
	ssz[v].clear();
	for (auto &i : g[v]) {
		if (!vis[i] && i != prev) {
			dfs(i, v);
			int sum = 0;
			for (auto &j : ssz[i]) sum += j;
			ssz[v].push_back(sum + 1);
		}
	}
	if (!ssz[v].size()) ssz[v].push_back(0);
}

void dfs2(int tot, int v, int prev = -1) {
	int sum = 0;
	for (auto &i : ssz[v]) sum += i;
	ssz[v].push_back(tot - sum - 1);
	for (auto &i : g[v])
		if (!vis[i] && i != prev) dfs2(tot, i, v);
}

int find(int tot, int v, int prev = -1) {
	bool good = true;
	for (auto &i : ssz[v]) good = good && (2 * i <= tot);
	if (good) return v;
	for (auto &i : g[v])
		if (!vis[i] && i != prev) {
			int temp = find(tot, i, v);
			if (temp != -1) return temp;
		}
	return -1;
}

void solve(int v = 0, int lvl = 0) {
	dfs(v);
	int sum = 0;
	for (auto &i : ssz[v]) sum += i;
	dfs2(sum, v);
	int at = find(sum, v);
//	cout << "at " << at << endl;
	ans[at] = lvl, vis[at] = 1;
	for (auto &i : g[at])
		if (!vis[i]) solve(i, lvl + 1);
}

int main() {
	fast;
	cin >> n;
	g.resize(n), ssz.resize(n), vis.resize(n, 0), ans.resize(n);
	for (int i = 0, u, v; i < n - 1; i++) {
		cin >> u >> v, --u, --v;
		g[u].push_back(v), g[v].push_back(u);
	}
	solve();
	for (auto &i : ans) cout << char(i + 'A') << " "; cout << endl;
}
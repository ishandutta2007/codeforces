#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <string>
#include <time.h>
#include <stack>
#include <queue>
#include <random>
#include <fstream>
#define endl '\n'
#define flush fflush(stdout), cout.flush()
#define fast ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define debug cout << "ok" << endl
#define finish(x) return cout << x << endl, 0
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7, inf = 1e9 + 7;
const ll hs = 199;
const ldb eps = 1e-9, pi = acos(-1);
using namespace std;

int r;
int n, d[200000] = {};
vector<vector<int>> g;
vector<int> vis, ans;

void solve(int v, int prev) {
	if (vis[v]) return;
	vis[v] = 1;
	ans.push_back(v);
	for (const auto &i : g[v])
		if (i != prev)
			solve(i, v);
}

void dfs(int v = r, int prev = -1) {
	for (const auto &i : g[v])
		if (i != prev)
			dfs(i, v);
	if (d[v] % 2 == 0) {
		if (prev != -1) d[prev]--;
		solve(v, prev);
	}
}

int main() {
	fast;
	cin >> n;
	g.resize(n);
	vis.resize(n, 0);
	for (int i = 0, x; i < n; i++) {
		cin >> x;
		if (x == 0) r = i;
		else {
			--x;
			g[i].push_back(x);
			g[x].push_back(i);
			d[i]++, d[x]++;
		}
	}
	dfs();
	if (ans.size() != n) finish("NO");
	cout << "YES" << endl;
	for (const auto &i : ans) cout << i + 1 << endl;
}
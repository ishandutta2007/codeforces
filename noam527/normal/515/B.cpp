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
#define finish return cout << "NO" << endl, 0
#define all(X) (X).begin(), (X).end()
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7;
const ll hs = 199;
const ldb eps = 1e-9, pi = acos(-1);
using namespace std;

int n, m, x, y;
vector<int> a, b, vis;
vector<vector<int>> g;

void dfs(int v) {
	if (vis[v]) return;
	vis[v] = 1;
	for (auto &i : g[v]) dfs(i);
}

int main() {
	fast;
	cin >> n >> m;
	vis.resize(n + m, 0), g.resize(n + m);
	cin >> x;
	while (x--) cin >> y, a.push_back(y);
	cin >> x;
	while (x--) cin >> y, b.push_back(y);

	g[0].push_back(n), g[n].push_back(0);
	for (int i = 1 % n, j = 1 % m; i != 0 || j != 0; i = (i + 1) % n, j = (j + 1) % m)
		g[i].push_back(n + j), g[n + j].push_back(i);

	for (auto &i : a) dfs(i);
	for (auto &i : b) dfs(n + i);
	for (auto &i : vis) if (!i) finish;
	cout << "YES" << endl;
}
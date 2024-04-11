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

int n, a[100005], u, v;
vector<vector<int>> g;
vector<int> ans;

void dfs(int v = 0, int prev = -1, int d = 0, vector<int> x = {}) {
	if (a[v] ^ x[d & 1]) ans.push_back(v + 1), x[d & 1] ^= 1;
	for (auto &i : g[v])
		if (i != prev)
			dfs(i, v, d ^ 1, x);
}

int main() {
	fast;
	cin >> n;
	g.resize(n);
	for (int i = 0; i < n - 1; i++)
		cin >> u >> v, g[--u].push_back(--v), g[v].push_back(u);
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < n; i++)
		cin >> u, a[i] ^= u;

	dfs(0, -1, 0, vector<int>(2));
	cout << ans.size() << endl;
	for (auto &i : ans) cout << i << endl;
}
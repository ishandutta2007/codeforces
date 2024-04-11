#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <string>
#define last(x, y) (x)[(x).size() - y]
#define endl '\n'
#define flush fflush(stdout), cout.flush()
#define fast ios::sync_with_stdio(0), cin.tie(0)
#define debug cout << "ok" << endl
#define in(X) ((X) - '0')
const int md = 1e9 + 7;
typedef long long ll;
typedef long double ldb;
using namespace std;

int n;
ldb ans = 0;
vector<vector<int>> g;

ldb dfs(int v = 0, int prev = -1, int dis = 0, ll divby = 1) {
	if (g[v].size() == 1 && g[v][0] == prev)
		return 0;
	ldb tot = 0;
	for (auto &i : g[v])
		if (i != prev)
			tot += dfs(i, v, dis + 1, divby * ll(g[v].size()));
	ldb temp = tot / (g[v].size() - (prev == -1 ? 0.0 : 1.0)) + 1;
	return temp;
}

int main() {
	fast;
	cin >> n;
	if (n == 1){
	    cout << 0 << endl;
	    return 0;
	}
	g.resize(n);
	for (int i = 0, u, v; i < n - 1; i++) {
		cin >> u >> v;
		u--, v--;
		g[u].push_back(v), g[v].push_back(u);
	}
	cout.precision(20);
	cout << dfs() << endl;
}
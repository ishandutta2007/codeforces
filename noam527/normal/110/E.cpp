#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <string>
#include <time.h>
#define last(x, y) (x)[(x).size() - y]
#define endl '\n'
#define flush fflush(stdout), cout.flush()
#define fast ios::sync_with_stdio(0), cin.tie(0)
#define debug cout << "ok" << endl
#define in(X) ((X) - '0')
const int md = 1e9 + 7;
const long long hs = 137;
//const double pi = acos(-1);
typedef long long ll;
typedef long double ldb;
using namespace std;

ll ans = 0;
int n;
vector<vector<int>> g;
vector<int> vis;
vector<ll> s;

bool spe(int x) {
	while (x) {
		if (x % 10 != 4 && x % 10 != 7) return false;
		x /= 10;
	}
	return true;
}

int dfs(int v) {
	if (vis[v]) return 0;
	vis[v] = 1;
	int rtn = 1;
	for (auto &i : g[v]) rtn += dfs(i);
	return rtn;
}

int main() {
	fast;
	cin >> n;
	g.resize(n), vis.resize(n, 0);
	for (int i = 0, u, v, c; i < n - 1; i++) {
		cin >> u >> v >> c;
		--u, --v;
		if (!spe(c)) g[u].push_back(v), g[v].push_back(u);
	}
	for (int i = 0; i < n; i++)
		if (!vis[i])
			s.push_back(dfs(i));

	for (auto i : s)
		ans += i * (n - i) * (n - i - 1);
	cout << ans << endl;
}
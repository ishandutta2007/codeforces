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

unordered_set<ll> used;
int n, m;
vector<vector<int>> g, ans;
vector<int> vis;

ll f(int u, int v) { return (ll)1e6 * min(u, v) + max(u, v); }

int dfs(int v, int prev = -1) {
//	cout << "v " << v << endl;
	if (vis[v]) return v;
	vis[v] = 1;
	vector<int> s;
	for (auto &i : g[v])
		if (i != prev) {
//			cout << v << "->" << i << endl;
			int val = dfs(i, v);
			if (val != -1 && used.find(f(v, i)) == used.end()) s.push_back(val);
		}
//	cout << "v " << v << " s size " << s.size() << endl;

	int i1 = 0, i2 = 1;
	while (i2 < s.size()) {
		ans.push_back({ s[i1], v, s[i2] });
		used.insert(f(s[i1], v)), used.insert(f(s[i2], v));
		i1 += 2, i2 += 2;
	}
	if (i1 == s.size()) return v;
	if (prev != -1) {
		ans.push_back({ s[i1], v, prev });
		used.insert(f(s[i1], v)), used.insert(f(v, prev));
	}
	return -1;
}

int main() {
	fast;
	cin >> n >> m;
	g.resize(n);
	vis.resize(n, 0);
	for (int i = 0, u, v; i < m; i++)
		cin >> u >> v, --u, --v, g[u].push_back(v), g[v].push_back(u);

	for (int i = 0; i < n; i++)
		if (!vis[i]) dfs(i);

	cout << ans.size() << endl;
	for (auto &i : ans)
		cout << i[0] + 1 << " " << i[1] + 1 << " " << i[2] + 1 << endl;
}
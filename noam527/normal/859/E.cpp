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

int n;
ll ans = 1;
vector<vector<int>> g;
vector<int> vis, danger;

int pow(ll b, int e) {
	int rtn = 1;
	while (e) {
		if (e & 1) rtn = (rtn * b) % md;
		b = (b * b) % md, e /= 2;
	}
	return rtn;
}

int inv(int x) {
	return pow(x, md - 2);
}

int dfs(int v, int prev = -1) {
	int rtn = 1;
	for (auto &i : g[v])
		if (i != prev)
			rtn += dfs(i, v);
	return rtn;
}

pair<int, bool> check(int v, int prev = -1) {
	if (vis[v]) return{ 1, false };
	pair<int, bool> rtn = { 0, false };
	vis[v] = 1;
	if (danger[v])
		rtn.second = true;
	for (auto &i : g[v])
		if (i != prev) {
			auto temp = check(i, v);
			rtn.first += temp.first, rtn.second = rtn.second || temp.second;
		}
	return rtn;
}

bool process(int v) {
//	cout << "processing " << v << endl;
	auto t = check(v);
//	cout << t.first << endl;
	if (t.first / 2 > 1) return false;
	if (t.first == 1 || t.first / 2 == 1) {
		if (!t.second)
			ans = (ans * 2) % md;
		return true;
	}

	ans = (ans * dfs(v)) % md;
	return true;
}

int main() {
	fast;
	cin >> n;
	g.resize(2 * n);
	vis.resize(2 * n, 0);
	danger.resize(2 * n, 0);
	for (int i = 0, u, v; i < n; i++) {
		cin >> u >> v;
		--u, --v;
		if (u != v)
			g[u].push_back(v), g[v].push_back(u);
		else
			g[u].push_back(v), danger[u] = 1;
	}
	for (int i = 0; i < 2 * n; i++) {
		if (!vis[i] && g[i].size() > 0)
			if (!process(i)) {
//				cout << "process went bad :(" << endl;
				cout << 0 << endl;
				return 0;
			}
//			else
//				cout << "current " << ans << endl;
	}
	cout << ans << endl;
}
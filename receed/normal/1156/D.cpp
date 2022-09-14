#include <iostream>
#include <iomanip>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <random>
#include <bitset>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <deque>
#include <queue>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

using namespace std;
using ll = long long;
using ld = long double;

const int N = 200002;
vector<pair<int, int>> g[N];
int c[N][2], used[N][2];

int dfs(int v, int p, int cc) {
	used[v][cc] = 1;
	int res = 1;
	for (auto &u : g[v]) {
		if (u.first == p || u.second != cc)
			continue;
		res += dfs(u.first, v, cc);
	}
	return res;
}

void dfs2(int v, int p, int cc, int nc) {
	c[v][cc] = nc;
	for (auto &u : g[v]) {
		if (u.first == p || u.second != cc)
			continue;
		dfs2(u.first, v, cc, nc);
	}
}


int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n, u, v, cc;
	cin >> n;
	rep(i, n - 1) {
		cin >> u >> v >> cc;
		g[u].push_back({v, cc});
		g[v].push_back({u, cc});
	}
	for (int i = 1; i <= n; i++)
		rep(j, 2)
			if (!used[i][j])
				dfs2(i, -1, j, dfs(i, -1, j));
	ll ans = 0;
	for (int i = 1; i <= n; i++)
		ans += (ll) c[i][0] * c[i][1] - 1;
	cout << ans;
}
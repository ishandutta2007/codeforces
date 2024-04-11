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
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <deque>
#include <queue>
#define rep(i, n) for (int i = 0; i < (n); i++)
 
typedef long long ll;
typedef long double ld;
using namespace std;

const int MOD = 998244353;
vector<vector<int>> g;
vector<int> used, cc;

int dfs(int v, int c) {
	used[v] = c;
	cc[c - 1]++;
	for (int u : g[v]) {
		if (used[u] == c || !used[u] && dfs(u, 3 - c))
			return 1;
	}
	return 0;
}

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll t, n, m, u, v;
	cin >> t;
	rep(z, t) {
		cin >> n >> m;
		g.assign(n, vector<int>());
		used.assign(n, 0);
		rep(i, m) {
			cin >> u >> v;
			u--; v--;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		ll ans = 1;
		vector<int> p2(n + 1, 1);
		rep(i, n)
			p2[i + 1] = p2[i] * 2 % MOD;
		rep(i, n) {
			if (used[i])
				continue;
			cc = {0, 0};
			if (dfs(i, 1)) {
				ans = 0;
				break;
			}
			ans = ans * (p2[cc[0]] + p2[cc[1]]) % MOD;
		}
		cout << ans << '\n';
	}
}
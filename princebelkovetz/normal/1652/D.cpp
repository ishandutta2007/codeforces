#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cassert>
#include <iomanip>
#include <queue>
#include <set>
#include <map>

using namespace std;
#define int long long
#define debug(x) cout << #x << " is " << x < '\n';
#define ld long double
const int mod = 998244353, N = 1e5 + 2;

vector <vector <vector <int>>> g;
vector <int> d, cur1, cur2, res;
int binpow(int a, int b) {
	if (!b) return 1ll;
	if (b & 1) return a * binpow(a, b - 1) % mod;
	int t = binpow(a, b / 2);
	return t * t % mod;
}

vector <pair <int, int>> get(int x) {
	vector <pair <int, int>> res;
	for (int i = 2; i * i <= x; ++i) {
		if (x % i == 0) {
			res.push_back({ i, 0 });
			while (x % i == 0) 
				res.back().second++, x /= i;
		}
	}
	if (x != 1) res.push_back({ x, 1 });
	return res;
}
void dfs(int v, int p) {
	for (auto& u : g[v]) {
		if (u[0] == p) continue;
		auto d1 = get(u[1]), d2 = get(u[2]);
		for (auto& x : d2)
			cur2[x.first] += x.second;
		for (auto& x : d1) {
			cur1[x.first] += x.second;
			d[x.first] = max({ 0ll, d[x.first], cur1[x.first] - cur2[x.first] });
		}
		dfs(u[0], v);
		for (auto& x : d2)
			cur2[x.first] -= x.second;
		for (auto& x : d1) 
			cur1[x.first] -= x.second;
	}
}

void dfsCalc(int v, int p) {
	for (auto& u : g[v]) {
		if (u[0] == p) continue;
		res[u[0]] = res[v] * binpow(u[1], mod - 2) % mod * u[2] % mod;
		dfsCalc(u[0], v);
	}
}

signed main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int tt; cin >> tt;
	while (tt--) {
		int n; cin >> n;
		g.assign(n + 1, {});
		res.assign(n + 1, 1);
		d.assign(n + 1, 0);
		cur1.assign(n + 1, 0);
		cur2.assign(n + 1, 0);
		for (int i = 0, u, v, x, y; i < n - 1; ++i) {
			cin >> u >> v >> x >> y;
			g[u].push_back({ v, x, y });
			g[v].push_back({ u, y, x });
		}
		dfs(1, 1);
		for (int i = 1; i < d.size(); ++i){
			res[1] = res[1] * binpow(i, d[i]) % mod;
		}
		dfsCalc(1, 1);
		int ans = 0;
		for (int i = 1; i <= n; ++i)
			ans = (ans + res[i]) % mod;
		cout << ans << '\n';
	}
	
}
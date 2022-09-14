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

typedef long long ll;
typedef long double ld;
using namespace std;

const int N = 300001;
const ll MOD = 998244353;
ll d1[N], d2[N], d3[N];
vector<int> g[N];

ll pw(ll x, ll k) {
	if (!k)
		return 1;
	if (k % 2)
		return pw(x, k - 1) * x % MOD;
	return pw(x * x % MOD, k / 2);
}

ll di(ll x, ll y) {
	return x * pw(y, MOD - 2) % MOD;
}

void dfs(int v, int p) {
	ll pr = 1;
	d3[v] = 1;
	for (int u : g[v]) {
		if (u == p)
			continue;
		dfs(u, v);
		pr = (d1[u] * 2 + d3[u]) % MOD * pr % MOD;
		d3[v] = (d1[u] + d3[u]) % MOD * d3[v] % MOD;
	}
	d2[v] = pr;
	for (int u : g[v]) {
		if (u == p)
			continue;
		d1[v] = (d1[v] + di(pr, (2 * d1[u] + d3[u]) % MOD) * d2[u] % MOD) % MOD;
	}
}

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, u, v;
	cin >> n;
	for (int i = 1; i < n; i++) {
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(1, -1);
	cout << (d1[1] + d3[1]) % MOD;
}
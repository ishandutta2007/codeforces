#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cassert>

typedef long long ll;
typedef long double ld;
using namespace std;

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, m;
	cin >> n >> m;
	vector<vector<ll>> a(n, vector<ll>(2)), b(n, vector<ll>(2));
	vector<vector<int>> g(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i][0] >> a[i][1];
		b[i] = {a[i][1] - a[i][0], i};
	}
	int u, v;
	for (int i = 0; i < m; i++) {
		cin >> u >> v;
		u--; v--;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	sort(b.begin(), b.end());
	vector<ll> p1(n + 1), p2(n + 1);
	for (int i = 0; i < n; i++)
		p2[i + 1] = p2[i] + a[b[i][1]][1];
	for (int i = n - 1; i >= 0; i--)
		p1[i] = p1[i + 1] + a[b[i][1]][0];
	for (int i = 0; i < n; i++) {
		int pos = lower_bound(b.begin(), b.end(), vector<ll>({a[i][1] - a[i][0], i})) - b.begin();
		ll ans = a[i][0] * pos + p2[pos] + a[i][1] * (n - 1 - pos) + p1[pos + 1];
		for (int j : g[i])
			ans -= min(a[i][0] + a[j][1], a[i][1] + a[j][0]);
		cout << ans << ' ';
	}
}
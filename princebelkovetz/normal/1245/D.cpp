#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <iomanip>
#include <cassert>
#include <queue>
using namespace std;
#define int long long
#define debug(x) cout << #x << " is " << x << '\n';
const int N = 1e6 + 2, mod = 1e9 + 7, mod2 = 998244353;

vector <vector <int>> a;
vector <int> c, k;
int cost(int i, int j) {
	return (abs(a[i][0] - a[j][0]) + abs(a[i][1] - a[j][1])) * (k[i] + k[j]);
}
signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(6);
	int n; cin >> n;
	a.resize(n);
	c.resize(n);
	k.resize(n);
	for (auto& x : a)
		x.resize(2), cin >> x[0] >> x[1];
	for (auto& x : c) cin >> x;
	for (auto& x : k) cin >> x;
	vector <vector <pair <int, int>>> g(n + 1);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			g[i].push_back({ j, cost(i, j) });
		}
	}
	for (int i = 0; i < n; ++i) {
		g[i].push_back({ n, c[i] });
		g[n].push_back({ i, c[i] });
	}
	vector <vector <int>> e;
	vector <int> electro, connect;
	vector <pair <int, int>> emin(n + 1);
	vector <bool> used(n + 1);
	used[0] = true;
	for (auto x : g[0])
		emin[x.first] = { x.second, 0 };
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		int mn = -1;
		for (int j = 0; j <= n; ++j) {
			if (used[j]) continue;
			if (mn == -1 or emin[j].first < emin[mn].first)
				mn = j;
		}
		used[mn] = true;
		e.push_back({ mn, emin[mn].second });
		ans += emin[mn].first;
		for (auto x : g[mn]) {
			if (used[x.first]) continue;
			if (emin[x.first].first > x.second)
				emin[x.first] = { x.second, mn };
		}
	}
	for (auto x : e) {
		if (x[0] == n or x[1] == n)
			electro.push_back(x[0] ^ x[1] ^ n);
		else
			connect.push_back(x[0]), connect.push_back(x[1]);
	}
	cout << ans << '\n' << electro.size() << '\n';
	for (auto x : electro) cout << x + 1 << ' ';
	cout << '\n' << connect.size() / 2 << '\n';
	for (int i = 0; i < connect.size(); i += 2)
		cout << connect[i] + 1 << ' ' << connect[i + 1] + 1 << '\n';
	return 0;
}
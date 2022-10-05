#include <bits/stdc++.h>
typedef long long ll;
typedef long double ldb;
const int md = 998244353;
const ll inf = 3e18;
const int OO = 1;
using namespace std;

int gcd(int x, int y) {
	return !y ? x : gcd(y, x % y);
}

int n, m;
vector<ll> a;
vector<ll> v[500005];

void solve() {
	cin >> n >> m;
	a.resize(n);
	for (auto &i : a) cin >> i;
	int g;
	cin >> g;
	for (int i = 1, x; i < m; i++) {
		cin >> x;
		g = gcd(g, x);
	}
	for (int i = 0; i < g; i++) v[i].clear();
	for (int i = 0; i < n; i++)
		v[i % g].push_back(a[i]);
	ll best = -inf, ans;
	for (int i = 0; i < g; i++) {
		sort(v[i].begin(), v[i].end());
		for (auto &j : v[i]) j = -j;
		for (int j = 1; j < v[i].size(); j++)
			v[i][j] += v[i][j - 1];
	}
	// odd
	ans = 0;
	for (int i = 0; i < g; i++) {
		ll mx = 0;
		for (int j = 1; j < v[i].size(); j += 2)
			mx = max(mx, v[i][j]);
		ans += 2 * mx;
	}
	for (auto &i : a) ans += i;
	best = max(best, ans);

	// even
	ans = 0;
	for (int i = 0; i < g; i++) {
		ll mx = -inf;
		for (int j = 0; j < v[i].size(); j += 2)
			mx = max(mx, v[i][j]);
		ans += 2 * mx;
	}
	for (auto &i : a) ans += i;
	best = max(best, ans);
	
	cout << best << '\n';
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int tst = 1;
	cin >> tst;
	while (tst--) solve();
}
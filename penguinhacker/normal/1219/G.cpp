#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n, m;
vector<vector<int>> g;

void transpose() {
	vector<vector<int>> ng(m, vector<int>(n));
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			ng[j][i] = g[i][j];
	swap(g, ng);
	swap(n, m);
}

ll get_largest(vector<ll>& v, int k) {
	if (v.size() <= k)
		return accumulate(v.begin(), v.end(), 0ll);
	vector<ll> b(k);
	for (ll x : v)
		if (x > b[k - 1]) {
			b[k - 1] = x;
			for (int i = k - 2; ~i; --i)
				if (b[i] < b[i + 1])
					swap(b[i], b[i + 1]);
		}
	return accumulate(b.begin(), b.end(), 0ll);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	g.assign(n, vector<int>(m));
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			cin >> g[i][j];
	ll ans = 0;
	for (int rep = 0; rep < 2; ++rep) {
		vector<ll> sr(n), sc(m);
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j)
				sr[i] += g[i][j], sc[j] += g[i][j];
		ans = max(ans, get_largest(sc, 4));
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j)
				sc[j] -= g[i][j];
			ans = max(ans, sr[i] + get_largest(sc, 3));
			for (int j = 0; j < m; ++j)
				sc[j] += g[i][j];
		}
		transpose();
	}
	if (n > m)
		transpose();
	if (n >= 2 && m >= 2) {
		vector<ll> sr(n), sc(m);
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j)
				sr[i] += g[i][j], sc[j] += g[i][j];
		for (int i1 = 0; i1 < n; ++i1)
			for (int i2 = i1 + 1; i2 < n; ++i2) {
				for (int j = 0; j < m; ++j)
					sc[j] -= g[i1][j] + g[i2][j];
				ans = max(ans, sr[i1] + sr[i2] + get_largest(sc, 2));
				for (int j = 0; j < m; ++j)
					sc[j] += g[i1][j] + g[i2][j];
			}
	}
	cout << ans;
	return 0;
}
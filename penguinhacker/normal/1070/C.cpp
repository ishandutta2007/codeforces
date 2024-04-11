#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int MX = 1e6;
int n, m, k;
vector<ar<int, 2>> q[MX];
ll c[4 * MX], s[4 * MX];

void upd(int i, int x, int u = 1, int l = 1, int r = MX) {
	if (l > i || r < i)
		return;
	if (l == r) {
		c[u] += x;
		s[u] += (ll)l * x;
		return;
	}
	int mid = (l + r) / 2;
	upd(i, x, 2 * u, l, mid);
	upd(i, x, 2 * u + 1, mid + 1, r);
	c[u] = c[2 * u] + c[2 * u + 1];
	s[u] = s[2 * u] + s[2 * u + 1];
}

ll qry(int x, int u = 1, int l = 1, int r = MX) {
	//cout << x << " " << c[u] << " " << s[u] << "\n";
	if (c[u] <= x)
		return s[u];
	if (l == r)
		return (ll)x * l;
	int mid = (l + r) / 2;
	if (c[2 * u] >= x)
		return qry(x, 2 * u, l, mid);
	return s[2 * u] + qry(x - c[2 * u], 2 * u + 1, mid + 1, r);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> k >> m;
	for (int i = 0; i < m; ++i) {
		int l, r, c, p;
		cin >> l >> r >> c >> p, --l;
		q[l].push_back({p, c});
		if (r < n)
			q[r].push_back({p, -c});
	}
	ll ans = 0;
	for (int i = 0; i < n; ++i) {
		for (ar<int, 2> x : q[i])
			upd(x[0], x[1]);
		ans += qry(k);
		//cout << i << " " << qry(k) << "\n";
	}
	cout << ans;
	return 0;
}
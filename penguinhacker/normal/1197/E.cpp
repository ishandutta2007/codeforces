#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN = 200000, MOD = 1e9 + 7;
const ar<int, 2> ID = {MOD, 0};

int n;
ar<int, 2> a[mxN], dp[2 * mxN], seg[8 * mxN];
vector<int> d;

ar<int, 2> comb(ar<int, 2> x, ar<int, 2> y) {
	return x[0] ^ y[0] ? x[0] < y[0] ? x : y : ar<int, 2>{x[0], (x[1] + y[1]) % MOD};
}

void upd(int i, ar<int, 2> x, int u = 1, int l = 0, int r = d.size() - 1) {
	if (l > i || r < i)
		return;
	if (l == r) {
		seg[u] = comb(seg[u], x);
		return;
	}
	int mid = (l + r) / 2;
	upd(i, x, 2 * u, l, mid);
	upd(i, x, 2 * u + 1, mid + 1, r);
	seg[u] = comb(seg[2 * u], seg[2 * u + 1]);
}

ar<int, 2> qry(int ql, int qr, int u = 1, int l = 0, int r = d.size() - 1) {
	if (l > qr || r < ql)
		return ID;
	if (ql <= l && r <= qr)
		return seg[u];
	int mid = (l + r) / 2;
	return comb(qry(ql, qr, 2 * u, l, mid), qry(ql, qr, 2 * u + 1, mid + 1, r));
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	d.resize(2 * n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i][0] >> a[i][1];
		d[2 * i] = a[i][0];
		d[2 * i + 1] = a[i][1];
	}
	sort(d.begin(), d.end());
	d.resize(unique(d.begin(), d.end()) - d.begin());
	sort(a, a + n);
	fill(seg, seg + 4 * d.size(), ID);
	int mxin = 0;
	for (int i = 0; i < n; ++i) {
		mxin = max(mxin, a[i][1]);
		a[i][0] = lower_bound(d.begin(), d.end(), a[i][0]) - d.begin();
		a[i][1] = lower_bound(d.begin(), d.end(), a[i][1]) - d.begin();
		dp[i] = {d[a[i][1]], 1};
		ar<int, 2> q = qry(0, a[i][1]);
		dp[i] = comb(dp[i], {q[0] + d[a[i][1]], q[1]});
		upd(a[i][0], {dp[i][0] - d[a[i][0]], dp[i][1]});
		//cout << dp[i][0] << " " << dp[i][1] << "\n";
	}
	ar<int, 2> ans = ID;
	for (int i = 0; i < n; ++i)
		if (d[a[i][0]] > mxin)
			ans = comb(ans, dp[i]);
	cout << ans[1];
	return 0;
}
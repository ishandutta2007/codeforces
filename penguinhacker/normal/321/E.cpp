#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN = 4000, INF = 1e9;
int n, k, a[mxN][mxN], pre[mxN + 1][mxN + 1];

inline int Get(int l, int r) {
	return pre[r + 1][r + 1] - pre[l][r + 1] - pre[r + 1][l] + pre[l][l];
}

vector<int> dp, ndp;

void solve(int l, int r, int ql, int qr) {
	if (l > r)
		return;
	int mid = (l + r) / 2;
	pair<int, int> best = {INF, -1};
	for (int i = ql; i <= min(qr, mid); ++i)
		best = min(best, {dp[i] + Get(i + 1, mid), i});
	ndp[mid] = best.first;
	solve(l, mid - 1, ql, best.second);
	solve(mid + 1, r, best.second, qr);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> k;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j) {
			char x; cin >> x;
			a[i][j] = x - '0';
			pre[i + 1][j + 1] = a[i][j] + pre[i + 1][j] + pre[i][j + 1] - pre[i][j];
		}
	dp.resize(n), ndp.resize(n);
	for (int i = 0; i < n; ++i)
		dp[i] = Get(0, i);
	for (int i = 2; i <= k; ++i) {
		solve(0, n - 1, 0, n - 1);
		swap(dp, ndp);
	}
	cout << dp[n - 1] / 2;
	return 0;
}
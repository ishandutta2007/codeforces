#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=1e5;
const ll INF=1e18;
int n, k, a[mxN], cnt[mxN], cl=0, cr=0;
ll cur, dp[2][mxN];

void Get(int l, int r) {
	while(cl>l)
		cur+=cnt[a[--cl]]++;
	while(cr<=r)
		cur+=cnt[a[cr++]]++;
	while(cl<l)
		cur-=--cnt[a[cl++]];
	while(cr>r+1)
		cur-=--cnt[a[--cr]];
}

void solve(int l=0, int r=n-1, int lb=0, int rb=n-1) {
	if (l>r)
		return;
	int mid=(l+r)/2;
	ar<ll, 2> b={INF, -1};
	for (int i=min(mid, rb); i>=lb; --i) {
		Get(i, mid);
		b=min(b, {cur+(i?dp[0][i-1]:0), i});
	}
	dp[1][mid]=b[0];
	solve(l, mid-1, lb, b[1]);
	solve(mid+1, r, b[1], rb);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> k;
	for (int i=0; i<n; ++i)
		cin >> a[i], --a[i];
	memset(dp[0], 0x3f, sizeof(dp[0]));
	for (int i=0; i<k; ++i) {
		solve();
		memcpy(dp[0], dp[1], sizeof(dp[0]));
	}
	cout << dp[0][n-1];
	return 0;
}
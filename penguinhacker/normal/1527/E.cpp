#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define ar array
 
const int mxN=35000, INF=1e9;
int n, k, a[mxN], dp[2][mxN], cl, cr, cur;
deque<int> oc[mxN];
 
void Get(int l, int r) {
	while(cl>l) {
		int x=a[--cl];
		oc[x].push_front(cl);
		if (oc[x].size()>=2)
			cur+=oc[x][1]-oc[x][0];
	}
	while(cr<=r) {
		int x=a[cr++];
		oc[x].push_back(cr-1);
		if (oc[x].size()>=2)
			cur+=oc[x].back()-oc[x].end()[-2];
	}
	while(cl<l) {
		int x=a[cl++];
		if (oc[x].size()>=2)
			cur-=oc[x][1]-oc[x][0];
		oc[x].pop_front();
	}
	while(cr>r+1) {
		int x=a[--cr];
		if (oc[x].size()>=2)
			cur-=oc[x].back()-oc[x].end()[-2];
		oc[x].pop_back();
	}
}
 
void solve(int l=0, int r=n-1, int lb=0, int rb=n-1) {
	if (l>r)
		return;
	int mid=(l+r)/2;
	ar<int, 2> b={INF, -1};
	for (int i=lb; i<=min(mid, rb); ++i) {
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
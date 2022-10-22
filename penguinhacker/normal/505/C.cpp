#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mxN=30001;
int n, d, ans, a[mxN], dp[mxN][501];

void smax(int& i, int j) {
	if (j>i)
		i=j;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> d;
	for (int i=0; i<n; ++i) {
		int x;
		cin >> x, ++a[x];
	}
	memset(dp, 0xbf, sizeof(dp));
	dp[d][250]=a[d];
	for (int i=d; i<mxN; ++i) {
		for (int j=0; j<=500; ++j) {
			if (dp[i][j]<0)
				continue;
			ans=max(ans, dp[i][j]);
			int k=d+j-250;
			if (k>1&&i+k-1<mxN)
				smax(dp[i+k-1][j-1], dp[i][j]+a[i+k-1]);
			if (i+k<mxN)
				smax(dp[i+k][j], dp[i][j]+a[i+k]);
			if (i+k+1<mxN)
				smax(dp[i+k+1][j+1], dp[i][j]+a[i+k+1]);
		}
	}
	cout << ans;
	return 0;
}
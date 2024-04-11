#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=100;
int n, a[mxN], dp[mxN][mxN][mxN][2];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	if (n<=2) {
		cout << n-1;
		return 0;
	}
	for (int i=0; i<n; ++i)
		cin >> a[i], --a[i];
	memset(dp, 0x3f, sizeof(dp));
	if (~a[0]) {
		int c[2]={(n+1)/2, n/2};
		--c[a[0]%2];
		dp[0][c[0]][c[1]][a[0]%2]=0;
	} else {
		dp[0][(n+1)/2-1][n/2][0]=0;
		dp[0][(n+1)/2][n/2-1][1]=0;
	}
	for (int i=1; i<n; ++i) {
		for (int j=0; j<=n; ++j) {
			for (int k=0; k<=n; ++k) {
				if (j+k!=n-i-1)
					continue;
				if (~a[i]) {
					a[i]%=2;
					int c[2]={j, k};
					++c[a[i]];
					dp[i][j][k][a[i]]=min(dp[i-1][c[0]][c[1]][a[i]], dp[i-1][c[0]][c[1]][a[i]^1]+1);
				} else {
					dp[i][j][k][0]=min(dp[i-1][j+1][k][0], dp[i-1][j+1][k][1]+1);
					dp[i][j][k][1]=min(dp[i-1][j][k+1][0]+1, dp[i-1][j][k+1][1]);
				}
			}
		}
	}
	cout << min(dp[n-1][0][0][0], dp[n-1][0][0][1]);
	return 0;
}
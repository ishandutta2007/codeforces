#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=500, M=1e9+7;
int n, a[mxN];
ll dp[mxN][mxN];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i=0; i<n; ++i)
		cin >> a[i], --a[i];
	dp[0][0]=1;
	for (int i=1; i<n; ++i)
		dp[i][i]=dp[i-1][i]=1;
	for (int i=n-1; ~i; --i) {
		for (int j=i+2; j<n; ++j) {
			dp[i][j]=dp[i+1][j];
			for (int k=i+1; k<j; ++k)
				if (a[k+1]>a[i+1])
					dp[i][j]=(dp[i][j]+dp[i+1][k]*dp[k][j])%M;
		}
	}
	cout << dp[0][n-1];
	return 0;
}
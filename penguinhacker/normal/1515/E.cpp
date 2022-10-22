#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=401;
int n, M;
ll C[mxN][mxN], dp[mxN][mxN];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> M;
	dp[1][1]=1, dp[2][2]=2;
	C[0][0]=1;
	for (int i=1; i<mxN; ++i) {
		C[i][0]=1;
		for (int j=1; j<=i; ++j)
			C[i][j]=(C[i-1][j-1]+C[i-1][j])%M;
	}
	for (int i=3; i<=n; ++i) {
		dp[i][i]=2*dp[i-1][i-1]%M;
		for (int j=i/2+1; j<i; ++j)
			for (int k=1; k<=j; ++k)
				dp[i][j]=(dp[i][j]+dp[k][k]*dp[i-k-1][j-k]%M*C[j][k])%M;
	}
	int ans=0;
	for (int i=n/2+1; i<=n; ++i)
		ans=(ans+dp[n][i])%M;
	cout << ans;
	return 0;
}
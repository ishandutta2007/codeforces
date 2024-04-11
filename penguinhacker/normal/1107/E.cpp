#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const ll INF=1e18;
int n, a[101];
ll dp[100][100][101][2];
string s;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> s;
	for (int i=1; i<=n; ++i)
		cin >> a[i];
	for (int i=0; i<n; ++i)
		for (int j=i; j<n; ++j)
			for (int k=0; k<=n; ++k)
				dp[i][j][k][0]=dp[i][j][k][1]=-INF;
	for (int i=0; i<n; ++i) {
		dp[i][i][0][0]=dp[i][i][0][1]=a[1];
		dp[i][i][1][s[i]-'0']=0;
	}
	for (int l=n-1; ~l; --l)
		for (int r=l+1; r<n; ++r) {
			int c0=count(s.begin()+l, s.begin()+r+1, '0');
			for (int c=c0; ~c; --c) {
				for (int d=c+1; d<=c0; ++d)
					dp[l][r][c][0]=max(dp[l][r][c][0], dp[l][r][d][0]+a[d-c]);
				for (int i=l; i<r; ++i)
					for (int j=0; j<=c; ++j)
						dp[l][r][c][0]=max(dp[l][r][c][0], dp[l][i][j][0]+dp[i+1][r][c-j][0]);
			}
			int c1=r-l+1-c0;
			for (int c=c1; ~c; --c) {
				for (int d=c+1; d<=c1; ++d)
					dp[l][r][c][1]=max(dp[l][r][c][1], dp[l][r][d][1]+a[d-c]);
				for (int i=l; i<r; ++i)
					for (int j=0; j<=c; ++j)
						dp[l][r][c][1]=max(dp[l][r][c][1], dp[l][i][j][1]+dp[i+1][r][c-j][1]);
			}
			dp[l][r][0][0]=max(dp[l][r][0][0], dp[l][r][0][1]);
			dp[l][r][0][1]=max(dp[l][r][0][1], dp[l][r][0][0]);
		}
	cout << dp[0][n-1][0][0];
	return 0;
}
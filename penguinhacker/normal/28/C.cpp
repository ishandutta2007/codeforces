#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n, m, a[50];
double C[51][51], p[51][51], ip[51][51], dp[50][51][51];

int cl(int x, int y) {
	return (x+y-1)/y;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	C[0][0]=1;
	for (int i=1; i<=50; ++i)
		for (int j=0; j<=i; ++j)
			C[i][j]=C[i-1][j]+(j?C[i-1][j-1]:0);
	for (int i=1; i<=50; ++i) {
		p[i][0]=ip[i][0]=1;
		for (int j=1; j<=50; ++j) {
			p[i][j]=p[i][j-1]*i;
			ip[i][j]=ip[i][j-1]/i;
		}
	}
	p[0][0]=1;
	cin >> n >> m;
	for (int i=0; i<m; ++i)
		cin >> a[i];
	for (int i=0; i<=n; ++i)
		dp[0][i][cl(i, a[0])]+=C[n][i]*ip[m][n]*p[m-1][n-i];
	for (int i=0; i<m-1; ++i) {
		for (int j=0; j<=n; ++j) {
			for (int k=0; k<=j; ++k) {
				if (!dp[i][j][k])
					continue;
				for (int l=0; l+j<=n; ++l)
					dp[i+1][j+l][max(k, cl(l, a[i+1]))]+=dp[i][j][k]*C[n-j][l]*ip[m-i-1][n-j]*(i==m-2&&l+j==n?1:p[m-2-i][n-j-l]);
				//cout << i << " " << j << " " << k << " " << dp[1][1][1] << endl;
			}
		}
	}
	//cout << dp[0][0][0] << " " << dp[0][1][1] << " " << dp[n-1][n][n] << endl;
	double ans=0;
	for (int i=0; i<=n; ++i)
		ans+=dp[m-1][n][i]*i;
	cout << fixed << setprecision(9) << ans;
	return 0;
}
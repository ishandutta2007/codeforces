#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n, m;
string g[2000];
int val[2000][2000][4];
int dp[2000][2000][4];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i=0; i<n; ++i)
		cin >> g[i];
	for (int i=0; i<n; ++i) {
		val[i][0][0]=1;
		for (int j=1; j<m; ++j)
			val[i][j][0]=g[i][j]==g[i][j-1]?val[i][j-1][0]+1:1;
	}
	for (int i=0; i<n; ++i) {
		val[i][m-1][1]=1;
		for (int j=m-2; j>=0; --j)
			val[i][j][1]=g[i][j]==g[i][j+1]?val[i][j+1][1]+1:1;
	}
	for (int j=0; j<m; ++j) {
		val[0][j][2]=1;
		for (int i=1; i<n; ++i)
			val[i][j][2]=g[i][j]==g[i-1][j]?val[i-1][j][2]+1:1;
	}
	for (int j=0; j<m; ++j) {
		val[n-1][j][3]=1;
		for (int i=n-2; i>=0; --i)
			val[i][j][3]=g[i][j]==g[i+1][j]?val[i+1][j][3]+1:1;
	}

	for (int i=0; i<n; ++i) {
		dp[i][0][0]=1;
		for (int j=1; j<m; ++j)
			dp[i][j][0]=min(min(val[i][j][2], val[i][j][3]), dp[i][j-1][0]+1);
	}
	for (int i=0; i<n; ++i) {
		dp[i][m-1][1]=1;
		for (int j=m-2; j>=0; --j)
			dp[i][j][1]=min(min(val[i][j][2], val[i][j][3]), dp[i][j+1][1]+1);
	}
	for (int j=0; j<m; ++j) {
		dp[0][j][2]=1;
		for (int i=1; i<n; ++i)
			dp[i][j][2]=min(min(val[i][j][0], val[i][j][1]), dp[i-1][j][2]+1);
	}
	for (int j=0; j<m; ++j) {
		dp[n-1][j][3]=1;
		for (int i=n-2; i>=0; --i)
			dp[i][j][3]=min(min(val[i][j][0], val[i][j][1]), dp[i+1][j][3]+1);
	}

	/*for (int k=0; k<4; ++k) {
		for (int i=0; i<n; ++i) {
			for (int j=0; j<m; ++j)
				cout << dp[i][j][k] << ' ';
			cout << '\n';
		}
		cout << "\n\n";
	}*/

	ll ans=0;
	for (int i=0; i<n; ++i) {
		for (int j=0; j<m; ++j) {
			int MN=1e9;
			for (int k=0; k<4; ++k)
				MN=min(MN, dp[i][j][k]);
			ans+=MN;
		}
	}
	cout << ans;
	return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
*/
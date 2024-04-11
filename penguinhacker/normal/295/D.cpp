#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=2000, M=1e9+7;
int n, m;
ll dp[mxN][mxN];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i=1; i<m; ++i)
		dp[0][i]=1;
	for (int i=1; i<n; ++i) {
		ll sum=0, cur=0;
		for (int j=1; j<m; ++j) {
			sum=(sum+dp[i-1][j])%M;
			cur=(cur+sum)%M;
			dp[i][j]=cur;
		}
	}
	for (int i=1; i<n; ++i)
		for (int j=1; j<m; ++j)
			dp[i][j]=(dp[i][j]+dp[i-1][j])%M;
	ll ans=0;
	for (int i=0; i<n; ++i) {
		for (int j=1; j<m; ++j) {
			ll up=i?(dp[i][j]-dp[i-1][j]+M)%M:1;
			ll down=dp[n-i-1][j];
			ans=(ans+(m-j)*up%M*down)%M;
		}
	}
	cout << ans << "\n";
	return 0;
}
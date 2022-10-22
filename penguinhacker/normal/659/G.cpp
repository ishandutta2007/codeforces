#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=1e6, M=1e9+7;
int n, a[mxN], c[mxN];
ll ans, dp[mxN];

ll get(int i, int j) { // get sum(dp[i][k] for 0<=k<=j)
	//cout << "GET: " << i << " " << j << " " << a[i] << " " << c[i] << endl;
	if (c[i]==-1||j<c[i]) {
		//if (i==1) cout << "uh   " << dp[i] << " " << dp[i]*j%M << endl;
		return dp[i]*j%M;
	}
	return (dp[i]*(c[i]-1)+j-(c[i]-1)+M)%M;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i=0; i<n; ++i)
		cin >> a[i], --a[i];
	c[0]=-1, dp[0]=1, ans=a[0];
	for (int i=1; i<n; ++i) {
		if (a[i]<=a[i-1]) {
			c[i]=-1;
			dp[i]=(get(i-1, a[i])+1)%M;
		} else {
			c[i]=a[i-1]+1;
			dp[i]=(get(i-1, a[i-1])+1)%M;
		}
		//cout << a[i] << " " << c[i] << " " << dp[i] << endl;
		ans=(ans+get(i, a[i]))%M;
	}
	cout << ans;
	return 0;
}
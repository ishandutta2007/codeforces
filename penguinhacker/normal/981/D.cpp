#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n, k;
ll ans=0, a[50], ps[51];
ll get(int l, int r) {return ps[r+1]-ps[l];}

bool ok(int bit) {
	ll need=ans|(1ll<<bit);
	vector<vector<bool>> dp(n, vector<bool>(k, 0));
	for (int i=0; i<n; ++i)
		dp[i][0]=(get(0, i)&need)==need;
	for (int j=1; j<k; ++j)
		for (int i=0; i<n; ++i)
			for (int k=0; k<i; ++k)
				dp[i][j]=dp[i][j]|(dp[k][j-1]&&(get(k+1, i)&need)==need);
	return dp[n-1][k-1];
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;
	for (int i=0; i<n; ++i) {
		cin >> a[i];
		ps[i+1]=a[i]+ps[i];
	}
	for (int bit=55; ~bit; --bit)
		if (ok(bit)) ans|=1ll<<bit;
	cout << ans;
	return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
*/
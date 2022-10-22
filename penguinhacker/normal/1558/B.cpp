#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=4e6;
int n, m, dp[mxN+1], pref[mxN+1];

int qry(int l, int r) {
	return (pref[l]-(r>=n?0:pref[r+1])+m)%m;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	dp[n]=pref[n]=1;
	int sum=1;
	for (int i=n-1; i; --i) {
		dp[i]=sum;
		for (int j=2; i*j<=n; ++j)
			dp[i]=(dp[i]+qry(i*j, (i+1)*j-1))%m;
		sum=(sum+dp[i])%m;
		pref[i]=(dp[i]+pref[i+1])%m;
		//cout << dp[i] << endl;
	}
	cout << dp[1];
	return 0;
}
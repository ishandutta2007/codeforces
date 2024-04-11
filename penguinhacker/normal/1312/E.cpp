#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n, a[500], dp[500][500], dp2[500];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i=0; i<n; ++i) {
		cin >> a[i];
		for (int j=0; j<n; ++j)
			dp[i][j]=i==j?a[i]:-1;
	}
	for (int inc=1; inc<n; ++inc) for (int i=0; i+inc<n; ++i) {
		int j=i+inc;
		for (int k=i; k<j; ++k)
			if (dp[i][k]==dp[k+1][j]&&dp[i][k]!=-1) {
				dp[i][j]=dp[i][k]+1;
				break;
			}
	}
	memset(dp2, 0x3f, sizeof(dp2));
	for (int i=0; i<n; ++i) {
		if (dp[0][i]!=-1) {
			dp2[i]=1;
			continue;
		}
		for (int j=0; j<i; ++j)
			if (dp[j+1][i]!=-1)
				dp2[i]=min(dp2[i], dp2[j]+1);
	}
	cout << dp2[n-1];
	return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
*/
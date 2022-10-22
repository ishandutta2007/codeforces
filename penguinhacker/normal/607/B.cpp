#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n, a[500], dp[500][500];
bool isPal[500][500];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i=0; i<n; ++i)
		cin >> a[i], isPal[i][i]=1;
	for (int i=0; i<n-1; ++i)
		isPal[i][i+1]=a[i]==a[i+1];
	for (int j=2; j<n; ++j)
		for (int i=0; i+j<n; ++i)
			isPal[i][i+j]=isPal[i+1][i+j-1]&&a[i]==a[i+j];
	
	memset(dp, 0x3f, sizeof(dp));
	for (int k=0; k<n; ++k)
		for (int i=0; i+k<n; ++i) {
			if (isPal[i][i+k]) {
				dp[i][i+k]=1;
				continue;
			}
			for (int j=0; j<k; ++j)
				dp[i][i+k]=min(dp[i][i+k], dp[i][i+j]+dp[i+j+1][i+k]);
			if (a[i]==a[i+k])
				dp[i][i+k]=min(dp[i][i+k], dp[i+1][i+k-1]);
		}
	cout << dp[0][n-1];
	return 0;
}
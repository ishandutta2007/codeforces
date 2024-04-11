#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n, a[2000];
ll dp[2000][2000];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i=0; i<n; ++i)
		cin >> a[i], dp[i][i]=0;
	sort(a, a+n);
	for (int i=n-1; ~i; --i)
		for (int j=i+1; j<n; ++j)
			dp[i][j]=min(dp[i][j-1], dp[i+1][j])+a[j]-a[i];
	cout << dp[0][n-1];
	return 0;
}
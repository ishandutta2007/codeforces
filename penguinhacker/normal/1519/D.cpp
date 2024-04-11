#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n;
ll ans, a[5000], b[5000], c[5000], dp[5000][5000];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i=0; i<n; ++i)
		cin >> a[i], c[i]=a[n-i-1];
	for (int i=0; i<n; ++i)
		cin >> b[i];
	for (int i=0; i<n; ++i)
		ans+=a[i]*b[i];
	ll base=ans;
	for (int i=0; i+1<n; ++i) {
		dp[i][i+1]=a[i+1]*b[i]+a[i]*b[i+1]-a[i]*b[i]-a[i+1]*b[i+1];
		ans=max(ans, base+dp[i][i+1]);
	}
	for (int i=n-1; ~i; --i) {
		for (int j=i+2; j<n; ++j) {
			dp[i][j]=dp[i+1][j-1]+a[i]*b[j]+a[j]*b[i]-a[i]*b[i]-a[j]*b[j];
			ans=max(ans, base+dp[i][j]);
		}
	}
	cout << ans;
	return 0;
}
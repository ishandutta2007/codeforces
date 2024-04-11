#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=1e6;
int n;
ll r1, r2, r3, d, a[mxN], b[mxN], dp[mxN+1][2];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> r1 >> r2 >> r3 >> d;
	r1=min(r1, r3);
	for (int i=0; i<n; ++i) {
		ll x;
		cin >> x;
		a[i]=x*r1+r3; // dont need to come back
		b[i]=min((x+1)*r1, (ll)r2)+min(r1, r2); // need to come back
	}
	for (int i=0; i<n-1; ++i) {
		dp[i+1][1]=dp[i][0]+b[i]+d;
		dp[i+1][0]=min({dp[i][0]+a[i]+d, dp[i+1][1]+2*d, dp[i][1]+b[i]+3*d});
	}
	cout << min({dp[n-1][0]+a[n-1]+d, dp[n-1][0]+b[n-1]+3*d, dp[n-1][1]+a[n-1]+2*d, dp[n-1][1]+b[n-1]+3*d})-d;
	return 0;
}
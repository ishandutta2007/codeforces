#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=1e6;
int n, a[mxN], dp[1<<22];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i=0; i<n; ++i) {
		cin >> a[i];
		dp[a[i]]=a[i];
	}
	for (int i=1; i<1<<22; ++i)
		for (int j=0; j<22&&!dp[i]; ++j)
			if (i&1<<j&&dp[i^1<<j])
				dp[i]=dp[i^1<<j];
	for (int i=0; i<n; ++i) {
		int ans=dp[a[i]^(1<<22)-1];
		cout << (ans?ans:-1) << " ";
	}
	return 0;
}
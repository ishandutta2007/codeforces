#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=1e6, M=998244353;
int n;
ll dp[mxN+1], p[mxN+1];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i=1; i<=n; ++i)
		for (int j=i; j<=n; j+=i)
			++dp[j];
	dp[1]=p[1]=1;
	for (int i=2; i<=n; ++i) {
		dp[i]=(dp[i]+p[i-1])%M;
		p[i]=(p[i-1]+dp[i])%M;
	}
	cout << dp[n];
	return 0;
}
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=2e5, M=998244353;
int n, k, s;
ll ans[mxN+1], dp[mxN+1], dp2[mxN+1];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> k;
	dp[0]=1;
	for (; s+k<=n; s+=k++) {
		memset(dp2, 0, sizeof(dp2));
		for (int i=s+k; i<=n; ++i) {
			dp2[i]=(dp2[i-k]+dp[i-k])%M;
			ans[i]=(ans[i]+dp2[i])%M;
		}
		memcpy(dp, dp2, sizeof(dp));
	}
	for (int i=1; i<=n; ++i)
		cout << ans[i] << " ";
	return 0;
}
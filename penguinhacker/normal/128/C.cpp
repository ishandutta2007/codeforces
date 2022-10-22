#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array
const int MOD=1e9+7;

int solve(int n, int k) {
	vector<int> dp(n+1, 0), dpl;
	dp[n]=1;
	for (int i=0; i<k; ++i) {
		dpl=dp;
		fill(dp.begin(), dp.end(), 0);
		int add=0;
		for (int j=n-2-2*i; j>0; --j) {
			dp[j]=dp[j+1];
			add=(add+dpl[j+2])%MOD;
			dp[j]=(dp[j]+add)%MOD;
		}
	}
	ll res=accumulate(dp.begin(), dp.end(), 0ll)%MOD;
	return res;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m, k;
	cin >> n >> m >> k;
	ll x=solve(n, k);
	ll y=solve(m, k);
	cout << (x*y%MOD);
	return 0;
}
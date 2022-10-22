#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define arr array
const int MOD=1e9+7;

int n, k;
ll dp[2001][2001]; //last num, length of seq
set<int> factor[2001];

void findFactor() {
	for (int i=1; i<=n; ++i) {
		for (int j=1; j*j<=i; ++j) {
			if (i%j==0) {
				factor[i].insert(j);
				factor[i].insert(i/j);
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	memset(dp, 0, sizeof(dp));
	cin >> n >> k;
	findFactor();

	for (int i=1; i<=n; ++i)
		dp[i][1]=1;

	for (int i=2; i<=k; ++i) {
		for (int j=1; j<=n; ++j) {
			for (const int &f:factor[j])
				dp[j][i]+=dp[f][i-1];
			dp[j][i]%=MOD;
		}
	}
	
	ll ans=0;
	for (int i=1; i<=n; ++i)
		ans+=dp[i][k];
	cout << ans%MOD;
	return 0;
}
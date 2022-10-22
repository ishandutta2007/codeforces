#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int MOD=1e9+7;
int n, k, a, b;
vector<int> dp, dpl;

void add(int l, int r, int inc) {
	l=max(l, 0);
	dp[l]=(dp[l]+inc)%MOD;
	if (r+1<n) {
		dp[r+1]=(dp[r+1]-inc+MOD)%MOD;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> a >> b >> k, --a, --b;
	dp.resize(n);
	dp[a]=1;
	for (int i=0; i<k; ++i) {
		dpl=dp;
		fill(dp.begin(), dp.end(), 0);
		for (int j=0; j<n; ++j) {
			if (j==b) {
				continue;
			}
			int dist=abs(j-b)-1;
			add(j-dist, j+dist, dpl[j]);
		}
		for (int j=1; j<n; ++j) {
			dp[j]=(dp[j]+dp[j-1])%MOD;
		}
		for (int j=0; j<n; ++j) {
			if (j!=b) {
				dp[j]=(dp[j]-dpl[j]+MOD)%MOD;
			}
		}
	}
	int ans=accumulate(dp.begin(), dp.end(), 0ll)%MOD;
	cout << ans;
	return 0;
}
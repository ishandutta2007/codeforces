#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int MOD=1e9+7;
int r, g, h;
vector<int> dp, dpl;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> r >> g;
	for (int i=1; ; ++i) {
		if (i*(i+1)/2>r+g)
			break;
		h=i;
	}
	//dp.reserve(200001);
	//dpl.reserve(200001);
	dp={1};
	int ans=0;
	for (int i=1; i<=h; ++i) {
		dpl=dp;
		dp.assign(min(i*(i+1)/2, g)+1, 0);
		for (int j=0; j<dp.size(); ++j) {
			if (i*(i+1)/2-j>r) continue;
			if (j<dpl.size()) dp[j]+=dpl[j];
			if (j>=i) dp[j]+=dpl[j-i];
			if (dp[j]>=MOD) dp[j]-=MOD;
			if (i==h) ans=(ans+dp[j])%MOD;
		}
	}
	cout << ans;
	return 0;
}
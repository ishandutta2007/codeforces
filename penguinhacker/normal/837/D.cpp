#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n, k, p2[200], p5[200];
vector<vector<int>> dp;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;
	int sum2=0, sum5=0;
	for (int i=0; i<n; ++i) {
		ll x; cin >> x;
		while(x%2==0) p2[i]++, x/=2;
		while(x%5==0) p5[i]++, x/=5;
		sum2+=p2[i], sum5+=p5[i];
	}
	dp.assign(k+1, vector<int>(sum5+1, -1e9));
	dp[0][0]=0;
	for (int ind=0; ind<n; ++ind) {
		int a=p2[ind], b=p5[ind];
		for (int i=min(k, ind+1); i>=1; --i) {
			for (int j=sum5; j>=b; --j) {
				dp[i][j]=max(dp[i][j], dp[i-1][j-b]+a);
			}
		}
	}
	int ans=0;
	for (int i=0; i<=sum5; ++i) ans=max(ans, min(i, dp[k][i]));
	cout << ans;
	return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
*/
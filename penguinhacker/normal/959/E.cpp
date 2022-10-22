#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

ll n, ans=0, dp[45];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n, --n;
	dp[0]=1;
	for (int i=1; i<42; ++i)
		dp[i]=2*dp[i-1]+(1ll<<(i-1));
	for (int i=0; i<42; ++i)
		if ((n>>i)&1)
			ans+=dp[i];
	cout << ans;
	return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
*/
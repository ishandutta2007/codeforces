#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=1e6;
int n, k, l, p[mxN+1];
bool a[mxN];
string s;
ar<int, 2> dp[mxN+1];

int ck(int x) {
	for (int i=l; i<=n; ++i)
		dp[i]=max(dp[i-1], {dp[i-l][0]+(p[i]-p[i-l]-x), dp[i-l][1]+1});
	return dp[n][1];
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> k >> l >> s;
	for (int i=0; i<n; ++i)
		a[i]='a'<=s[i]&&s[i]<='z';
	int ans=69696969;
	for (int rep=0; rep<2; ++rep) {
		for (int i=0; i<n; ++i)
			p[i+1]=p[i]+a[i];
		int need=0;
		for (int i=0; i<n;) {
			if (!a[i]) {
				++i;
				continue;
			}
			i+=l;
			++need;
		}
		if (need<=k) {
			cout << 0;
			return 0;
		}
		int lb=1, rb=l;
		while(lb<rb) { // look for smallest cost such that #subarrays >= k
			int mid=(lb+rb+1)/2;
			if (ck(mid)>=k)
				lb=mid;
			else
				rb=mid-1;
		}
		assert(ck(lb)>=k);
		//cout << p[n] << " " << lb << " " << dp[n][0] << " " << dp[n][1] << endl;
		ans=min(ans, p[n]-(lb*k+dp[n][0]));
		for (int i=0; i<n; ++i)
			a[i]^=1;
	}
	cout << ans;
	return 0;
}
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n, k;
ll s;
bool dp[2][500];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	dp[0][0]=1;
	cin >> n >> k;
	for (int i=0; i<n; ++i) {
		int a, b;
		cin >> a >> b;
		s+=a+b;
		memset(dp[1], 0, sizeof(dp[1]));
		for (int x=0; x<=min(a, k-1); ++x) {
			int left=(a-x)%k;
			if (left&&left+b<k)
				continue;
			//cout << i << " " << x << "\n";
			//int y=(a+b-x)%k;
			for (int j=0; j<k; ++j)
				dp[1][(j+x)%k]|=dp[0][j];
		}
		memcpy(dp[0], dp[1], sizeof(dp[0]));
	}
	ll ans=0;
	for (int i=0; i<k; ++i) {
		if (!dp[0][i])
			continue;
		ll j=(s-i)%k;
		ans=max(ans, (s-i-j)/k);
	}
	cout << ans;
	return 0;
}
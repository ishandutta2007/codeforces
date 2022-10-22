#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=5000;
int n, a[mxN], b[mxN];
ll dp[mxN];

void solve() {
	cin >> n;
	for (int i=0; i<n; ++i)
		cin >> a[i];
	for (int i=0; i<n; ++i)
		cin >> b[i];
	memset(dp, 0, sizeof(dp));
	for (int i=1; i<n; ++i) {
		for (int j=i-1; ~j; --j) {
			if (a[i]==a[j])
				continue;
			ll di=dp[i], dj=dp[j], p=abs(b[i]-b[j]);
			dp[i]=max(dp[i], dj+p);
			dp[j]=max(dp[j], di+p);
		}
	}
	cout << *max_element(dp, dp+n) << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--)
		solve();
	return 0;
}
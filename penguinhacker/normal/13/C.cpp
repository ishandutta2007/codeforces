#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n, a[5000];
ll dp[5000], dpl[5000];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i=0; i<n; ++i) cin >> a[i];
	vector<int> d(a, a+n);
	sort(d.begin(), d.end());
	d.resize(unique(d.begin(), d.end())-d.begin());
	int m=d.size();
	for (int i=0; i<m; ++i) {
		dp[i]=abs(a[0]-d[i]);
		if (i) dp[i]=min(dp[i], dp[i-1]);
	}
	for (int i=1; i<n; ++i) {
		for (int j=0; j<m; ++j)
			dpl[j]=dp[j];
		for (int j=0; j<m; ++j) {
			dp[j]=abs(a[i]-d[j])+dpl[j];
			if (j) dp[j]=min(dp[j], dp[j-1]);
		}
	}
	cout << dp[m-1];
	return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
*/
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n, m, a[200000];
ll dp[200000];
ll ans=0;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i=0; i<n; ++i)
		cin >> a[i];
	sort(a, a+n);
	for (int i=0; i<m; ++i)
		dp[i]=a[i];
	for (int i=m; i<n; ++i)
		dp[i]=a[i]+dp[i-m];
	for (int i=0; i<n; ++i) {
		ans+=dp[i];
		cout << ans << ' ';
	}
	return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
*/
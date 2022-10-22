#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n, cnt[51];

void solve() {
	cin >> n;
	memset(cnt, 0, sizeof(cnt));
	for (int i=0; i<n; ++i) {
		int a; cin >> a;
		++cnt[a];
	}
	int ans=0;
	for (int sum=2; sum<=2*n; ++sum) {
		int cur=0;
		for (int i=1; 2*i<sum; ++i) {
			if (sum-i>n) continue;
			cur+=min(cnt[i], cnt[sum-i]);
		}
		if (sum%2==0)
			cur+=cnt[sum/2]/2;
		ans=max(ans, cur);
	}
	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t; cin >> t;
	while(t--) solve();
	return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
*/
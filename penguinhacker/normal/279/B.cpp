#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n, t, ans=0, a[100000];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> t;
	for (int i=0; i<n; ++i) cin >> a[i];
	for (int l=0, r=0, sum=0; r<n; ++r) {
		sum+=a[r];
		while(sum>t&&l<r) sum-=a[l++];
		if (sum<=t) ans=max(ans, r-l+1);
	}
	cout << ans;
	return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
*/
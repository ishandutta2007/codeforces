#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n, a[100000], best, mn, mx;

void solve() {
	cin >> n, best=0, mx=-1, mn=1e9;
	for (int i=0; i<n; ++i)
		cin >> a[i];
	for (int i=0; i<n; ++i) {
		if (a[i]==-1) continue;
		bool adj=0;
		if (i!=0) {
			int b=a[i-1];
			if (b==-1)
				adj=1;
			else
				best=max(best, abs(a[i]-b));
		}
		if (i!=n-1) {
			int b=a[i+1];
			if (b==-1)
				adj=1;
			else
				best=max(best, abs(a[i]-b));
		}
		if (adj) {
			mn=min(mn, a[i]);
			mx=max(mx, a[i]);
		}
	}
	int k=mx==-1?0:(mx+mn)/2;
	int ans=max(best, (mx-mn+1)/2);
	cout << ans << ' ' << k << '\n';
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

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
*/
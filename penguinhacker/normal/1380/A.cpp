#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n, a[1000], pre[1000], suf[1000];

void solve() {
	cin >> n;
	for (int i=0; i<n; ++i)
		cin >> a[i];
	pre[0]=0;
	for (int i=1; i<n; ++i)
		pre[i]=a[i]>a[pre[i-1]]?pre[i-1]:i;
	suf[n-1]=n-1;
	for (int i=n-2; ~i; --i)
		suf[i]=a[i]>a[suf[i+1]]?suf[i+1]:i;
	ar<int, 3> ans={-1,-1,-1};
	for (int i=1; i<n-1; ++i) {
		ar<int, 3> cur={pre[i-1], i, suf[i+1]};
		if (a[cur[0]]<a[i]&&a[i]>a[cur[2]]) {
			ans=cur;
			break;
		}
	}
	if (ans[0]==-1) {
		cout << "NO\n";
		return;
	}
	cout << "YES\n";
	cout << ans[0]+1 << ' ' << ans[1]+1 << ' ' << ans[2]+1 << '\n';
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
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n, a[50], b[50];
void solve() {
	cin >> n;
	for (int i=0; i<n; ++i)
		cin >> a[i];
	for (int i=0; i<n; ++i)
		cin >> b[i];
	int ma=1e9, mb=1e9;
	for (int i=0; i<n; ++i) {
		ma=min(ma, a[i]);
		mb=min(mb, b[i]);
	}
	ll ans=0;
	for (int i=0; i<n; ++i)
		ans+=max(a[i]-ma, b[i]-mb);
	cout << ans << '\n';
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
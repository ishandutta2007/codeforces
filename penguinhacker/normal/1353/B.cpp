#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n, k, a[30], b[30];

void solve() {
	cin >> n >> k;
	for (int i=0; i<n; ++i)
		cin >> a[i];
	for (int i=0; i<n; ++i)
		cin >> b[i];
	sort(a, a+n);
	sort(b, b+n, greater<int>());
	for (int i=0; i<k; ++i) {
		if (b[i]<=a[i])
			break;
		swap(a[i], b[i]);
	}
	int ans=0;
	for (int i=0; i<n; ++i)
		ans+=a[i];
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
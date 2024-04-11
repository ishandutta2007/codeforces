#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n, m, k, a[10000];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> k;
	for (int i=0; i<n; ++i)
		cin >> a[i];
	if (n%2==0) {
		cout << 0;
		return 0;
	}
	int x=(n+1)/2;
	ll ans=1ll*m/x*k;
	for (int i=0; i<n; i+=2)
		if (a[i]-ans<0)
			ans=a[i];
	cout << ans;
	return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
*/
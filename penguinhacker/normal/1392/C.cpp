#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n, a[200000];
void test_case() {
	cin >> n;
	for (int i=0; i<n; ++i)
		cin >> a[i];
	ll ans=0;
	for (int i=n-2; ~i; --i)
		if (a[i]>a[i+1])
			ans+=a[i]-a[i+1];
	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t=1;
	cin >> t;
	while(t--)
		test_case();
	return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
*/
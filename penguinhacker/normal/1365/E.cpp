#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n;
ll a[500], ans=0;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i=0; i<n; ++i)
		cin >> a[i];
	if (n<=3) {
		for (int i=0; i<n; ++i)
			ans|=a[i];
		cout << ans << '\n';
		return 0;
	}
	for (int i=0; i<n; ++i)
		for (int j=i+1; j<n; ++j)
			for (int k=j+1; k<n; ++k)
				ans=max(ans, (a[i]|a[j])|a[k]);
	cout << ans;
	return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
*/
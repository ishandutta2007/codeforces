#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n, a[300000];

void solve() {
	cin >> n;
	for (int i=0; i<n; ++i)
		cin >> a[i];
	cout << (a[0]<a[n-1]?"YES":"NO") << '\n';
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
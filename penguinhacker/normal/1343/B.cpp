#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n;

void solve() {
	cin >> n, n/=2;
	if (n&1) {
		cout << "NO\n";
		return;
	}
	cout << "YES\n";
	for (int i=1; i<=n; ++i)
		cout << 2*i << ' ';
	for (int i=1; i<n; ++i)
		cout << 2*i-1 << ' ';
	cout << 1ll*n*(n+1)-1ll*(n-1)*(n-1) << '\n';
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
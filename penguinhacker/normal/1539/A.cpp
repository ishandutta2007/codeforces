#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

void solve() {
	ll n, x, t;
	cin >> n >> x >> t;
	ll mx=t/x;
	if (mx>=n-1)
		cout << n*(n-1)/2 << "\n";
	else
		cout << mx*(mx-1)/2+(n-mx)*mx << "\n";
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
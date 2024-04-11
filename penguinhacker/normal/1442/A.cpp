#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n, a[30000];

void solve() {
	cin >> n;
	for (int i = 0; i < n; ++i) cin >> a[i];
	ll sum = 0;
	for (int i = 1; i < n; ++i) if (a[i] - a[i - 1] < 0) sum += a[i - 1] - a[i];
	cout << (a[0] >= sum ? "YES" : "NO") << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t; cin >> t;
	while(t--) solve();
	return 0;
}
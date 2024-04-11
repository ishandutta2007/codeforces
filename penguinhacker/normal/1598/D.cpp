#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

void solve() {
	int n;
	cin >> n;
	vector<int> a(n), b(n);
	map<int, ll> x, y;
	for (int i=0; i<n; ++i) {
		cin >> a[i] >> b[i];
		++x[a[i]], ++y[b[i]];
	}
	ll ans=0;
	for (int i=0; i<n; ++i)
		ans+=(x[a[i]]-1)*(y[b[i]]-1);
	cout << (ll)n*(n-1)*(n-2)/6-ans << "\n";
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
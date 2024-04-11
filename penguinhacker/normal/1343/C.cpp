#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n, a[200000];

void solve() {
	cin >> n;
	for (int i=0; i<n; ++i)
		cin >> a[i];
	ll ans=0;
	int curr=a[0];
	for (int i=1; i<n; ++i) {
		if ((a[i]>0)!=(a[i-1]>0)) {
			ans+=curr;
			curr=a[i];
		}
		else {
			curr=max(curr, a[i]);
		}
	}
	ans+=curr;
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
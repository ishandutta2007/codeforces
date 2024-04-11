#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int MOD=1e9+7;
int n, a[200000];

void solve() {
	cin >> n;
	for (int i=0; i<n; ++i)
		cin >> a[i];
	int mn=*min_element(a, a+n);
	int c=count(a, a+n, mn);
	for (int i=0; i<n; ++i)
		if ((a[i]&mn)^mn) {
			cout << "0\n";
			return;
		}
	ll ans=(ll)c*(c-1)%MOD;
	for (int i=1; i<=n-2; ++i)
		ans=ans*i%MOD;
	cout << ans << "\n";
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
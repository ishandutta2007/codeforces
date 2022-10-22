#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	const int M=1e9+7;
	while(t--) {
		ll n, k;
		cin >> n >> k;
		ll ans=1;
		for (int i=0; i<k; ++i)
			ans=ans*n%M;
		cout << ans << "\n";
	}
	return 0;
}
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--) {
		ll n;
		cin >> n;
		if (n%2050) {
			cout << "-1\n";
			continue;
		}
		int ans=0;
		for (n/=2050; n; n/=10)
			ans+=n%10;
		cout << ans << "\n";
	}
	return 0;
}
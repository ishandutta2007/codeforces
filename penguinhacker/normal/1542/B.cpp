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
		ll n, a, b;
		cin >> n >> a >> b;
		if (a==1) {
			cout << ((n-1)%b==0?"Yes":"No") << "\n";
		} else {
			bool ok=0;
			for (ll x=1; x<=n; x*=a)
				if ((n-x)%b==0) {
					ok=1;
					break;
				}
			cout << (ok?"Yes":"No") << "\n";
		}
	}
	return 0;
}
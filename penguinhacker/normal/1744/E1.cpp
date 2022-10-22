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
		ll a, b, c, d;
		cin >> a >> b >> c >> d;
		bool ok=0;
		for (int i=a+1; i<=c; ++i) {
			ll need=a*b/__gcd(a*b, (ll)i);
			//cout << need << endl;
			ll x=(b/need+1)*need;
			if (x<=d) {
				cout << i << " " << x << "\n";
				ok=1;
				break;
			}
		}
		if (!ok)
			cout << "-1 -1\n";
	}
	return 0;
}
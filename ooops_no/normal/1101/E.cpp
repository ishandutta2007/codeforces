#include<bits/stdc++.h>
#define ll long long 
using namespace std;
int  main() {
	ios_base::sync_with_stdio(0);
	ll maxs = 0;
	ll maxs1 = 0;
	ll x;
	cin >> x;
	for (int i = 0; i < x; i++) {
		char a;
		ll  b, c;
		cin >> a >> b >> c;
		if (a == '+') {
			maxs = max(maxs, max(b, c));
			maxs1 = max(maxs1, min(b, c));
		}
		else {
			if (max(c, b) >= maxs and min(c, b) >= maxs1)
				cout << "YES" << endl;
			else
				cout << "NO" << endl;
		}
	}
}
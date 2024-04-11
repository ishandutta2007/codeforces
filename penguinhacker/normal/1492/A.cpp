#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

ll n(ll p, ll x) {
	return (x - p % x) % x;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t; cin >> t;
	while(t--) {
		ll p, a, b, c; cin >> p >> a >> b >> c;
		cout << min({n(p, a), n(p, b), n(p, c)}) << "\n";
	}
	return 0;
}
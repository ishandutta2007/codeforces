#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	
	ll n, k;
	cin >> n >> k;
	
	if (k > 42) {cout << "No"; return 0;}
	
	ll ans = 1;
	for (ll i = 1; i <= k; i++) {
		ll c = __gcd(ans, i);
		ll s = i/c;
		ans *= s;
	}
	n++;
	if (n % ans == 0) {cout << "Yes"; return 0;}
	cout << "No";
	
	
	
	return 0;
}
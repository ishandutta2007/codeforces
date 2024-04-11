#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

bool checksq(ll n) {
	ll k = sqrt(n);
	return (k*k == n);
}

int main() {
	ios::sync_with_stdio(0);
	
	ll n;
	cin >> n;
	ll x;
	ll ans = -10000000;
	while (n--) {
		cin >> x;
		if (!checksq(x) && x > ans) {ans = x;}
	}
	cout << ans;
	
	
	return 0;
}
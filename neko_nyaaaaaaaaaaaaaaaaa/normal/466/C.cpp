#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	
	ll n;
	cin >> n; if (n < 3) {cout << 0; return 0;}
	
	vector<ll> a(n);
	vector<ll> s(n);
	ll sum = 0;
	for (ll i = 0; i < n; i++) {
		cin >> a[i];
		sum += a[i];
		s[i] = sum;
	}
	if (sum % 3) {cout << 0; return 0;}
	ll b1 = sum/3, b2 = 2*(sum/3);
	ll cnt2 = 0;
	for (ll i = 0; i < n-1; i++) {
		if (s[i] == b2) {cnt2++;}
	}
	ll ans = 0;
	for (ll i = 0; i < n-1; i++) {
		if (s[i] == b2) {cnt2--;}
		if (s[i] == b1) {ans += cnt2;}
	}
	cout << ans;
	
	return 0;
}
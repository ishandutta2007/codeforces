#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t; cin >> t;
	while(t--) {
		ll n; cin >> n;
		while(1) {
			ll sum = 0;
			ll x = n;
			while(x) {
				sum += x % 10;
				x /= 10;
			}
			if (__gcd(sum, n) > 1) {
				cout << n << "\n";
				break;
			}
			++n;
		}
	}
	return 0;
}
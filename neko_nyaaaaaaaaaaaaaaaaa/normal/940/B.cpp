#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	
	ll n, k, a, b;
	cin >> n >> k >> a >> b;
	if (n == 1) {cout << 0; return 0;}
	if (k == 1) {
		cout << a*(n-1);
		return 0;
	}
	ll ans = 0;
	while (n > 1) {
		if (n < k) {ans += (n-1)*a; break;}
		if (n % k) {ans += a*(n % k); n -= n%k; continue;} 
		ll cost = (n - n/k)*a;
		if (cost < b) {
			ans += cost;
		} else {
			ans += b;
		}
		n /= k;
	}
	cout << ans;
	
	return 0;
}
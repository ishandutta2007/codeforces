#include <bits/stdc++.h>
using namespace std;

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);

	// gcd of all divisors
	long long n; 
	while (cin >> n) {
		long long ans = 0;
		for (long long i = 2; i*i <= n; i++) {
			if (n % i == 0) {
				ans = __gcd(ans, i);
				ans = __gcd(ans, n/i);
			}
		}
		ans = __gcd(ans, n);
		cout << ans << '\n';
	}
	
	
	return 0;
}
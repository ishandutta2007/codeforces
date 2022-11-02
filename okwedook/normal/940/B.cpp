#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;

int main() {
	ll n, k, a, b;
	cin >> n >> k >> a >> b;
	ll ans = 0;
	if (k == 1) {
		cout << (n - 1) * a;
		return 0;
	}
	while (n > 1) {
		if (n % k == 0 && (n - n / k) * a > b) {
			ans += b;
			n /= k;
		} else {
			ll newn = max(1ll, n % k == 0 ? n / k : (n / k) * k);
			ans += (n - newn) * a;
			n = newn;
		}
	}
	cout << ans;
	//system("pause");
    return 0;
}
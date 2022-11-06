#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ll n, x = 0, y = 0;
	scanf("%lld", &n);
	ll a[n];
	for (ll i = 0; i < n; i++) scanf("%lld", &a[i]);
	sort(a, a + n, greater<ll>());
	for (ll i = 0; i < n / 2; i++) {
		x += a[i];
		y += a[n - i - 1];
	}
	if (n % 2 != 0) x += a[n / 2];
	printf("%lld\n", x * x + y * y);
}
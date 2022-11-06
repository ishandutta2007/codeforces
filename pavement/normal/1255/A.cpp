#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ll t, a, b;
	scanf("%lld", &t);
	while (t--) {
		scanf("%lld%lld", &a, &b);
		if (a > b) swap(a, b);
		b -= a, a = 0;
		ll u5 = b / 5;
		b -= u5 * 5;
		ll u2 = b / 2;
		b -= u2 * 2;
		printf("%lld\n", u5 + u2 + b);
	}
}
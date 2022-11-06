#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int m = 1000000007;

ll exp_mod(ll a, ll b) {
	ll result = 1;
	while (b) {
		if (b % 2 == 1) result *= a;
		a *= a;
		a %= m;
		result %= m;
		b >>= 1;
	}
	return result;
}

int main() {
	ll n, m, k;
	scanf("%lld%lld", &n, &m);
	k = exp_mod(2, m);
	k--;
	printf("%lld\n", exp_mod(k, n));
}
#pragma warning(disable:4996)

#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;


int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ll n, a, b, c;
	scanf("%I64d %I64d %I64d %I64d", &n, &a, &b, &c);
	if (a <= b - c) {
		printf("%I64d", n / a);
		return 0;
	}
	ll cnt = 0;
	if (n >= b) {
		ll k = (n - b) / (b - c) + 1;
		cnt += k;
		n -= k*(b - c);
	}
	cnt += (n / a);
	printf("%I64d", cnt);

}
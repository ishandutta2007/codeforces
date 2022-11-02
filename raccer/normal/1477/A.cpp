#include <bits/stdc++.h>
using namespace std;

long long a[200010];

long long gcd(long long a, long long b) {
	return !b ? a : gcd(b, a % b);
}

int main () {
	int T; scanf("%d", &T);
	while (T--) {
		int n; long long k;
		scanf("%d%I64d", &n, &k);
		int s1 = 0;
		for (int i = 0; i < n; i++) {
			scanf("%I64d", &a[i]);
		}
		sort(a, a + n);
		long long d = 0;
		for (int i = 1; i < n; i++) {
			d = gcd(d, a[i] - a[i - 1]);
		}
		long long be = (a[0] % d + d) % d;
		if ((k % d + d) % d != be) printf("NO\n");
		else printf("YES\n");
	}
	return 0;
}
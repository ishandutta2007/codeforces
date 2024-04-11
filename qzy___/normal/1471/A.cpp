#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;

int T, n, a[N], x;

int main() {
	for (scanf("%d", &T); T; T--) {
		scanf("%d%d", &n, &x);
		for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
		long long sum = 0;
		for (int i = 1; i <= n; i++) sum += a[i];
		long long t1 = 0, t2 = ceil(sum * 1.0 / x);
		for (int i = 1; i <= n; i++) t1 += ceil(a[i] * 1.0 / x);
		printf("%lld %lld\n", t2, t1);
	}
	return 0;
}
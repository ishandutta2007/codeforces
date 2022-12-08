#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;

int T, n, a[N], x;
long long c[N];

int main() {
	for (scanf("%d", &T); T; T--) {
		scanf("%d%d", &n, &x); long long ans = 0;
		for (int i = 1; i <= n; i++) scanf("%d", &a[i]), ans += a[i];
		for (int i = 1; i <= n; i++) c[i] = 1;
		while (true) {
			int flag = 0;
			for (int i = 1; i <= n; i++) {
				if (a[i] % x == 0)
					ans += c[i] * a[i], a[i] /= x, c[i] *= x;
				else {
					flag = 1;
					break;
				}
			}
			if (flag == 1) break;
		}
		printf("%lld\n", ans);
	}
	return 0;
}
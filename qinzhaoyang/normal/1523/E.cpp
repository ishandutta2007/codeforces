#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10, P = 1e9 + 7;

int Pow(int x, int y) {
	int r = 1;
	while (y) {
		if (y & 1) r = 1ll * r * x % P;
		x = 1ll * x * x % P, y >>= 1;
	}
	return r;
}

int T, n, k, p[N], v[N];

int C(int x, int y) {
	if (x < y || y < 0) return 0;
	return 1ll * p[x] * v[y] % P * v[x - y] % P;
}

int main() {
	p[0] = v[0] = 1;
	for (int i = 1; i <= 100000; i++) {
		p[i] = 1ll * p[i - 1] * i % P;
		v[i] = Pow(p[i], P - 2);
	}
	for (scanf("%d", &T); T; T--) {
		scanf("%d %d", &n, &k);
		int ans = 1;
		for (int i = 1; i <= n && n - (i - 1) * (k - 1) >= 0; i++) {
			ans += 1ll * C(n - (i - 1) * (k - 1), i) * Pow(C(n, i), P - 2) % P;
			ans %= P;
		}
		printf("%d\n", ans);
	}
	return 0;
}
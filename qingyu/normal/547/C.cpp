#pragma GCC optimize(2)
#include <bits/stdc++.h>

constexpr int N = 1000000;

typedef long long LL;

int pd[N + 3], prime[N + 3], mu[N + 3], n, q, a[N + 3], cnt[N + 3], mark[N + 3];

LL ans;
inline void init() {
	mu[1] = 1;
	for (int i = 2; i <= N; ++i) {
		if (!pd[i]) {
			prime[++prime[0]] = i;
			mu[i] = -1;
		}
		for (int j = 1; j <= prime[0]; ++j) {
			if (prime[j] * i > N) break;
			pd[prime[j] * i] = 1;
			if (!(i%prime[j])) {
				mu[i*prime[j]] = 0;
				break;
			}
			mu[i*prime[j]] = -mu[i];
		}
	}
}
void change(int x, int val) {
	for (int i = 1; i*i <= x; ++i)
		if (!(x%i)) {
			ans -= (LL)cnt[i] * (cnt[i] - 1) / 2 * mu[i]; cnt[i] += val;
			ans += (LL)cnt[i] * (cnt[i] - 1) / 2 * mu[i];
			if (i*i != x) {
				int j = x / i;
				ans -= (LL)cnt[j] * (cnt[j] - 1) / 2 * mu[j]; cnt[j] += val;
				ans += (LL)cnt[j] * (cnt[j] - 1) / 2 * mu[j];
			}
		}
}

inline char nc() {
    static char buf[1000000], *p1 = buf, *p2 = buf;
    return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1000000, stdin), p1 == p2) ? EOF : *p1++;
}

inline int read() {
    int res = 0;
    char ch = nc();
    while (!isdigit(ch)) ch = nc();
    while (isdigit(ch)) res = res * 10 + ch - 48, ch = nc();
    return res;
}

int main() {
	n = read(), q = read();
	init();
	for (int i = 1; i <= n; ++i) a[i] = read();
	for (int i = 1; i <= q; ++i) {
		int x = read();
		mark[x] ^= 1;
		change(a[x], mark[x] == 0 ? -1 : 1);
		printf("%lld\n", ans);
	}
}
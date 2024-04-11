#include <bits/stdc++.h>

typedef long long LL;

constexpr int mod = 1e9 + 7;
constexpr int maxn = 1e6 + 10;
LL sk[maxn], b[maxn], z[maxn];

void solve() {
	LL ans = 0;
	for (int i = 2; i <= maxn; i++) {
		LL v = 0;
		for (int j = i; j <= maxn; j += i)
			v += sk[j];
		if (!v) continue;
		ans += (v * z[i]) % mod * b[v - 1] % mod;
	}
	printf("%lld\n", (ans + mod) % mod);
}

inline void init() {
	b[0] = 1;
	for (int i = 1; i <= maxn; i++)
		b[i] = b[i - 1] * 2 % mod, z[i] = i;
	for (int i = 2; i <= maxn; i++)
		for (int j = i + i; j <= maxn; j += i)
			z[j] -= z[i];
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
    init();
	int n = read();
	memset(sk, 0, sizeof(sk));
	for (int i = 1, x; i <= n; ++i) {
		x = read();
		++sk[x];
	}
	solve();
}
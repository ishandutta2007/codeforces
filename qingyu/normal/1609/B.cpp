#include <bits/stdc++.h>

const int mod = 998244353;

inline int inc(int x, int y) { x += y - mod; return x + (x >> 31 & mod); }
inline int dec(int x, int y) { x -= y; return x + (x >> 31 & mod); }
inline int mul(int x, int y) { return 1ll * x * y % mod; }

inline void upd(int &x, int y) { x = inc(x, y); }
inline void dpu(int &x, int y) { x = dec(x, y); }
inline void pud(int &x, int y) { x = mul(x, y); }

inline int fastpow(int x, int p) {
	int r = 1;
	while (p) {
		if (p & 1) pud(r, x);
		pud(x, x);
		p >>= 1;
	}
	return r;
}

const int N = 1e6 + 50;
int n, q;
char s[N];
inline bool check(int i) {
	return s[i] == 'a' && s[i + 1] == 'b' && s[i + 2] == 'c';
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	scanf("%d%d%s", &n, &q, s + 1);
	int ans = 0;
	for (int i = 1; i + 2 <= n; ++i)
		ans += check(i);
	for (int i = 1; i <= q; ++i) {
		int p; char s[4];
		scanf("%d%s", &p, s);
		char ch = s[0];
		for (int i = std::max(1, p - 2); i + 2 <= n && i <= p + 2; ++i)
			ans -= check(i);
		::s[p] = ch;
		for (int i = std::max(1, p - 2); i + 2 <= n && i <= p + 2; ++i)
			ans += check(i);
		printf("%d\n", ans);
	}
	return 0;
}
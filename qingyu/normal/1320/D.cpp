#include <bits/stdc++.h>

const int mod1 = 1e9 + 15, mod2 = 998244353;
const int N = 2e5 + 50;

int32_t n, m, c[N];
char s[N];

struct Hash
{
	int32_t x, y;
	Hash() {}
	Hash(int32_t v) : x(v), y(v) {}
	Hash(int32_t x, int32_t y) : x(x), y(y) {}
} h1[N], h2[N], pow3[N];

inline int inc(int x, int y, int p) { x += y - p; return x + (x >> 31 & p); }
inline int dec(int x, int y, int p) { x -= y; return x + (x >> 31 & p); }
inline int mul(int x, int y, int p) { return 1ll * x * y % p; }

inline Hash operator+ (Hash A, Hash B) { return Hash(inc(A.x, B.x, mod1), inc(A.y, B.y, mod2)); }
inline Hash operator- (Hash A, Hash B) { return Hash(dec(A.x, B.x, mod1), dec(A.y, B.y, mod2)); }
inline Hash operator* (Hash A, Hash B) { return Hash(mul(A.x, B.x, mod1), mul(A.y, B.y, mod2)); }
inline Hash operator+ (Hash A, int32_t v) { return Hash(inc(A.x, v, mod1), inc(A.y, v, mod2)); }
inline Hash operator- (Hash A, int32_t v) { return Hash(dec(A.x, v, mod1), dec(A.y, v, mod2)); }
inline Hash operator* (Hash A, int32_t v) { return Hash(mul(A.x, v, mod1), mul(A.y, v, mod2)); }
inline bool operator==(Hash A, Hash B) { return A.x == B.x && A.y == B.y; }

inline Hash getHashValue(int l, int r)
{
	if (l & 1) return h1[r] - h1[l - 1] * pow3[c[r] - c[l - 1]];
	return h2[r] - h2[l - 1] * pow3[c[r] - c[l - 1]];
}

inline bool judge(int l1, int r1, int l2, int r2)
{
	return getHashValue(l1, r1) == getHashValue(l2, r2);
}

int main()
{
	scanf("%d%s%d", &n, s + 1, &m);
	pow3[0] = 1;
	for (int i = 1; i <= n; ++i)
	{
		pow3[i] = pow3[i - 1] * 3;
		if (s[i] -= 48) h1[i] = h1[i - 1], h2[i] = h2[i - 1], c[i] = c[i - 1];
		else h1[i] = h1[i - 1] * 3 + (i & 1) + 1, h2[i] = h2[i - 1] * 3 + ((i ^ 1) & 1) + 1, c[i] = c[i - 1] + 1;
	}
	for (int i = 1; i <= m; ++i)
	{
		int l1, l2, k;
		scanf("%d%d%d", &l1, &l2, &k);
		puts(judge(l1, l1 + k - 1, l2, l2 + k - 1) ? "Yes" : "No");
	}
	return 0;
}
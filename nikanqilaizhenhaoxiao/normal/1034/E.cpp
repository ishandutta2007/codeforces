#include <bits/stdc++.h>

#ifdef DEBUG
#define debug(...) fprintf(stderr, __VA_ARGS__)
#else
#define debug(...)
#endif

#ifdef __WIN32
#define LLFORMAT "I64"
#else
#define LLFORMAT "ll"
#endif

using namespace std;

const int maxn = 22, maxm = (1 << 21) | 10;
const long long T = 93824992236885ll, S = (1ll << 50) - 1;

int m, n, PC[maxm];
char s[maxm];
long long a[maxm], b[maxm];

inline long long sum(long long x, long long y) {
	return x ^ y ^ ((x & y & T) << 1);
}

inline void upd(long long &x, const long long &y) {
	x ^= y ^ ((x & y & T) << 1);
	return;
}

inline void g(long long *a) {
	scanf("%s", s);
	for (int i = 0; i < n; ++i) a[i] = ((long long) s[i] - '0') << PC[i];
	for (int hl = 1, l = 2; l <= n; hl = l, l <<= 1) for (int i = 0; i < n; i += l) for (int j = 0; j < hl; ++j) upd(a[i | j | hl], a[i | j]);
	return;
}

inline void mul(long long &x, const long long &y) {
	long long Y[4];
	Y[0] = 0;
	Y[1] = y;
	Y[2] = sum(y, y);
	Y[3] = sum(Y[2], y);
	long long z = 0; int foo;
	while(x) {
		if(foo = (x & 3)) upd(z, Y[foo]);
		(Y[1] <<= 2) &= S;
		(Y[2] <<= 2) &= S;
		(Y[3] <<= 2) &= S;
		x >>= 2;
	}
	x = z;
	return;
}

int main() {
	scanf("%d", &m); n = 1 << m;
	for (int i = 0; i < n; ++i) PC[i] = __builtin_popcount(i) << 1;
	g(a); g(b);
	for (int i = 0; i < n; ++i) mul(a[i], b[i]);
	for (int hl = 1, l = 2; l <= n; hl = l, l <<= 1) for (int i = 0; i < n; i += l) for (int j = 0; j < hl; ++j) upd(a[i | j | hl], sum(T, S ^ a[i | j]));
	for (int i = 0; i < n; ++i) s[i] = ((a[i] >> PC[i]) & 3) + '0';
	fwrite(s, n, 1, stdout);
	return 0;
}
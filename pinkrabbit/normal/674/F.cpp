#include <cstdio>

typedef unsigned ui;
const int MP = 135;

int N, P, Q;
ui C[MP], Ans;

inline ui gInv(ui b) {
	ui a = 1, e = 0x7fffffff;
	for (; e; e >>= 1, b *= b)
		if (e & 1) a *= b;
	return a;
}

inline void getCoef() {
	ui c1 = 1, c2 = 0;
	C[0] = 1;
	for (int i = 1; i <= P; ++i) {
		ui x = N - i + 1;
		ui y = i;
		ui x0 = __builtin_ctz(x);
		ui y0 = __builtin_ctz(y);
		c2 += x0 - y0;
		x >>= x0, y >>= y0;
		c1 *= x * gInv(y);
		if (c2 < 32) C[i] = c1 << c2;
	}
}

int main() {
	scanf("%d%d%d", &N, &P, &Q);
	if (P >= N) P = N - 1;
	getCoef();
	for (int i = 1; i <= Q; ++i) {
		ui now = 0;
		for (int j = P; j >= 0; --j)
			now = now * i + C[j];
		Ans ^= now * i;
	}
	printf("%u\n", Ans);
	return 0;
}
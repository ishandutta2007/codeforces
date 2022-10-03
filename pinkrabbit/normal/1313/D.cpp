#include <cstdio>
#include <cstring>
#include <algorithm>

const int MN = 200005, MS = 1 << 8;

inline void chkmx(int &x, int y) { x = x < y ? y : x; }

int N, A[MN], P[MN], B[MN], stk[9], tp;
int C[MS], f[MS], g[MS];

int main() {
	scanf("%d%*d%*d", &N), N *= 2;
	for (int i = 1; i <= N; ++i) scanf("%d", &A[i]), P[i] = i;
	std::sort(P + 1, P + N + 1, [](int i, int j) { return A[i] == A[j] ? (i & 1) > (j & 1) : A[i] < A[j]; });
	for (int S = 1; S < MS; ++S) C[S] = C[S & (S - 1)] ^ 1;
	memset(f, -1, sizeof f), f[0] = 0;
	for (int j = 0; j < 8; ++j) stk[++tp] = j;
	for (int ii = 1, T; ii < N; ++ii) {
		int i = P[ii], j = P[ii + 1], o = A[j] - (j & 1) - A[i] + (i & 1);
		memset(g, -1, sizeof g);
		if (i & 1) T = 1 << (B[i + 1] = stk[tp--]);
		else T = ~(1 << (stk[++tp] = B[i]));
		for (int S = 0; S < MS; ++S) if (~f[S]) {
			if (i & 1)
				chkmx(g[S], f[S] + C[S] * o),
				chkmx(g[S | T], f[S] + !C[S] * o);
			else chkmx(g[S & T], f[S] + C[S & T] * o);
		}
		std::swap(f, g);
	}
	printf("%d\n", std::max(f[0], f[1 << B[P[N]]]));
	return 0;
}
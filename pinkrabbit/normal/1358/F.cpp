#include <cstdio>
#include <algorithm>
#include <cstdlib>

typedef long long LL;
const int MN = 200005, MS = 10000005;

int N;
LL A[MN], B[MN];
LL Ans[MS]; int C;

inline void check() {
	int ok1 = 1, ok2 = 1;
	for (int i = 1; i <= N; ++i) {
		if (A[i] != B[i]) ok1 = 0;
		if (A[i] != B[N - i + 1]) ok2 = 0;
	}
	if (!ok1 && ok2) ok1 = 1, Ans[++C] = -1;
	if (ok1) {
		LL tot1 = 0, tot2 = 0;
		for (int i = 1; i <= C; ++i)
			tot1 += Ans[i] == -1 ? 1 : Ans[i],
			tot2 += Ans[i] == -1 ? 0 : Ans[i];
		if (tot2 > 200000) printf("BIG\n%lld\n", tot2);
		else {
			printf("SMALL\n%lld\n", tot1);
			for (int i = C; i >= 1; --i) {
				if (Ans[i] == -1) putchar('R');
				else {
					int x = Ans[i];
					while (x) putchar('P'), --x;
				}
			}
			putchar('\n');
		}
		exit(0);
	}
}

int main() {
	scanf("%d", &N);
	for (int i = 1; i <= N; ++i) scanf("%lld", &A[i]);
	for (int i = 1; i <= N; ++i) scanf("%lld", &B[i]);
	if (N == 1) {
		if (A[1] == B[1]) puts("SMALL\n0\n");
		else puts("IMPOSSIBLE");
		return 0;
	}
	if (N == 2) {
		if (B[1] == B[2]) return puts("IMPOSSIBLE"), 0;
		while (1) {
//			printf("(%lld, %lld)\n", B[1], B[2]);
			if (B[1] > B[2]) std::swap(B[1], B[2]), Ans[++C] = -1;
			if (A[1] == B[1]) {
				LL diff = B[2] - A[2];
				if (diff < 0 || diff % B[1] != 0) return puts("IMPOSSIBLE"), 0;
				Ans[++C] = diff / B[1];
				break;
			}
			if (A[2] == B[1]) {
				LL diff = B[2] - A[1];
				if (diff < 0 || diff % B[1] != 0) return puts("IMPOSSIBLE"), 0;
				Ans[++C] = diff / B[1];
				Ans[++C] = -1;
				break;
			}
			if (B[2] % B[1] == 0) return puts("IMPOSSIBLE"), 0;
			Ans[++C] = B[2] / B[1];
			B[2] %= B[1];
		}
		LL tot1 = 0, tot2 = 0;
		for (int i = 1; i <= C; ++i)
			tot1 += Ans[i] == -1 ? 1 : Ans[i],
			tot2 += Ans[i] == -1 ? 0 : Ans[i];
		if (tot2 > 200000) printf("BIG\n%lld\n\n", tot2);
		else {
			printf("SMALL\n%lld\n", tot1);
			for (int i = C; i >= 1; --i) {
				if (Ans[i] == -1) putchar('R');
				else {
					int x = Ans[i];
					while (x) putchar('P'), --x;
				}
			}
			putchar('\n');
		}
		return 0;
	}
	check();
	while (1) {
		if (B[1] == B[N]) return puts("IMPOSSIBLE"), 0;
		if (B[1] > B[N]) {
			std::reverse(B + 1, B + N + 1), Ans[++C] = -1;
		} else {
			int ok = 1;
			for (int i = 2; i <= N; ++i)
				if (B[i - 1] >= B[i]) ok = 0;
			if (!ok) return puts("IMPOSSIBLE"), 0;
			for (int i = N; i >= 2; --i)
				B[i] -= B[i - 1];
			Ans[++C] = 1;
		}
//		printf("\t\t\t"); for (int i = 1; i <= N; ++i) printf("%lld, ", B[i]); puts("");
		check();
	}
	return 0;
}
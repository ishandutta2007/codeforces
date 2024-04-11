#include <cstdio>

const int MN = 1005;

int N, K;
int A[MN];

inline int check() {
	int C = 0;
	for (int i = 1; i <= N; ++i)
		if (i % K != 1 % K) C += !A[i];
	if (C < K) return 0;
	printf("%d", K), C = K;
	for (int i = 1; i <= N && C; ++i)
		if (i % K != 1 % K && !A[i]) printf(" %d", i), A[i] = 1, --C;
	puts(""), fflush(stdout);
	scanf("%d", &C);
	for (int i = 1; i <= K; ++i)
		A[C] = 0, C = C % N + 1;
	return 1;
}

int main() {
	scanf("%d", &N), K = 1;
	for (int i = 2; i <= N; ++i)
		if (i + (N - 1) / i < K + (N - 1) / K)
			K = i;
	while (check()) ;
	puts("0");
	return 0;
}
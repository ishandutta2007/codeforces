#include <cstdio>

int N, A[50005];

int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &N);
		for (int i = 1; i <= N; ++i) scanf("%d", &A[i]);
		if (A[1] + A[2] > A[N]) puts("-1");
		else printf("1 2 %d\n", N);
	}
	return 0;
}
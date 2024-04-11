#include <cstdio>

const int MN = 1005;

int N, M;
int A[MN], T[MN], L[MN], R[MN];

int main() {
	scanf("%d%d", &N, &M);
	for (int i = 1; i <= M; ++i) {
		scanf("%d%d%d", &T[i], &L[i], &R[i]);
		if (T[i]) {
			for (int j = L[i]; j < R[i]; ++j)
				A[j] = 1;
		}
	}
	for (int i = 1; i <= M; ++i) {
		if (T[i]) continue;
		int ok = 0;
		for (int j = L[i]; j < R[i]; ++j)
			if (!A[j]) ok = 1;
		if (!ok) return puts("NO"), 0;
	}
	int K = N;
	printf("YES\n%d ", N);
	for (int i = 2; i <= N; ++i)
		printf("%d ", A[i - 1] ? K : --K);
	return 0;
}
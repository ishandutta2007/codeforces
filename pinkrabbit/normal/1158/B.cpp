#include <cstdio>

int N, K;

int main() {
	scanf("%d%d", &N, &K);
	K = (N - K) / 2 + 1;
	for (int i = 1; i <= N; ++i) printf("%c", "01"[i % K == 0]);
	return 0;
}
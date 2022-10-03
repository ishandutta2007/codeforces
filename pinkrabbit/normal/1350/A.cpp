#include <cstdio>

int N, K;

int main() {
	int Tests;
	scanf("%d", &Tests);
	while (Tests--) {
		scanf("%d%d", &N, &K);
		int x = N;
		for (int i = 2; i * i <= N; ++i)
			if (N % i == 0) { x = i; break; }
		if (x == 2) printf("%d\n", N + 2 * K);
		else printf("%d\n", N + x + 2 * (K - 1));
	}
	return 0;
}
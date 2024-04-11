#include <cstdio>

int N, M;

int main() {
	int Tests;
	scanf("%d", &Tests);
	while (Tests--) {
		scanf("%d%d", &N, &M);
		printf("%d\n", (N * M + 1) / 2);
	}
}
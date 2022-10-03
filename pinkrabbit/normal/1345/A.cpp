#include <cstdio>

int main() {
	int Tests;
	scanf("%d", &Tests);
	while (Tests--) {
		int N, M;
		scanf("%d%d", &N, &M);
		puts(N <= 1 || M <= 1 || N <= 4 / M ? "YES" : "NO");
	}
	return 0;
}
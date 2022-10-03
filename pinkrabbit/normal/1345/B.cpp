#include <cstdio>

int main() {
	int Tests;
	scanf("%d", &Tests);
	while (Tests--) {
		int N, x = 25819, Ans = 0;
		scanf("%d", &N);
		while (x >= 1) {
			while (x * (3 * x + 1) / 2 <= N)
				++Ans, N -= x * (3 * x + 1) / 2;
			--x;
		}
		printf("%d\n", Ans);
	}
	return 0;
}
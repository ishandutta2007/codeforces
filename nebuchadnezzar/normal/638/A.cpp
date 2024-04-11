#include <cstdio>

int main() {
	int n, a;
	scanf("%d%d", &n, &a);
	if (a % 2 == 0) {
		a = n + 1 - a;
	}
	printf("%d\n", (a + 1) / 2);
}
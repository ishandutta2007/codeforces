#include <cstdio>
#include <cmath>

int main() {
	int N;
	scanf("%d", &N);
	printf("%d\n", (N - 1) % 9 + 1);
	return 0;
}
#include <cstdio>

const int Z[6] = {4, 1, 3, 2, 0, 5};

int N, Ans;

int main() {
	scanf("%d", &N);
	for (int i = 0; i < 6; ++i) if (N >> i & 1) Ans |= 1 << Z[i];
	printf("%d\n", Ans);
	return 0;
}
#include <cstdio>
#include <cstring>
#include <algorithm>

int N;
int A[15];

int main() {
	scanf("%d", &N);
	for (int i = 1; i <= N; ++i) scanf("%d", &A[i]);
	printf("%d\n", 2 + (A[3] ^ *std::min_element(A + 1, A + N + 1)));
	return 0;
}
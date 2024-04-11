#include <cstdio>

int N, M, Ans;

int main() {
	scanf("%d%d", &N, &M);
	if (M % N) return puts("-1"), 0;
	M /= N;
	while (~M & 1) M >>= 1, ++Ans;
	while (!(M % 3)) M /= 3, ++Ans;
	if (M > 1) return puts("-1"), 0;
	printf("%d\n", Ans);
	return 0;
}
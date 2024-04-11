#include <cstdio>

int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		int N;
		scanf("%d", &N);
		for (int i = 1; i <= N; ++i)
			printf("%d%c", i + 1, " \n"[i == N]);
	}
	return 0;
}
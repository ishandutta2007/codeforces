#include <cstdio>
#include <algorithm>

int N, Ans;

inline int Ask(int j) {
	int c0 = 0, c1 = 0, x;
	for (int i = 0; i < N; ++i) ++(i >> j & 1 ? c1 : c0);
	printf("%d %d", c0, c1);
	for (int i = 0; i < N; ++i) if (~i >> j & 1) printf(" %d", i + 1);
	for (int i = 0; i < N; ++i) if ( i >> j & 1) printf(" %d", i + 1);
	printf("\n"), fflush(stdout);
	scanf("%d", &x);
	return x;
}

int main() {
	int T; scanf("%d", &T);
	while (T--) {
		scanf("%d", &N), Ans = 0;
		for (int j = 0; 1 << j < N; ++j)
			Ans = std::max(Ans, Ask(j));
		printf("-1 %d\n", Ans), fflush(stdout);
	}
	return 0;
}

// lg
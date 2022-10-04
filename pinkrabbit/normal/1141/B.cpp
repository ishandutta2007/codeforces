#include <cstdio>
#include <algorithm>

const int MN = 200005;

int N, A[MN], Cnt, Ans;

int main() {
	scanf("%d", &N);
	for (int i = 1; i <= N; ++i) scanf("%d", &A[i]);
	for (int i = 1; i <= N + N; ++i) {
		int j = (i - 1) % N + 1;
		if (A[j]) ++Cnt;
		else Ans = std::max(Ans, Cnt), Cnt = 0;
	} Ans = std::max(Ans, Cnt);
	printf("%d\n", Ans);
	return 0;
}

// lg
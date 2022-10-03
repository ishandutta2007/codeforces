#include <cstdio>
#include <algorithm>

typedef long long LL;
const int MN = 100005;

int N, M, A[MN], B[MN];

int main() {
	scanf("%d%d", &N, &M);
	for (int i = 1; i <= N; ++i) scanf("%d", &A[i]);
	for (int i = 1; i <= M; ++i) scanf("%d", &B[i]);
	int maxA = *std::max_element(A + 1, A + N + 1);
	int minB = *std::min_element(B + 1, B + M + 1);
	if (minB < maxA) return puts("-1"), 0;
	LL Ans = 0;
	for (int i = 1; i <= N; ++i) Ans += A[i];
	Ans *= M;
	if (maxA == minB) {
		for (int i = 1; i <= M; ++i) Ans += B[i] - maxA;
		printf("%lld\n", Ans);
	}
	else {
		std::nth_element(A + 1, A + N - 1, A + N + 1);
		int smaxA = A[N - 1];
		for (int i = 1; i <= M; ++i) Ans += B[i] - maxA;
		Ans += maxA - smaxA;
		printf("%lld\n", Ans);
	}
	return 0;
}
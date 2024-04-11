#include <cstdio>
#include <algorithm>

typedef long long LL;
const int MN = 200005;

int N, x;
LL A[MN], Min, Max;
int B[MN];

int main() {
	scanf("%d", &N);
	for (int i = 2; i <= N; ++i) scanf("%d", &x), A[i] = A[i - 1] + x;
	Min = Max = A[1];
	for (int i = 2; i <= N; ++i) Min = std::min(Min, A[i]), Max = std::max(Max, A[i]);
	if (Max - Min + 1 == N) {
		for (int i = 1; i <= N; ++i) A[i] -= Min - 1;
		for (int i = 1; i <= N; ++i) B[A[i]] = 1;
		for (int i = 1; i <= N; ++i) if (B[i] != 1) return puts("-1"), 0;
		for (int i = 1; i <= N; ++i) printf("%lld ", A[i]);
		puts("");
	} else puts("-1");
	return 0;
}
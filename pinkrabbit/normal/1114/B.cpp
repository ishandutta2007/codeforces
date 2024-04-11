#include <cstdio>
#include <algorithm>
// lg
typedef long long LL;

int N, M, K;
int A[200005], B[200005];
LL Ans = 0;

int main(){
	scanf("%d%d%d", &N, &M, &K);
	for (int i = 1; i <= N; ++i) {
		scanf("%d", &A[i]);
		B[i] = i;
	}
	std::sort(B + 1, B + N + 1, [](int i, int j) { return A[i] > A[j]; });
	std::sort(B + 1, B + M * K + 1);
	for (int i = 1; i <= M * K; ++i) Ans += A[B[i]];
	printf("%lld\n", Ans);
	for (int i = M; i < M * K; i += M) printf("%d ", B[i]);
	puts("");
	return 0;
}
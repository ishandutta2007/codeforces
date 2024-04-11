#include <cstdio>
#include <algorithm>

typedef long long LL;

const int MN = 200005;

int M, N, A[MN], B[MN], pA[MN], pB[MN];
LL pos[MN * 3], aim[MN], Ans[MN * 2];
int QwQ[MN];

int main() {
	scanf("%d%d", &M, &N);
	for (int i = 1; i <= N; ++i) scanf("%d", &A[i]), pA[i] = i;
	for (int i = 1; i <= N; ++i) scanf("%d", &B[i]), pB[i] = i;
	std::sort(pA + 1, pA + N + 1, [](int i, int j) { return A[i] < A[j]; });
	std::sort(pB + 1, pB + N + 1, [](int i, int j) { return B[i] < B[j]; });
	for (int i = 1; i <= N; ++i)
		pos[i] = A[pA[i]],
		pos[N + i] = M + A[pA[i]],
		pos[2 * N + i] = 2ll * M + A[pA[i]],
		aim[i] = M + B[pB[i]];
	int j = N;
	for (int i = 1; i <= N; ++i) {
		while (j <= N + N && pos[j] < aim[i]) ++j;
		Ans[1] += aim[i], Ans[j - i + 1] -= 2 * aim[i];
	}
	j = 0;
	for (int i = 1; i <= N; ++i) {
		while (j <= N && aim[j] <= pos[N + i]) ++j;
		Ans[1] -= pos[i], Ans[i + 1] += pos[i];
		Ans[N + i + 1] += pos[N + N + i];
		Ans[i + 1] -= pos[N + i], Ans[i + N - j + 2] += 2 * pos[N + i], Ans[N + i + 1] -= pos[N + i];
	}
	for (int i = 1; i <= N + N + 1; ++i) Ans[i] += Ans[i - 1];
	int p = std::min_element(Ans + 1, Ans + N + N + 2) - Ans;
	printf("%lld\n", Ans[p]);
	for (int i = 1; i <= N; ++i) QwQ[pA[(p + i - 2) % N + 1]] = pB[i];
	for (int i = 1; i <= N; ++i) printf("%d%c", QwQ[i], " \n"[i == N]);
	return 0;
}
#include <cstdio>
#include <algorithm>

int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		static const int MN = 100005;
		int N;
		static int A[MN], B[MN];
		scanf("%d", &N);
		for (int i = 1; i <= N; ++i)
			scanf("%d", &A[i]);
		for (int i = 1; i <= N; ++i)
			scanf("%d", &B[i]);
		static int C[MN];
		for (int i = 1; i <= N; ++i)
			C[i] = A[i];
		std::sort(C + 1, C + N + 1);
		for (int i = 1; i <= N; ++i)
			A[i] = (int)(std::lower_bound(C + 1, C + N + 1, A[i]) - C);
		for (int i = 1; i <= N; ++i)
			C[i] = B[i];
		std::sort(C + 1, C + N + 1);
		for (int i = 1; i <= N; ++i)
			B[i] = (int)(std::lower_bound(C + 1, C + N + 1, B[i]) - C);
//		for (int i = 1; i <= N; ++i)
//			printf("%d%c", A[i], " \n"[i == N]);
//		for (int i = 1; i <= N; ++i)
//			printf("%d%c", B[i], " \n"[i == N]);
		for (int i = 1; i <= N; ++i)
			C[A[i]] = B[i];
//		for (int i = 1; i <= N; ++i)
//			printf("%d%c", C[i], " \n"[i == N]);
		int mn = N + 1, ans = -1;
		for (int i = N; i >= 1; --i) {
			mn = std::min(mn, C[i]);
			if (mn == i) {
				ans = i;
				break;
			}
		}
		for (int i = 1; i <= N; ++i)
			printf("%d", A[i] >= ans);
		puts("");
	}
	return 0;
}
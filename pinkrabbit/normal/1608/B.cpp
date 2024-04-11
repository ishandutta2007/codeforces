#include <cstdio>
#include <algorithm>

int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		int N, A, B;
		scanf("%d%d%d", &N, &A, &B);
		if (std::abs(A - B) >= 2 || A + B >= N - 1) {
			puts("-1");
			continue;
		}
		int rev = 0;
		if (B > A)
			std::swap(B, A),
			rev = 1;
		static const int MN = 100005;
		static int p[MN];
		// A - 1 <= B <= A
		// A : maximum
		// B : minimum
		for (int i = 1; i <= N; ++i)
			p[i] = 0;
		for (int i = 1; i <= A; ++i)
			p[2 * i] = N - i + 1;
		for (int i = 1; i <= B + 1; ++i)
			p[2 * i - 1] = i;
		if (A == B) {
			for (int i = B + 2; i <= N - A; ++i)
				p[A + i] = i;
		} else {
			for (int i = B + 2; i <= N - A; ++i)
				p[N + B + 2 - i] = i;
		}
		for (int i = 1; i <= N; ++i)
			printf("%d%c", rev ? N - p[i] + 1 : p[i], " \n"[i == N]);
	}
	return 0;
}

// 1 9 2 8 3 7 4 6 5
// A = B = 2
// 1 9 2 8 3 4 5 6 7
// A = 3, B = 2
// 1 9 2 8 3 7 6 5 4
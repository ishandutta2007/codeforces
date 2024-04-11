#include <cstdio>

const int MN = 100005;

int N, A[MN], f[MN], Ans;

int main() {
	int Tests;
	scanf("%d", &Tests);
	while (Tests--) {
		scanf("%d", &N);
		for (int i = 1; i <= N; ++i) scanf("%d", &A[i]), f[i] = 1;
		Ans = 1;
		for (int i = 1; i <= N; ++i) {
			Ans = Ans < f[i] ? f[i] : Ans;
			for (int j = i + i; j <= N; j += i)
				if (A[i] < A[j]) f[j] = f[j] < f[i] + 1 ? f[i] + 1 : f[j];
		}
		printf("%d\n", Ans);
	}
	return 0;
}
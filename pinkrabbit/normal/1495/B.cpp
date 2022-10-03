#include <cstdio>

const int MN = 100005;

int N, A[MN], B[MN];

int main() {
	scanf("%d", &N);
	for (int i = 1; i <= N; ++i) scanf("%d", &A[i]);
	int t = 1;
	for (int i = 2; i <= N - 1; ++i) {
		if ((A[i + 1] > A[i]) == (A[i] > A[i - 1])) ++t;
		else ++B[t], t = 1;
	}
	++B[t];
	int mx = N - 1;
	while (!B[mx]) --mx;
//	for (int i = 1; i <= N - 1; ++i) printf("%d%s", B[i], i == N - 1 ? "\n" : ", ");
	int Ans = 0;
	for (int i = 2; i <= N - 1; ++i) if (A[i] > A[i - 1] && A[i] > A[i + 1]) {
		int lp = i - 1, rp = i + 1;
		while (lp > 1 && A[lp - 1] < A[lp]) --lp;
		while (rp < N && A[rp + 1] < A[rp]) ++rp;
		int l = i - lp, r = rp - i;
//		printf("(%d, %d)\n", l, r);
		if (l != r || (l & 1)) continue;
		if (l == mx && B[l] == 2) ++Ans;
	}
	printf("%d\n", Ans);
	return 0;
}
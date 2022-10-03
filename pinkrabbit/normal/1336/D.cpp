#include <cstdio>

const int MN = 105;

int N, lstv1, lstv2, v1, v2;
int dv1[MN], dv2[MN], Tag[MN], Ans[MN];

int main() {
	scanf("%d", &N);
	scanf("%d%d", &lstv1, &lstv2);
	for (int i = 1; i < N; ++i) {
		printf("+ %d\n", i), fflush(stdout);
		scanf("%d%d", &v1, &v2);
		dv1[i] = v1 - lstv1, dv2[i] = v2 - lstv2;
		if (dv1[i] > 0)
			for (int x = 2; x <= N; ++x)
				if (x * (x - 1) / 2 == dv1[i]) {
					Tag[i] = x; break;
				}
		lstv1 = v1, lstv2 = v2;
	}
	printf("+ 1\n"), fflush(stdout);
	scanf("%d%d", &v1, &v2);
	int ndv1 = v1 - lstv1, ndv2 = v2 - lstv2;
	for (int x = 0; x <= N; ++x)
		if (x * (x + 1) / 2 == ndv1) {
			Ans[1] = x; break;
		}
	int delta = ndv2 - dv2[1] - 1; // delta = a[2] + a[3]
	if (Tag[2] >= 2) Ans[2] = Tag[2], Ans[3] = delta - Ans[2];
	else if (Tag[3] >= 2) Ans[3] = Tag[3], Ans[2] = delta - Ans[3];
	else if (delta == 0) Ans[3] = Ans[2] = 0;
	else if (delta == 2) Ans[3] = Ans[2] = 1;
	else if (dv2[2] > 0) Ans[2] = 0, Ans[3] = 1;
	else Ans[2] = 1, Ans[3] = 0;
	for (int i = 3; i <= N - 2; ++i) {
		if (Tag[i + 1] >= 2) {
			Ans[i + 1] = Tag[i + 1];
			continue;
		}
		if ((Ans[i - 2] + 1) * (Ans[i - 1] + 1) == dv2[i]) Ans[i + 1] = 0;
		else Ans[i + 1] = 1;
	}
	Ans[N] = (dv2[N - 1] - (Ans[N - 3] + 1) * (Ans[N - 2] + 1)) / (Ans[N - 2] + 1);
	printf("!");
	for (int i = 1; i <= N; ++i) printf(" %d", Ans[i]);
	puts(""), fflush(stdout);
	return 0;
}
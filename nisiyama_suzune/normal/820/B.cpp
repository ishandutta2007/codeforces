#include <bits/stdc++.h>

int main () {
	int N, A;
	scanf ("%d%d", &N, &A);
	int ans = 3;
	double an = 360. / N / 2.;
	for (int i = 4; i <= N; ++i) {
		if (fabs (A - (i - 2) * an) < fabs (A - (ans - 2) * an))
			ans = i;
	}
	printf ("2 1 %d\n", ans);
}
#include <bits/stdc++.h>

int main () {
	int A, B;
	scanf ("%d%d", &A, &B);
	int L = std::min (A, B);
	int ans = 1;
	for (int i = 1; i <= L; ++i) ans *= i;
	printf ("%d\n", ans);
	return 0;
}
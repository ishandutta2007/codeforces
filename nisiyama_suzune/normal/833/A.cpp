#include <bits/stdc++.h>

int main () {
	int T;
	scanf ("%d", &T);
	for (int t = 0; t < T; ++t) {
		int A, B;
		scanf ("%d%d", &A, &B);
		int d = round (pow (1LL * A * B, 1. / 3.));
		if (1LL * d * d * d == 1LL * A * B && A % d == 0 && B % d == 0)
			puts ("Yes");
		else
			puts ("No");
	}
}
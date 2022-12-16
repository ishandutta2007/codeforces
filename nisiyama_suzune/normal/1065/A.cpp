#include <bits/stdc++.h>

int main () {
	int T; scanf ("%d", &T); while (T--) {
		long long S, A, B, C;
		scanf ("%lld%lld%lld%lld", &S, &A, &B, &C);
		printf ("%lld\n", S / C + S / C / A * B);
	}
}
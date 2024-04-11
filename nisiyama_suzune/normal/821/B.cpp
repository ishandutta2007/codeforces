#include <bits/stdc++.h>

#ifdef WIN32
	#define LL "%I64d"
#else
	#define LL "%lld"
#endif

int main () {
	long long M, B;
	scanf (LL LL, &M, &B);
	long long ans = 0;
	for (long long i = B; i >= 0; --i) {
		long long x = (B - i) * M;
		if (ans < x * (x + 1) / 2 * (i + 1) + i * (i + 1) / 2 * (x + 1)) ans = x * (x + 1) / 2 * (i + 1) + i * (i + 1) / 2 * (x + 1);
	}
	printf (LL "\n", ans);
}
#include <bits/stdc++.h>

int main () {
	long long N, M;
	scanf ("%lld%lld", &N, &M);
	printf ("%lld ", std::max (0ll, N - M * 2));
	long long l = 0, r = N, ans;
	while (l <= r) {
		long long m = (l + r) / 2;
		if (m * (m - 1) / 2 >= M) {
			ans = m; r = m - 1;
		} else l = m + 1;
	}
	printf ("%lld\n", N - ans);
}
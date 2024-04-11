#include <bits/stdc++.h>
using namespace std;

int cnt[35];

int main () {
	int T; scanf("%d", &T);
	while (T--) {
		int d, mod; scanf("%d%d", &d, &mod);
		int n = 0;
		while ((1 << n) <= d) n++;
		n--;
		int last = d;
		long long ans = 1;
		for (int i = 0; i <= n; i++) {
			cnt[i] = min(1 << i, last);
			last -= cnt[i];
			ans = ans * (cnt[i] + 1) % mod;
		}
		printf("%lld\n", (ans - 1 + mod) % mod);
	}
	return 0;
}
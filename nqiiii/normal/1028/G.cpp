#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll f[6][10010], b = 1;
int main() {
	for (int i = 1; i <= 5; ++i)
		for (int j = 1; j <= (i == 5 ? 1 : 10000); ++j) {
			ll now = f[i - 1][j];
			for (int k = 1; k <= j; ++k) now += f[i - 1][min(now + j + 1, 10000ll)] + 1;
			f[i][j] = now;
		}
	for (int i = 5, d; i >= 1; --i) {	
		ll now = 0; printf("%lld ", min(b, 10000ll));
		for (int j = 1; j <= min(b, 10000ll); ++j) {
			now += f[i - 1][min(b + now, 10000ll)];
			printf("%lld ", b + now); ++now;
		}
		printf("\n"); fflush(stdout);
		scanf("%d", &d);
		if (d == -1) break;
		else {
			now = 0;
			for (int j = 1; j <= d; ++j) now += f[i - 1][min(b + now, 10000ll)] + 1;
			b += now;
		}
	}
}
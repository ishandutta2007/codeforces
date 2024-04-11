#include <bits/stdc++.h>
using namespace std;
typedef long long Long;
int n;
Long ans[100010], now;
stack<Long> g[70];

int Bit(Long v) {
	return v ? Bit(v >> 1) + 1 : -1;
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		Long x; scanf("%lld", &x);
		g[Bit(x)].push(x);
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 0; ; ++j) {
			if (j == 61) {
				printf("No"); return 0;
			} else if (!(now >> j & 1) && !g[j].empty()) {
				ans[i] = g[j].top(); g[j].pop();
				now ^= ans[i]; break;
			}
		}
	}
	printf("Yes\n");
	for (int i = 1; i <= n; ++i) printf("%lld ", ans[i]);
}
#include <bits/stdc++.h>
using namespace std;
int main () {
	int n; scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int x, y; scanf("%d%d", &x, &y);
		int cnt = y / x;
		printf("%lld\n", 1ll * cnt * cnt * (x - y % x) + 1ll * (cnt + 1) * (cnt + 1) * (y % x));
	}
	return 0;
}
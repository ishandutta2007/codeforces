#include <cstdio>

void solve() {
	int n;
	scanf("%d", &n);
	int h = 1;
	while (h <= n) h *= 2;
	h--;
	printf("%lld\n", (long long) n * (n + 1) / 2 - 2 * h);
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) solve();
}
#pragma gcc optmize("Ofast")
#include <bits/stdc++.h>

const int MAXN = 100 + 1, MINX = 1, MAXX = 100;
int a[MAXN], n, d, ans, del;

int main() {
	scanf("%d%d", &n, &d);
	for (register int i = 1; i <= n; ++i)
		scanf("%d", a + i);
	std::sort(a + 1, a + n + 1);
    ans = n;
	for (register int i = 0; i - 100; ++i) {
		del = 0;
		for (register int j = 1; j - n - 1; j++)
			if (a[j] < i || a[j] > i + d)
				++del;
		ans = std::min(ans, del);
	}
	printf("%d", ans);
	return 0;
}
#include <bits/stdc++.h>
long long n, m, i, p;

int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		scanf("%lld%lld", &n, &m);
		p = m - (m & 3);
		for (i = p + 1; i <= m; i++)
			if (n & 1)
				n += i;
			else
				n -= i;
		printf("%lld\n", n);
	}
}
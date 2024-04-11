#include <stdio.h>
int n, m, c, p, a[1001];
int main() {
	register int i;
	scanf("%d%d%d", &n, &m, &c);
	while(m--) {
		scanf("%d", &p);
		if(p <= c / 2) {
			for(i = 1; i <= n; ++i) if(a[i] > p || !a[i]) break;
			a[i] = p;
			printf("%d\n", i);
			fflush(stdout);
		} else {
			for(i = n; i >= 1; --i) if(a[i] < p || !a[i]) break;
			a[i] = p;
			printf("%d\n", i);
			fflush(stdout);
		}
		register bool ok = 1;
		for(i = 1; i <= n && ok; ++i) ok &= a[i];
		for(i = 2; i <= n && ok; ++i) ok &= a[i] > a[i-1];
		if(ok) return 0;
	}
	return 0;
}
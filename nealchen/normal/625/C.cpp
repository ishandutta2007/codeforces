#include <stdio.h>
int n, k, i, j, l, tb[501][501];
int main() {
	scanf("%d%d", &n, &k);
	l = 0;
	for(i = 1; i <= n; ++i) for(j = 1; j < k; ++j) tb[i][j] = ++l;
	for(i = 1; i <= n; ++i) for(j = k; j <= n; ++j) tb[i][j] = ++l;
	l = 0;
	for(i = 1; i <= n; ++i) l += tb[i][k];
	printf("%d\n", l);
	for(i = 1; i <= n; ++i) {
		for(j = 1; j <= n; ++j) printf("%d ", tb[i][j]);
		puts("");
	}
	return 0;
}
#include <algorithm>
#include <stdio.h>
#include <string.h>
int n, k, s[100], t;
char st[102];
int main() {
	int i, j;
	scanf("%d%d", &n, &k);
	for(i = 0; i < n; ++i) scanf("%s", st), s[i] = strlen(st);
	scanf("%s", st);
	t = strlen(st);
	std::sort(s, s + n);
	i = std::lower_bound(s, s + n, t) - s + 1;
	j = std::upper_bound(s, s + n, t) - s;
	printf("%d %d\n", i + (i - 1) / k * 5, j + (j - 1) / k * 5);
	return 0;
}
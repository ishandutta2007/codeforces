#include <stdio.h>
int main() {
	int n, m, z, ans = 0;
	scanf("%d%d%d", &n, &m, &z);
	for(int i = 1; i <= z; ++i) ans += i % n == 0 && i % m == 0;
	printf("%d", ans);
	return 0;
}
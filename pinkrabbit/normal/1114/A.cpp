#include <cstdio>
// lg
int main() {
	int x, y, z, a, b, c;
	scanf("%d%d%d%d%d%d", &x, &y, &z, &a, &b, &c);
	if (a < x || a + b < x + y || a + b + c < x + y + z) puts("NO");
	else puts("YES");
	return 0;
}
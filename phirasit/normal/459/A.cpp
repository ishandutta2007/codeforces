#include <stdio.h>

int main() {
	int a, b, x, y;
	scanf("%d%d%d%d", &a, &b, &x, &y);
	if(b == y) {
		int s = a-x;
		printf("%d %d %d %d\n", a, b+s, x, y+s);
	}else if(a == x) {
		int s = b-y;
		printf("%d %d %d %d\n", a+s, b, x+s, y);
	}else if(b-y == a-x || y-b == a-x) {
		printf("%d %d %d %d\n", a, y, x, b);
	}else {
		printf("-1\n");
	}
	return 0;
}
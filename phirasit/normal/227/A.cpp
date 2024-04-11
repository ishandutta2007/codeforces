#include <stdio.h>

long long x1, y1;
long long x2, y2;
long long x3, y3;

int main() {
	scanf("%I64d%I64d%I64d%I64d%I64d%I64d", &x1, &y1, &x2, &y2, &x3, &y3);
	long long r = (x3 - x1) * (y2 - y1) - (y3 - y1) * (x2 - x1);
	if(r > 0) {
		printf("RIGHT\n");
	}else if(r < 0) {
		printf("LEFT\n");
	}else {
		printf("TOWARDS\n");
	}
	return 0;
}
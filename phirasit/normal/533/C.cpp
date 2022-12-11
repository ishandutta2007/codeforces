#include <stdio.h>

int main() {
	int x1, x2, y1, y2;
	scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
	if(x1+y1 <= x2 || x1+y1 <= y2) {
		printf("Polycarp");
	}else if(x1 <= x2 && y1 <= y2) {
		printf("Polycarp");
	}else {
		printf("Vasiliy");
	}
	printf("\n");
	return 0;
}
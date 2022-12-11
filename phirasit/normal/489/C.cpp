#include <stdio.h>

int m, s;

void find_mn(int a, int b) {
	if(b >= m-1) {
		printf("%d", s-a);
		return;
	}
	for(int i = 0;i < 10;i++) {
		if(i == 0 && b == 0) continue;
		if(a + i + 9*(m-b-1) >= s) {
			printf("%d", i);
			find_mn(a+i, b+1);
			return;
		}
	}
	if(b == 0) {
		printf("-1");
	}
}
void find_mx(int a, int b) {
	if(b >= m-1) {
		printf("%d", s-a);
		return;
	}
	for(int i = 9;i >= 0;i--) {
		if(i == 0 && b == 0) continue;
		if(a + i <= s) {
			printf("%d", i);
			find_mx(a+i, b+1);
			return;
		}
	}
	if(b == 0) {
		printf("-1");
	}
}
int main() {
	scanf("%d%d", &m, &s);
	if(m == 1 && s == 0) {
		printf("0 0\n");
	}else if(9*m < s || s == 0) {
		printf("-1 -1\n");
	}else {
		find_mn(0, 0);
		printf(" ");
		find_mx(0, 0);
		printf("\n");
	}
	return 0;
}
#include <stdio.h>

int n;

int main() {
	scanf("%d", &n);
	for(int i = 0;i < n;i++) {
		for(int j = 0;j < n;j++) {
			if(n/2 <= i+j && i+j <= n+n/2-1 && j-i <= n/2 && i-j <= n/2) {
				printf("D");
			}else {
				printf("*");
			}
		}
		printf("\n");
	}
	return 0;
}
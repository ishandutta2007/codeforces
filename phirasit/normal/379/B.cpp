#include <stdio.h>

int n,a;

int main() {
	int i;
	scanf("%d",&n);
	while(n--) {
		scanf("%d",&a);
		while(a--) {
			printf("P");
			if(a > 0) {
				if(n > 0) {
					printf("RL");
				}else {
					printf("LR");
				}
			}
		}
		if(n > 0)
			printf("R");
	}
	printf("\n");
	return 0;
}
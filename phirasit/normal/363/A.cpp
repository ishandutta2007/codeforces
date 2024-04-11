#include <stdio.h>

int n;

int main() {
	int i,j;
	scanf("%d",&n);
	if(n == 0) printf("O-|-OOOO\n");
	while(n) {
		i = n%10;
		if(i < 5) printf("O-");
		else printf("-O");
		i %= 5;
		printf("|");
		for(j=0;j<5;j++) {
			if(i == j)
				printf("-");
			else
				printf("O");
		}
		n /= 10;
		printf("\n");
	}
	return 0;
}
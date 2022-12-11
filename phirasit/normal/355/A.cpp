#include <stdio.h>

int a,b;

int main() {
	scanf("%d %d",&a,&b);
	if(a == 1 && b == 0)
		printf("0\n");
	else if(b == 0)
		printf("No solution\n");
	else {
		a--;
		printf("%d",b);
		while(a--)
			printf("0");
		printf("\n");
	}
	return 0;
}
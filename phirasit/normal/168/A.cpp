#include <stdio.h>

int n,x,y;

int main() {
	int i,j;
	scanf("%d %d %d",&n,&x,&y);
	int k = n*y-100*x;
	int a = k/100 + !!(k%100);
	if(k > 0)
		printf("%d\n",a);
	else 
		printf("0\n");
	return 0;
}
#include <stdio.h>

int abs(int x) {
	if(x < 0) return -x;
	return x;
}
int mx(int a,int b) {
	if(a > b) return a;
	return b;
}
int main() {
	int a,b,x,y;
	scanf("%d %d %d %d",&a,&b,&x,&y);
	printf("%d ",(a != x) + (b != y));
	if((a+b)%2 != (x+y)%2) {
		printf("0 ");
	}else {
		if(a == x && b == y) {
			printf("0 ");
		}else if(a+b == x+y || a-b == x-y)
			printf("1 ");
		else
			printf("2 ");
	}
	printf("%d\n",mx(abs(a-x),abs(b-y)));
	return 0;
}
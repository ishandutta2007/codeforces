#include <stdio.h>

int n,m,i,j,a,b;
int ans = (-1u/2);

void check(int x,int y) {
	if(x%a || y%b) return;
	if((x/a)%2 != (y/b)%2) return;
	if(x/a >= y/b && x/a < ans)
		ans = x/a;
	if(y/b >= x/a && y/b < ans)
		ans = y/b;
}
int main() {
	scanf("%d %d %d %d %d %d",&n,&m,&i,&j,&a,&b);
	check(n-i,m-j);
	check(n-i,j-1);
	check(i-1,m-j);
	check(i-1,j-1);
	if(ans == -1u/2 || (ans > 0 && ((n-a < 1 && i+a > n) || (m-b < 1 && j+b > m)))) {
		printf("Poor Inna and pony!\n");
	}else {
		printf("%d\n",ans);
	}
	return 0;
}
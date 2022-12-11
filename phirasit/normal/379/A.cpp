#include <stdio.h>

int a,b,c,ans = 0;

int main() {
	scanf("%d %d",&a,&b);
	c = 0;
	while(a > 0) {
		ans += a;
		int s = a+c;
		c = s%b;
		a = s/b;
	}
	printf("%d\n",ans);
	return 0;
}
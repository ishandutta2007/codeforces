#include <stdio.h>
#include <math.h>

int t;
int x;

int main() {
	scanf("%d",&t);
	while(t--) {
		scanf("%d",&x);
		if(360 % (180-x) == 0)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}
/*
(n-2)*180 / n = x
(n-2)*180 = nx
180n -360 = nx
(180-x)n = 360
n = 360/(180-x);
*/
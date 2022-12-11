#include <stdio.h>
#include <math.h>

double a,b,c,d;

int main() {
	scanf("%lf %lf %lf %lf",&a,&b,&c,&d);
	if(a-b == b-c && b-c == c-d) {
		printf("%.0lf\n",2*d-c);
	}else if(a/b == b/c && b/c == c/d && floor(d*d/c) == d*d/c) {
		printf("%.0lf\n",d*d/c);
	}else {
		printf("42\n");
	}
	return 0;
}
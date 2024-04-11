#include <stdio.h>

double ans = 0;
double a,b,c,d;

void cal(double p) {
	if(p <= 0.00000001) return;
	ans += p*a/b;
	cal(p*(1-a/b) * (1-c/d));
}
int main() {
	scanf("%lf %lf %lf %lf",&a,&b,&c,&d);
	cal(1);
	printf("%.8lf\n",ans);
	return 0;
}
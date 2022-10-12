#include <cstdio>
#include <cmath>

const double PI = acos(-1);

double r, p;

double sqr (double x) { return x * x; }

int main(){
	scanf ("%lf %lf", &p, &r);
	double area = sqr(sin(PI / p)) / tan(1.5 * PI / p) - sin(2.0 * PI / p) / 2.0;
	area *= -r * r * p;
	printf("%.15lf\n", area);
	return 0;
}
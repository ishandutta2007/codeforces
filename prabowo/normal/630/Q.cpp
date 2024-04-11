#include <cstdio>
#include <cmath>

const double pi = acos(-1);

double f(int S, int k) {
	double theta = (pi - pi * 2 / k) / 2.0;
	return tan(theta) * S * S / 4.0 * k * sqrt (S * S - S * S / cos(theta) / cos(theta) / 4) / 3;
}

int main () {
	int l3, l4, l5;
	scanf ("%d %d %d", &l3, &l4, &l5);
	printf ("%.10lf\n", f(l3, 3) + f(l4, 4) + f(l5, 5));
	return 0;
}
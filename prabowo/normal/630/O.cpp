#include <cstdio>
#include <cmath>

int main () {
	int px, py, vx, vy;
	int a, b, c, d;
	
	scanf ("%d %d %d %d %d %d %d %d", &px, &py, &vx, &vy, &a, &b, &c, &d);
	
	double len = hypot (vx, vy);
	
	double x = vx / len;
	double y = vy / len;
	
	printf ("%.12lf %.12lf\n", x * b + px, y * b + py);
	printf ("%.12lf %.12lf\n", -y * a / 2.0 + px, x * a / 2.0 + py);
	printf ("%.12lf %.12lf\n", -y * c / 2.0 + px, x * c / 2.0 + py);
	printf ("%.12lf %.12lf\n", -x * d - y * c / 2.0 + px, -y * d + x * c / 2.0 + py);
	printf ("%.12lf %.12lf\n", -x * d + y * c / 2.0 + px, -y * d - x * c / 2.0 + py);
	printf ("%.12lf %.12lf\n", y * c / 2.0 + px, -x * c / 2.0 + py);
	printf ("%.12lf %.12lf\n", y * a / 2.0 + px, -x * a / 2.0 + py);
	
	return 0;
}
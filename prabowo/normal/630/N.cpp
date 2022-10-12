#include <cstdio>
#include <cmath>

int main() {
	int a, b, c;
	scanf ("%d %d %d", &a, &b, &c);
	double d = sqrt ((double) (b * b - 4 * a * c));
	
	double ans1 = (d - b) / (2 * a);
	double ans2 = (-d - b) / (2 * a);
	if (ans1 < ans2) printf ("%.15lf\n%.15lf\n", ans2, ans1);
	else printf ("%.15lf\n%.15lf\n", ans1, ans2);
	return 0;
}
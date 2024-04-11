#include<cstdio>
#include<cmath>
#include<algorithm>

using namespace std;

const double eps = 1e-4;

double x[10], y[10], a[10], b[10], c[10], a2[10], b2[10], c2[10], mx[10], my[10], ang[10], angle, d, xx, yy, k;
int boo, l, BOO;

int main()
{
	scanf("%lf%lf%lf%lf%lf%lf", &x[1], &y[1], &x[2], &y[2], &x[3], &y[3]);
	x[4] = x[1], y[4] = y[1];
	for (int i = 1; i < 3; i++)
	{
		a2[i] = y[i + 1] - y[i];
		b2[i] = x[i] - x[i + 1];
		c2[i] = y[i] * x[i + 1] - x[i] * y[i + 1];
		mx[i] = (x[i] + x[i + 1]) / 2;
		my[i] = (y[i] + y[i + 1]) / 2;
		a[i] = -b2[i];
		b[i] = a2[i];
		//printf("mx[i] = %.20lf\n", mx[i]);
		c[i] = -a[i] * mx[i] - b[i] * my[i];
	}
	//printf("%.20lf %.20lf %.20lf\n", a[1], b[1], c[1]);
	//printf("%.20lf %.20lf %.20lf\n", a[2], b[2], c[2]);
	yy = (a[1] * c[2] - c[1] * a[2]) / (a[2] * b[1] - a[1] * b[2]);
	if (a[1] != 0)
		xx = (-c[1] - b[1] * yy) / a[1];
	else
		xx = (-c[2] - b[2] * yy) / a[2];
	//printf("%.20lf %.20lf\n", xx, yy);
	d = (x[1] - xx) * (x[1] - xx) + (y[1] - yy) * (y[1] - yy);
	ang[3] = acos(1 - ((x[1] - x[2]) * (x[1] - x[2]) + (y[1] - y[2]) * (y[1] - y[2])) / (2 * d));
	ang[2] = acos(1 - ((x[1] - x[3]) * (x[1] - x[3]) + (y[1] - y[3]) * (y[1] - y[3])) / (2 * d));
	ang[1] = acos(1 - ((x[2] - x[3]) * (x[2] - x[3]) + (y[2] - y[3]) * (y[2] - y[3])) / (2 * d));
	//for (int i = 1; i < 4; i++)
	//	printf("ang = %.20lf\n", ang[i]);
	for (int i = 3; i <= 1000; i++)
	{
		angle = 2 * M_PI / i;
	 	for (int j = 1; j < 4; j++)
	 	{
	 		boo = 0;
	 		BOO = 1;
	 		k = ang[j] / angle;
	 		l = (int) k;
	 		if (abs(k - l) < eps || abs(l + 1 - k) < eps)
	 			boo = 1;
	 		if (boo == 0)
	 		{
	 		    BOO = 0;
	 			break;
	 		}
	 	}
	 	if (BOO == 1)
	 	{
	 	    //printf("%d\n", i);
	 		printf("%.20lf\n", d * i * sin(angle) / 2);
	 		return 0;
	 	}
	}
	return 0;
}
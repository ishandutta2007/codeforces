#include<cstdio>
#include<cmath>

using namespace std;

double a, v, l, d, w, l1, l2, t1, T1, T2, T3, v1, v2;

int main()
{
	scanf("%lf%lf%lf%lf%lf", &a, &v, &l, &d, &w);
	if (w >= v)
	{
		if (v * v >= 2 * a * l)
			printf("%.20lf\n", sqrt(2 * l / a));
		else
		{
			l1 = v * v / (2 * a);
			t1 = v / a;
			printf("%.20lf\n", t1 + (l - l1) / v);
		}
	}
	else
	{
		if (w * w >= 2 * a * d)
		{
		    //printf("U");
			T1 = sqrt(2 * d / a);
			v1 = sqrt(2 * d * a);
		}
		else
		{
			if ((2 * v * v - w * w) <= 2 * a * d)
			{
				l1 = (2 * v * v - w * w) / (2 * a);
				t1 = (2 * v - w) / a;
				T1 = t1 + (d - l1) / v;
			}
			else
			{
				v2 = sqrt(a * d + w * w / 2);
				T1 = (2 * v2 - w) / a;
			}
			v1 = w;
		}
		if (v * v - v1 * v1 >= 2 * a * (l - d))
		{
			v2 = sqrt(2 * a * (l - d) + v1 * v1);
			T2 = (v2 - v1) / a;
		}
		else
		{
			//printf("U");
			T2 = (v - v1) / a;
			l2 = (v * v - v1 * v1) / (2 * a);
			T3 = (l - d - l2) / v;	
		}
		printf("%.20lf\n", T1 + T2 + T3);
	}
	return 0;
}
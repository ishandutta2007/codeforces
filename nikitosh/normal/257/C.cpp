#include<cstdio>
#include<algorithm>
#include<cmath>

using namespace std;

int N;
double sum, x, y, ang, angle[200000], min1 = 1e9, max1 = -1e9; 

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		scanf("%lf%lf", &x, &y);
		angle[i] = atan2(y, x);     
	}
	sort(angle, angle + N);
	for (int i = 1; i < N; i++)
	{
		ang = angle[i] - angle[i - 1];
		min1 = min(min1, 2 * M_PI - ang);
	}
	min1 = min(min1, angle[N - 1] - angle[0]);
	printf("%.20lf\n", min1 * (double) 180 / M_PI);
	return 0;
}
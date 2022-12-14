#include<cstdio>
#include<algorithm>
#include<cmath>

using namespace std;

int N, b[100], a[1000], i, k;
                        
int main()
{                 
	double pi = acos((double) -1);
	scanf("%d", &N);
	for (i = 0; i < N; i++)
		scanf("%d", &a[i]); 
	if (N == 1)
	{
		printf("%.20lf", (double) a[0] * (double) a[0] * pi);
		return 0;
	}
	sort(a, a + N);
	if (N % 2 == 1)
	{
		for (i = N - 1; i >= 1; i--)
			if (i % 2 == 0)
				k += a[i] * a[i] - a[i - 1] * a[i - 1];
		k += a[0] * a[0];
	}
	else
	{
		for (i = N - 1; i >= 1; i--)
			if (i % 2 == 1)
				k += a[i] * a[i] - a[i - 1] * a[i - 1];
	}
	printf("%.20lf", ((double) k) * pi);
	return 0;
}
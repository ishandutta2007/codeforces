#include<cstdio>

int N, K, a[100000], i, l = 0;

int main()
{
	scanf("%d%d", &N, &K);
	for (i = 1; i <= N; i++)
		scanf("%d", &a[i]);
	if (a[K] > 0)
	{
		l = N + 1;
		for (i = K + 1; i <= N; i++)
			if (a[i] != a[K])
			{
				l = i;
				break;
			}
	}             
	else
	{
		for (i = 1; i <= N; i++)
			if (a[i] <= 0)
			{
				l = i;
				break;
			}
	}              
	printf("%d", l - 1);
	return 0;	
}
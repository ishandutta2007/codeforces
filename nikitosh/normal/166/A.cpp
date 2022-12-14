#include<cstdio>

int N, K, a[1000], b[1000], i, j, t, z;

int main()
{
	scanf("%d%d", &N, &K);
	for (i = 0; i < N; i++)
	{
		scanf("%d%d", &a[i], &b[i]);
	}
	for (i = 0; i < N; i++)
		for (j = 0; j < N - i; j++)
		{
			if (a[j] < a[j + 1])
			{
				t = a[j];
				a[j] = a[j + 1];
				a[j + 1] = t;
				t = b[j];
				b[j] = b[j + 1];
				b[j + 1] = t;
			}
			if (a[j] == a[j + 1] && b[j] > b[j + 1]) 
			{
				t = a[j];
				a[j] = a[j + 1];
				a[j + 1] = t;
				t = b[j];
				b[j] = b[j + 1];
				b[j + 1] = t;
			}                                        
		}
	for (i = 0; i < N; i++)
		if (a[i] == a[K - 1] && b[i] == b[K - 1])
			z++;
	printf("%d", z); 
	return 0;
}
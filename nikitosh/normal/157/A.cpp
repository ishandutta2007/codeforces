#include<cstdio>

int N, i, j, k, a[40][40], x[40], y[40], zzz;

int main()
{
	scanf("%d", &N);
	for (i = 0; i < N; i++)
	{
		k = 0;
		for (j = 0; j < N; j++)
		{
			scanf("%d", &a[i][j]);
			k += a[i][j];
		}
		x[i] = k;
	}
	for (i = 0; i < N; i++)
	{
		k = 0;
		for (j = 0; j < N; j++)
			k += a[j][i];
		y[i] = k;
	}
	for (i = 0; i < N; i++)
		for (j = 0; j < N; j++)
			if (x[i] < y[j])
				zzz++;
	printf("%d", zzz);
	return 0;
}
#include<cstdio>

int N, i, j, a[1000][1000], sum;

int main()
{
scanf("%d", &N);
	for (i = 0; i < N; i++)
		for (j = 0; j < N; j++)
			scanf("%d", &a[i][j]);
 	for (i = 0; i < N; i++)
 	{
 		sum += a[i][i];
 		sum += a[i][N - i - 1];
	}
	for (i = 0; i < N; i++)
	{
		sum += a[N / 2][i];
		sum += a[i][N / 2];
	}
	sum -= 3 * a[N / 2][N / 2];
	printf("%d", sum);
	return 0;
}
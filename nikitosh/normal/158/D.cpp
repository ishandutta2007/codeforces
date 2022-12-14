#include<cstdio>

int i, j, g, max1 = -300000000, k, l, N, a[100000], b[100000], x = 0;

int main()
{
	scanf("%d", &N);
	for (i = 1; i <= N; i++)
		scanf("%d", &a[i]);
	for (i = 1; i <= N; i++)     
		if (N % i == 0)
		{
			if ((N / i) != 1 && (N / i) != 2) 
			b[x] = i;
			x++;
		}
	for (i = 0; i < x; i++)
		for (j = 1; j <= b[i]; j++)
		{
			k = 0;
			for (g = 0; g < N / b[i]; g++)
			{
				k += a[g * b[i] + j];                
			}
			if (k > max1)
				max1 = k;
	   	}
	printf("%d", max1);
	return 0;
}
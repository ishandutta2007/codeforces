#include<cstdio>

int N, k, i, sum;

int main()
{
	scanf("%d", &N);
	sum = N;
	while(N != 1)
	{
		for (i = N - 1; i >= 1; i--)
			if (N % i == 0)
			{
				k = i;
				break;
			}
		sum += k;
		N = k;
	}
	printf("%d", sum);
	return 0;
}
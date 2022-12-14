#include<cstdio>
#include<cmath>

int N, a[10000], x, p[100], q[100], ans;

int obw(int k, int l)
{
	for (int j = 0; j < 10; j++)
		p[j] = 0;
	for (int j = 0; j < 10; j++)
		q[j] = 0;
	while (k != 0)
	{
		p[k % 10]++;
		k /= 10;
	}
	while (l != 0)
	{
		q[l % 10]++;
		l /= 10;
	}
	for (int j = 0; j < 10; j++)
		if (p[j] != 0 && q[j] != 0)
			return 1;
	return 0;
}

int main()
{
	scanf("%d", &N);
	for (int i = 1; i <= (int) sqrt(N); i++)
	{
		if (N % i == 0 && i * i != N)
		{
			a[x++] = i;
			a[x++] = N / i;
	 	}
	 	if (N % i == 0 && i * i == N)
	 		a[x++] = i;
	}
	for (int i = 0; i < x; i++)
		if (obw(N, a[i]) == 1)
			ans++;
 	printf("%d\n", ans);
	return 0;
}
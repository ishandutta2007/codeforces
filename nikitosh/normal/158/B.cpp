#include<cstdio>

int N, k, i, l, a[100];

int main()
{
	scanf("%d", &N);
	for (i = 0; i < N; i++)
	{
		scanf("%d", &k);
		a[k]++;
	}
	l += a[4];
	l += a[3];
	a[1] -= a[3];
	l += a[2] / 2;
	if (a[2] % 2 == 0)
		a[2] = 0;
	else
	{
		l += 1;
		a[1] -= 2;
	}	
	if (a[1] > 0)
		l += (a[1] + 3) / 4; 
	printf("%d", l);
	return 0;
}
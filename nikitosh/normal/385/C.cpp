#include<cstdio>
#include<iostream>

using namespace std;

const int maxX = (int) 1e7 + 5;

int n, m, l, r, a[1000005], was[maxX + 5], prime[maxX + 5], used[maxX + 5];
long long sum[maxX + 5];

int main()
{
	//freopen("1.in", "r", stdin);
	//freopen("1.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
		was[a[i]]++;
	}
	for (int i = 2; i <= maxX; i++)
		prime[i] = 1;
	for (int j = 2; j <= maxX; j++)
	{
		for (int k = 2; k <= maxX / j; k++)
			prime[j * k] = 0;
	}
	for (int j = 2; j <= maxX; j++)
	{
		if (prime[j] == 0)
			continue;
		for (int k = 1; k <= maxX / j; k++)
			if (was[k * j])
				used[j] += was[k * j];
	}
	for (int i = 1; i <= maxX; i++)
    {
    	sum[i] = sum[i - 1] + used[i];
		//printf("%I64d\n", sum[i]);
	}
	scanf("%d", &m);
	for (int i = 0; i < m; i++)
	{
		scanf("%d%d", &l, &r);
		if (l > (int) 1e7)
		{
			puts("0");
			continue;
		}
		if (r > (int) 1e7)
			r = (int) 1e7;
		printf("%I64d\n", sum[r] - sum[l - 1]);
	}
	return 0;
}
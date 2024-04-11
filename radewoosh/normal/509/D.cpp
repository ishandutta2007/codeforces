#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
long long tab[107][107];
long long mod;
long long a[107];
long long b[107];

long long zna(long long v)
{
	if (v>0)
	return 1;
	if (v<0)
	return -1;
	return 0;
}

long long bez(long long v)
{
	return max(v, -v);
}

int main()
{
	scanf("%d%d", &n, &m);
	for (int i=1; i<=n; i++)
	{
		for (int j=1; j<=m; j++)
		{
			scanf("%lld", &tab[i][j]);
		}
	}
	for (int i=1; i<n; i++)
	{
		for (int j=1; j<m; j++)
		{
			if (tab[i][j]-tab[i][j+1]!=tab[i+1][j]-tab[i+1][j+1])
			{
				if (zna(tab[i][j]-tab[i][j+1])==zna(tab[i+1][j]-tab[i+1][j+1]))
				{
					printf("NO");
					return 0;
				}
				mod=bez(tab[i][j]-tab[i][j+1]-tab[i+1][j]+tab[i+1][j+1]);
				break;
			}
		}
		if (mod)
		break;
	}
	if (!mod)
	{
		mod=1;
		mod*=1000000;
		mod*=1000000;
		mod*=1000000;
	}
	a[1]=0;
	for (int i=2; i<=n; i++)
	{
		a[i]=(a[i-1]+tab[i][1]-tab[i-1][1]+mod)%mod;
	}
	b[1]=(tab[1][1]-a[1]+mod)%mod;
	for (int j=2; j<=m; j++)
	{
		b[j]=b[j-1]+(tab[1][j]-tab[1][j-1]);
	}
	for (int i=1; i<=n; i++)
	{
		for (int j=1; j<=m; j++)
		{
			if ((a[i]+b[j])%mod!=tab[i][j])
			{
				printf("NO");
				return 0;
			}
		}
	}
	printf("YES\n");
	printf("%lld", mod);
	printf("\n");
	for (int i=1; i<=n; i++)
	printf("%lld ", a[i]);
	printf("\n");
	for (int i=1; i<=m; i++)
	printf("%lld ", b[i]);
	return 0;
}
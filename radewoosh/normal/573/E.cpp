#include <bits/stdc++.h>
using namespace std;

int n;

long long tab[100007];
int wz[100007];

long long sum[100007];
long long ile[100007];

long long wyn;

int czy=1;

void aktu()
{
	for (int i=1; i<=n; i++)
	{
		sum[i]=0;
		ile[i]=0;
	}
	for (int i=1; i<=n; i++)
	{
		ile[i]=ile[i-1]+wz[i];
	}
	for (int i=n; i; i--)
	{
		sum[i]=sum[i+1]+tab[i]*wz[i];
	}
}

int main()
{
	scanf("%d", &n);
	for (int i=1; i<=n; i++)
	{
		scanf("%lld", &tab[i]);
		wz[i]=1;
		wyn+=i*tab[i];
	}
	while(czy)
	{
		czy=0;
		aktu();
		for (int i=1; i<=n; i++)
		{
			if (wz[i] && -tab[i]*(ile[i-1]+1)-sum[i+1]>0)
			{
				wyn+=-tab[i]*(ile[i-1]+1)-sum[i+1];
				wz[i]=0;
				czy=1;
			}
			ile[i]=ile[i-1]+wz[i];
		}
		aktu();
		for (int i=n; i; i--)
		{
			if (!wz[i] && tab[i]*(ile[i-1]+1)+sum[i+1]>0)
			{
				wyn+=tab[i]*(ile[i-1]+1)+sum[i+1];
				wz[i]=1;
				czy=1;
			}
			sum[i]=sum[i+1]+tab[i]*wz[i];
		}
	}
	printf("%lld\n", wyn);
	return 0;
}
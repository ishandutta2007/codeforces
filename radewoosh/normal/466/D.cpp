#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int n, h;
int tab[500007];
long long wyn[5007];

int main()
{
	scanf("%d%d", &n, &h);
	for (int i=1; i<=n; i++)
	{
		scanf("%d", &tab[i]);
		if (tab[i]+min(n-i+1, i)<h || tab[i]>h)
		{
			printf("0");
			return 0;
		}
		if (i>1 && max(tab[i]-tab[i-1], tab[i-1]-tab[i])>1)
		{
			printf("0");
			return 0;
		}
	}
	wyn[1]=1;
	for (int i=2; i<=n; i++)
	{
		if (tab[i]==tab[i-1])
		{
			wyn[i]=wyn[i-1]*(h-tab[i]+1);
		}
		if (tab[i]<tab[i-1])
		{
			wyn[i]=wyn[i-1];
		}
		if (tab[i]>tab[i-1])
		{
			wyn[i]=wyn[i-1]*(h-tab[i-1]);
		}
		wyn[i]=wyn[i]%1000000007;
	}
	printf("%lld", wyn[n]);
	return 0;
}
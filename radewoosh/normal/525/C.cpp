#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int n;
long long wyn;
long long tab[1000007];

long long wait;

int main()
{
	scanf("%d", &n);
	for (int i=1; i<=n; i++)
	{
		scanf("%lld", &tab[i]);
	}
	sort(tab+1, tab+1+n);
	for (int i=n-1; i>0; i--)
	{
		if (tab[i]==tab[i+1] || tab[i]+1==tab[i+1])
		{
			if (!wait)
			{
				wait=tab[i];
			}
			else
			{
				wyn+=wait*tab[i];
				wait=0;
			}
			i--;
			continue;
		}
	}
	printf("%lld", wyn);
	return 0;
}
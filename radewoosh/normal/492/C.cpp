#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int n;
long long r, lim, ak;
long long wyn;
pair <long long, long long> tab[100007];

int main()
{
	scanf("%d%lld%lld", &n, &r, &lim);
	lim*=n;
	for (int i=1; i<=n; i++)
	{
		scanf("%lld%lld", &tab[i].second, &tab[i].first);
		ak+=tab[i].second;
	}
	if (ak>=lim)
	{
		printf("0");
		return 0;
	}
	sort(tab+1, tab+1+n);
	for (int i=1; i<=n; i++)
	{
		wyn+=tab[i].first*min(lim-ak, r-tab[i].second);
		ak+=min(lim-ak, r-tab[i].second);
	}
	printf("%lld", wyn);
	return 0;
}
#include <iostream>
#include <cstdio>
#include <map>
#include <algorithm>
#include <vector>
using namespace std;

int n;
long long tab1[307];
long long tab2[307];
map <long long,long long> mapa;

int main()
{
	scanf("%d", &n);
	mapa[0]=0;
	for (int i=1; i<=n; i++)
	{
		scanf("%lld", &tab1[i]);
	}
	for (int i=1; i<=n; i++)
	{
		scanf("%lld", &tab2[i]);
	}
	for (int i=1; i<=n; i++)
	{
		for (map <long long,long long>::iterator it=mapa.begin(); it!=mapa.end(); it++)
		{
			if (mapa[__gcd(it->first, tab1[i])])
			mapa[__gcd(it->first, tab1[i])]=min(mapa[__gcd(it->first, tab1[i])], mapa[it->first]+tab2[i]);
			else
			mapa[__gcd(it->first, tab1[i])]=mapa[it->first]+tab2[i];
		}
	}
	if (mapa[1])
	{
		printf("%lld", mapa[1]);
	}
	else
	{
		printf("-1");
	}
	return 0;
}
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;


int n;
pair <long long,long long> s;
pair <long long,long long> tab[1007];
int czywaz[1007];
int wyn;

long long ilo(pair <long long,long long> a, pair <long long,long long> b)
{
	return (a.first-s.first)*(b.second-s.second)-(b.first-s.first)*(a.second-s.second);
}

int main()
{
	scanf("%d%lld%lld", &n, &s.first, &s.second);
	wyn=n;
	for (int i=1; i<=n; i++)
	{
		scanf("%lld%lld", &tab[i].first, &tab[i].second);
	}
	for (int i=1; i<=n; i++)
	{
		for (int j=1; j<i; j++)
		{
			if (!czywaz[j] && !ilo(tab[i], tab[j]))
			{
				czywaz[j]=1;
				wyn--;
			}
		}
	}
	printf("%d", wyn);
	return 0;
}
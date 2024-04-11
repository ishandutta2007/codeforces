#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int n;
pair <int,int> tab[2007];
int gdz1, gdz2;

int main()
{
	scanf("%d", &n);
	for (int i=1; i<=n; i++)
	{
		scanf("%d", &tab[i].first);
		tab[i].second=i;
	}
	sort(tab+1, tab+1+n);
	for (int i=1; i<n; i++)
	{
		if (tab[i].first==tab[i+1].first)
		{
			if (!gdz1)
			{
				gdz1=i;
				continue;
			}
			if (!gdz2)
			{
				gdz2=i;
				continue;
			}
		}
	}
	if (!gdz2)
	{
		printf("NO");
		return 0;
	}
	printf("YES\n");
	for (int i=1; i<=n; i++)
	{
		printf("%d ", tab[i].second);
	}
	printf("\n");
	for (int i=1; i<=n; i++)
	{
		if (gdz1==i)
		{
			printf("%d ", tab[i+1].second);
			continue;
		}
		if (gdz1==i-1)
		{
			printf("%d ", tab[i-1].second);
			continue;
		}
		printf("%d ", tab[i].second);
	}
	printf("\n");
	for (int i=1; i<=n; i++)
	{
		if (gdz2==i)
		{
			printf("%d ", tab[i+1].second);
			continue;
		}
		if (gdz2==i-1)
		{
			printf("%d ", tab[i-1].second);
			continue;
		}
		printf("%d ", tab[i].second);
	}
	return 0;
}
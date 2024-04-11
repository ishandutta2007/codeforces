#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int n=6;
int tab[10];

int main()
{
	for (int i=1; i<=n; i++)
	{
		scanf("%d", &tab[i]);
	}
	sort(tab+1, tab+7);
	if (tab[1]==tab[2] && tab[1]==tab[3] && tab[1]==tab[4])
	{
		if (tab[5]==tab[6])
		printf("Elephant");
		else
		printf("Bear");
		return 0;
	}
	if (tab[3]==tab[2] && tab[3]==tab[4] && tab[3]==tab[5])
	{
		if (tab[1]==tab[6])
		printf("Elephant");
		else
		printf("Bear");
		return 0;
	}
	if (tab[3]==tab[6] && tab[3]==tab[4] && tab[3]==tab[5])
	{
		if (tab[1]==tab[2])
		printf("Elephant");
		else
		printf("Bear");
		return 0;
	}
	printf("Alien");
	return 0;
}
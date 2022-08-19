#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int n, k;
int tab[1007];
vector <int> wek[107];
int mini=1000000;
int maxi;

int main()
{
	scanf("%d%d", &n, &k);
	for (int i=1; i<=n; i++)
	{
		scanf("%d", &tab[i]);
		mini=min(mini, tab[i]);
		maxi=max(maxi, tab[i]);
	}
	for (int i=1; i<=mini; i++)
	{
		for (int j=1; j<=n; j++)
		{
			wek[j].push_back(1);
		}
	}
	if (maxi-mini>k)
	{
		printf("NO");
		return 0;
	}
	for (int i=1; i<=maxi-mini; i++)
	{
		for (int j=1; j<=n; j++)
		{
			if (wek[j].size()<tab[j])
			wek[j].push_back(i);
		}
	}
	printf("YES\n");
	for (int i=1; i<=n; i++)
	{
		for (int j=0; j<wek[i].size(); j++)
		{
			printf("%d ", wek[i][j]);
		}
		printf("\n");
	}
	return 0;
}
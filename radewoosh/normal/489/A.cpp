#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int n;
int tab[3007];
int mini;
vector <pair <int,int> > wek;

int main()
{
	scanf("%d", &n);
	for (int i=1; i<=n; i++)
	{
		scanf("%d", &tab[i]);
	}
	for (int i=1; i<n; i++)
	{
		mini=i;
		for (int j=i+1; j<=n; j++)
		{
			if (tab[mini]>tab[j])
			mini=j;
		}
		if (mini==i)
		continue;
		wek.push_back(make_pair(i, mini));
		tab[i]+=tab[mini];
		tab[mini]=tab[i]-tab[mini];
		tab[i]-=tab[mini];
	}
	printf("%d\n", wek.size());
	for (int i=0; i<wek.size(); i++)
	{
		printf("%d %d\n", wek[i].first-1, wek[i].second-1);
	}
	return 0;
}
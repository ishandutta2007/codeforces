#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <set>
#include <map>
using namespace std;

int n;
int tab[500007];
int tabn[500007];
vector <pair <int,int> > wek;
int gdziej[500007];
int gdzied[500007];
int sumj[500007];
int sumd[500007];
int dotj, dotd;
int v;
int vp;
int ilej, iled;

int main()
{
	scanf("%d", &n);
	for (int i=1; i<=n; i++)
	{
		scanf("%d", &tab[i]);
		tab[i]-=1;
	}
	for (int i=1; i<=5*n; i++)
	{
		gdziej[i]=1000000;
		gdzied[i]=1000000;
	}
	if (!tab[n])
	{
		for (int i=1; i<=n; i++)
		{
			tab[i]^=1;
		}
	}
	v=0;
	for (int i=1; i<=n; i++)
	{
		if (tab[i])
		{
			v++;
			gdziej[v]=i;
		}
	}
	v=0;
	for (int i=1; i<=n; i++)
	{
		if (!tab[i])
		{
			v++;
			gdzied[v]=i;
		}
	}
	for (int i=1; i<=n; i++)
	{
		sumj[i]=sumj[i-1];
		sumd[i]=sumd[i-1];
		if (!tab[i])
		{
			sumd[i]++;
		}
		else
		{
			sumj[i]++;
		}
	}
	/*for (int i=1; i<=n; i++)
	printf("%d ", gdziej[i]);
	printf("\n");
	for (int i=1; i<=n; i++)
	printf("%d ", gdzied[i]);
	printf("\n");
	for (int i=1; i<=n; i++)
	printf("%d ", sumj[i]);
	printf("\n");
	for (int i=1; i<=n; i++)
	printf("%d ", sumd[i]);
	printf("\n");*/
	for (int i=1; i<=n; i++)
	{
		//printf("   %d\n", i);
		dotj=0;
		dotd=0;
		v=0;
		ilej=0;
		iled=0;
		while (gdziej[dotj+i]!=gdzied[dotd+i])
		{
			//printf("%d %d   %d  %d %d   %d %d\n", ilej, iled, v, dotj, dotd, gdziej[dotj+i], gdzied[dotd+i]);
			if (gdziej[dotj+i]<gdzied[dotd+i])
			{
				ilej++;
				vp=gdziej[dotj+i];
			}
			else
			{
				iled++;
				vp=gdzied[dotd+i];
			}
			dotj+=sumj[vp]-sumj[v];
			dotd+=sumd[vp]-sumd[v];
			v=vp;
		}
		if (v==n && ilej>iled)
		{
			wek.push_back(make_pair(ilej, i));
		}
	}
	printf("%d\n", wek.size());
	sort(wek.begin(), wek.end());
	for (int i=0; i<wek.size(); i++)
	{
		printf("%d %d\n", wek[i].first, wek[i].second);
	}
	return 0;
}
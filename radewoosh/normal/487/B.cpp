#include <iostream>
#include <cstdio>
#include <algorithm>
#include <set>
using namespace std;

int n;
int s, l;
int m;
int tab[100007];
int drzewo[1000007];
set <pair <int,int> > maxi;
set <pair <int,int> > mini;
/*
int drzemin[1000007];
int drzemax[1000007];
*/

int a, b;
int gdz;
int dok;
int wyn;

int potenga(int v)
{
	for (int i=1; 1; i*=2)
	if (i>=v)
	return i;
}

void pis(int v, int war)
{
	v=v+m-1;
	while(v)
	{
		drzewo[v]=min(drzewo[v], war);
		v/=2;
	}
}

int czyt(int v, int a, int b, int graa, int grab)
{
	if (a>=graa && b<=grab)
	{
		return drzewo[v];
	}
	if (a>grab || b<graa)
	{
		return 1000000;
	}
	return min(czyt(v*2, a, (a+b)/2, graa, grab), czyt(v*2+1, (a+b)/2+1, b, graa, grab));
}

/*void piszmi(int v, int war)
{
	v=v+m-1;
	while(v)
	{
		drzemin[v]=min(drzemin[v], war);
		v/=2;
	}
}

int czytmi(int v, int a, int b, int graa, int grab)
{
	if (a>=graa && b<=grab)
	{
		return drzemin[v];
	}
	if (a>grab || b<graa)
	{
		return 1000000007;
	}
	return min(czytmi(v*2, a, (a+b)/2, graa, grab), czytmi(v*2+1, (a+b)/2+1, b, graa, grab));
}

void piszma(int v, int war)
{
	v=v+m-1;
	while(v)
	{
		drzemax[v]=max(drzemax[v], war);
		v/=2;
	}
}

int czytma(int v, int a, int b, int graa, int grab)
{
	if (a>=graa && b<=grab)
	{
		return drzemax[v];
	}
	if (a>grab || b<graa)
	{
		return -1000000007;
	}
	return max(czytma(v*2, a, (a+b)/2, graa, grab), czytma(v*2+1, (a+b)/2+1, b, graa, grab));
}
*/

int main()
{
	scanf("%d%d%d", &n, &s, &l);
	m=potenga(n+1);
	for (int i=1; i<=m*2; i++)
	{
		drzewo[i]=1000000;
		//drzemin[i]=1000000007;
		//drzemax[i]=-1000000007;
	}
	for (int i=1; i<=n; i++)
	{
		scanf("%d", &tab[i]);
	}
	pis(1, 0);
	gdz=1;
	for (int i=1; i<=n; i++)
	{
		mini.insert(make_pair(tab[i], i));
		maxi.insert(make_pair(-tab[i], i));
		//printf("%d %d  %d %d\n", -(*maxi.begin()).first, (*maxi.begin()).second, (*mini.begin()).first, (*mini.begin()).second);
		while(-(*maxi.begin()).first-(*mini.begin()).first>s)
		{
			mini.erase(make_pair(tab[gdz], gdz));
			maxi.erase(make_pair(-tab[gdz], gdz));
			gdz++;
		}
		dok=i-l+1;
		if (dok>=gdz)
		pis(i+1, czyt(1, 1, m, gdz, dok)+1);
		//printf("%d   %d %d  %d\n", i, gdz, dok, czyt(1, 1, m, i+1, i+1));
		//for (int j=1; j<2*m; j++)
		//printf("%d.%d ", j, drzewo[j]);
		//printf("\n");
	}
	if (czyt(1, 1, m, n+1, n+1)>n)
	printf("-1");
	else
	printf("%d", czyt(1, 1, m, n+1, n+1));
	return 0;
}
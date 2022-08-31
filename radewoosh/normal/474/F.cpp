#include <iostream>
#include <cstdio>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;

int n, m;
int nwd[100007];
int p[100007];
int k[100007];
int n1;
int drzewo[1000007];
vector <int> sta[100007];
vector <int> kon[100007];
int wyn[100007];
map <int,int> mapa;
int tab[100007];

int potenga(int v)
{
	for (int i=1; 1; i*=2)
	if (i>=v)
	return i;
}

int czyt(int v, int a, int b, int graa, int grab)
{
	if (a>=graa && b<=grab)
	return drzewo[v];
	if (a>grab || b<graa)
	return 0;
	return __gcd(czyt(v*2, a, (a+b)/2, graa, grab), czyt(v*2+1, (a+b)/2+1, b, graa, grab));
}

int main()
{
	scanf("%d", &n);
	n1=potenga(n);
	for (int i=1; i<=n; i++)
	{
		scanf("%d", &drzewo[n1-1+i]);
		tab[i]=drzewo[n1-1+i];
	}
	for (int i=n1-1; i; i--)
	{
		drzewo[i]=__gcd(drzewo[i*2], drzewo[i*2+1]);
	}
	scanf("%d", &m);
	for (int i=1; i<=m; i++)
	{
		scanf("%d%d", &p[i], &k[i]);
		sta[p[i]].push_back(i);
		kon[k[i]].push_back(i);
		nwd[i]=czyt(1, 1, n1, p[i], k[i]);
		wyn[i]=k[i]-p[i]+1;
	}
	for (int i=1; i<=n; i++)
	{
		for (int j=0; j<sta[i].size(); j++)
		{
			wyn[sta[i][j]]+=mapa[nwd[sta[i][j]]];
		}
		mapa[tab[i]]++;
		for (int j=0; j<kon[i].size(); j++)
		{
			wyn[kon[i][j]]-=mapa[nwd[kon[i][j]]];
		}
	}
	for (int i=1; i<=m; i++)
	printf("%d\n", wyn[i]);
	return 0;
}
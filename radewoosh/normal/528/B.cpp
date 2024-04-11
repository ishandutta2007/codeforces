#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
using namespace std;

int n;
pair <int,int> tab[1000007];
int p1, p2;
int dos[1000007];

//set <int> odl;

int potenga(int v)
{
	for (int i=1; 1; i<<=1)
	{
		if (i>=v)
		{
			return i;
		}
	}
}

int n1;
int drzewo[1500000];
int bsa, bsb;
int sr;

int pom;

void pisz(int v, int war)
{
	v+=n1-1;
	while(v)
	{
		drzewo[v]=max(drzewo[v], war);
		v>>=1;
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
		return 0;
	}
	return max( czyt((v<<1), a, (a+b)>>1, graa, grab) , czyt((v<<1)+1, (a+b+2)>>1, b, graa, grab) );
}

void szuk(int v)
{
	bsa=0;
	bsb=n;
	while(bsa<bsb)
	{
		sr=(bsa+bsb+2)>>1;
		if (dos[sr]<=v)
		{
			bsa=sr;
		}
		else
		{
			bsb=sr-1;
		}
	}
}

int main()
{
	scanf("%d", &n);
	n1=potenga(n);
	for (int i=1; i<=n; i++)
	{
		scanf("%d%d", &p1, &p2);
		tab[i].first=p1-p2;
		tab[i].second=p1+p2;
		dos[i]=tab[i].second;
	}
	sort(tab+1, tab+1+n);
	sort(dos+1, dos+1+n);
	for (int i=1; i<=n; i++)
	{
		if (tab[i].first<=0)
		{
			szuk(tab[i].second);
			pisz(bsa, 1);
			//printf("%d %d   %d\n", tab[i].first, tab[i].second, bsa);
		}
		else
		{
			szuk(tab[i].first);
			pom=czyt(1, 1, n1, 1, bsa);
			//printf("%d\n", bsa);
			szuk(tab[i].second);
			pisz(bsa, pom+1);
			//printf("%d %d   %d\n", tab[i].first, tab[i].second, bsa);
		}
		//for (int j=1; j<=n; j++)
		//printf("%d ", czyt(1, 1, n1, j, j));
		//printf("\n");
	}
	printf("%d", czyt(1, 1, n1, 1, n));
	return 0;
}
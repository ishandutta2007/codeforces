#include <bits/stdc++.h>
using namespace std;

int n;
int n1;

int kied[1100007];

int drzewo[1100007];
int narz[1100007];

int potenga(int v)
{
	for (int i=1; 1; i<<=1)
		if (i>=v)
			return i;
}

void dodaj(int v, int a, int b, int graa, int grab, int w)
{
	if (a>=graa && b<=grab)
	{
		narz[v]+=w;
		return;
	}
	if (a>grab || b<graa)
	{
		return;
	}
	dodaj((v<<1), a, (a+b)>>1, graa, grab, w);
	dodaj((v<<1)^1, (a+b+2)>>1, b, graa, grab, w);
	drzewo[v]=min(drzewo[(v<<1)]+narz[(v<<1)], drzewo[(v<<1)^1]+narz[(v<<1)^1]);
}

int szukaj(int v, int a, int b)
{
	if (a==b)
		return a;
	drzewo[v]+=narz[v];
	narz[(v<<1)]+=narz[v];
	narz[(v<<1)^1]+=narz[v];
	narz[v]=0;
	if (drzewo[(v<<1)^1]+narz[(v<<1)^1]<0)
		return szukaj((v<<1)^1, (a+b+2)>>1, b);
	return szukaj((v<<1), a, (a+b)>>1);
}

int main()
{
	scanf("%d", &n);
	n1=potenga(n);
	for (int i=1; i<=n; i++)
	{
		int p, t, x;
		scanf("%d%d", &p, &t);
		if (t==0)
		{
			dodaj(1, 1, n1, 1, p, 1);
		}
		else
		{
			scanf("%d", &x);
			kied[p]=x;
			dodaj(1, 1, n1, 1, p, -1);
		}
		if (drzewo[1]+narz[1]>=0)
			printf("-1\n");
		else
			printf("%d\n", kied[szukaj(1, 1, n1)]);
	}
	return 0;
}
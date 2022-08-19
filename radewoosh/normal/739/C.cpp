#include <bits/stdc++.h>
using namespace std;

int n;

int n1;

long long wys[1100007];

int drzewo[1100007];

int najp1[1100007];
int najp2[1100007];
int najp21[1100007];

int najl1[1100007];
int najl2[1100007];
int najl12[1100007];

int q;

int potenga(int v)
{
	for (int i=1; 1; i<<=1)
		if (i>=v)
			return i;
}

void rzuc(int v, int a, int b, int graa, int grab, long long war)
{
	if (a>=graa && b<=grab)
	{
		wys[v]+=war;
		return;
	}
	if (a>grab || b<graa)
	{
		return;
	}
	rzuc((v<<1), a, (a+b)>>1, graa, grab, war);
	rzuc((v<<1)^1, (a+b+2)>>1, b, graa, grab, war);
}

long long spytaj(int v)
{
	long long ret=0;
	v+=n1-1;
	while(v)
	{
		ret+=wys[v];
		v>>=1;
	}
	return ret;
}

inline void upd(int v, int pd)
{
	int c1=(v<<1);
	int c2=(v<<1)^1;
	drzewo[v]=max(drzewo[c1], drzewo[c2]);
	najp1[v]=najp2[v]=najp21[v]=najl1[v]=najl2[v]=najl12[v]=0;
	
	najp1[v]=najp1[c1];
	najp2[v]=najp2[c1];
	najp21[v]=najp21[c1];
	if (najp21[v]==pd)
		najp21[v]+=najp1[c2];
	if (najp1[v]==pd)
		najp1[v]+=najp1[c2];
	if (najp2[v]==pd)
		najp2[v]+=najp2[c2];
	if (najp2[c1]==pd)
		najp21[v]=max(najp21[v], pd+najp21[c2]);
	
	najl1[v]=najl1[c2];
	najl2[v]=najl2[c2];
	najl12[v]=najl12[c2];
	if (najl12[v]==pd)
		najl12[v]+=najl2[c1];
	if (najl1[v]==pd)
		najl1[v]+=najl1[c1];
	if (najl2[v]==pd)
		najl2[v]+=najl2[c1];
	if (najl1[c2]==pd)
		najl12[v]=max(najl12[v], pd+najl12[c1]);
		
	drzewo[v]=max(drzewo[v], najl2[c1]+najp21[c2]);
	drzewo[v]=max(drzewo[v], najl12[c1]+najp1[c2]);
}

inline void zmien(int v, int na)
{
	v+=n1-1;
	drzewo[v]=najp1[v]=najp2[v]=najp21[v]=najl1[v]=najl2[v]=najl12[v]=0;
	if (na==1)
		najp1[v]=najl1[v]=najl12[v]=najp21[v]=1;
	if (na==2)
		najp2[v]=najl2[v]=najp21[v]=najl12[v]=1;
	if (na)
		drzewo[v]=1;
	v>>=1;
	int r=1;
	while(v)
	{
		upd(v, r);
		v>>=1;
		r<<=1;
	}
}

void wykonaj(int l, int p, long long war)
{
	rzuc(1, 1, n1, l, p, war);
	if (l>1)
	{
		long long raz=spytaj(l-1);
		long long dwa=spytaj(l);
		if (raz<dwa)
			zmien(l-1, 2);
		if (raz==dwa)
			zmien(l-1, 0);
		if (raz>dwa)
			zmien(l-1, 1);
	}
	if (p<n)
	{
		long long raz=spytaj(p);
		long long dwa=spytaj(p+1);
		if (raz<dwa)
			zmien(p, 2);
		if (raz==dwa)
			zmien(p, 0);
		if (raz>dwa)
			zmien(p, 1);
	}
}

int main()
{
	scanf("%d", &n);
	n1=potenga(n);
	for (int i=1; i<=n; i++)
	{
		int p1;
		scanf("%d", &p1);
		wykonaj(i, i, p1);
	}
	scanf("%d", &q);
	while(q--)
	{
		int p1, p2;
		long long p3;
		scanf("%d%d%lld", &p1, &p2, &p3);
		wykonaj(p1, p2, p3);
		printf("%d\n", drzewo[1]+1);
	}
	return 0;
}
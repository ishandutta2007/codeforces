#include <bits/stdc++.h>
using namespace std;

int n, m;

bitset <2007> tab[2007];
int pie[2007];

int zap[2007][2007];

int wyn[1000007];

void dodaj(vector < bitset<2007> > &mam, bitset <2007> chce)
{
	for (int i=0; i<n; i++)
		if (chce[i] && mam[i][i])
			chce^=mam[i];
	for (int i=0; i<n; i++)
	{
		if (chce[i])
		{
			for (int j=0; j<i; j++)
				if (mam[j][i])
					mam[j]^=chce;
			mam[i]=chce;
			return;
		}
	}
}

void rek(int l, int p, vector < bitset<2007> > &mam)
{
	if (l==p)
	{
		int gdz=0;
		for (int i=0; i<n; i++)
			if (!mam[i][i])
				gdz=i;
		mam[gdz]=tab[l];
		for (int i=0; i<n; i++)
			if (mam[gdz][i] && gdz!=i)
				mam[gdz]^=mam[i];
		for (int i=0; i<n; i++)
		{
			if (!zap[l][i] || i==gdz)
				continue;
			wyn[zap[l][i]]=(!mam[i][gdz]);
		}
		return;
	}
	vector < bitset<2007> > jed, dwa;
	jed=mam;
	dwa=mam;
	int s=(l+p)/2;
	for (int i=s+1; i<=p; i++)
		dodaj(jed, tab[i]);
	for (int i=l; i<=s; i++)
		dodaj(dwa, tab[i]);
	rek(l, s, jed);
	rek(s+1, p, dwa);
}

inline int czytaj()
{
	int ret=0;
	char pom;
	while(1)
	{
		pom=getchar();
		if (pom>='0' && pom<='9')
			ret=ret*10+pom-'0';
		else
			break;
	}
	return ret;
}

int per1[2007];
int per2[2007];

int main()
{
	n=czytaj();
	m=czytaj();
	for (int i=0; i<n; i++)
		per1[i]=per2[i]=i;
	random_shuffle(per1, per1+n);
	random_shuffle(per2, per2+n);
	for (int i=1; i<=m; i++)
	{
		int p1, p2;
		p1=czytaj();
		p2=czytaj();
		p1--;
		p2--;
		p1=per1[p1];
		p2=per2[p2];
		zap[p1][p2]=i;
		tab[p1][p2]=1;
	}
	vector < bitset<2007> > start;
	for (int i=0; i<n; i++)
		start.push_back(tab[n]);
	rek(0, n-1, start);
	for (int i=1; i<=m; i++)
	{
		if (wyn[i])
		{
			putchar('Y');
			putchar('E');
			putchar('S');
			putchar('\n');
		}
		else
		{
			putchar('N');
			putchar('O');
			putchar('\n');
		}
	}
	return 0;
}
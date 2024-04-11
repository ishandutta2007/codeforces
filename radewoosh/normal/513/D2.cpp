#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int n, m;
int p1, p2;
char wcz[10];
vector <int> lew[1000007];
vector <int> pra[1000007];

int n1;
vector <int> in;
int drzewo[2100000];
int czy=1;

int potenga(int v)
{
	for (int i=1; 1; i*=2)
	{
		if (i>=v)
		{
			return i;
		}
	}
}

void pisz(int v, int war)
{
	v+=n1-1;
	drzewo[v]=war;
	v>>=1;
	while(v)
	{
		drzewo[v]=max(drzewo[v<<1], drzewo[(v<<1)+1]);
		v>>=1;
	}
}

int czyt(int v, int a, int b, int graa, int grab)
{
	if (graa>grab)
	{
		return 0;
	}
	if (a>=graa && b<=grab)
	{
		return drzewo[v];
	}
	if (a>grab || b<graa)
	{
		return 0;
	}
	return max(czyt(v<<1, a, (a+b)>>1, graa, grab) , czyt((v<<1)+1, (a+b+2)>>1, b, graa, grab));
}

void rek(int v, int b)
{
	if (!lew[v].empty() && lew[v].back()>b)
	{
		czy=0;
	}
	if (!pra[v].empty() && pra[v].back()>b)
	{
		czy=0;
	}
	if (v==b)
	{
		in.push_back(v);
		return;
	}
	if (lew[v].empty() && pra[v].empty())
	{
		in.push_back(v);
		rek(v+1, b);
		return;
	}
	if (lew[v].empty())
	{
		in.push_back(v);
		rek(v+1, b);
		return;
	}
	if (pra[v].empty())
	{
		rek(v+1, b);
		in.push_back(v);
		return;
	}
	int p3=czyt(1, 1, n1, v+1, lew[v].back());
	if (p3>=pra[v][0])
	{
		czy=0;
	}
	rek(v+1, p3);
	in.push_back(v);
	if (p3<b)
	rek(p3+1, b);
}

int main()
{
	scanf("%d%d", &n, &m);
	n1=potenga(n);
	for (int i=1; i<=m; i++)
	{
		scanf("%d%d%s", &p1, &p2, &wcz);
		if (p2<=p1)
		{
			printf("IMPOSSIBLE");
			return 0;
		}
		if (wcz[0]=='L')
		{
			lew[p1].push_back(p2);
		}
		else
		{
			pra[p1].push_back(p2);
		}
	}
	for (int i=1; i<=n; i++)
	{
		sort(lew[i].begin(), lew[i].end());
		sort(pra[i].begin(), pra[i].end());
		if (!lew[i].empty() && !pra[i].empty() && lew[i].back()>=pra[i][0])
		{
			printf("IMPOSSIBLE");
			return 0;
		}
	}
	for (int i=n; i; i--)
	{
		p1=0;
		if (!lew[i].empty())
		p1=max(p1, lew[i].back());
		if (!pra[i].empty())
		p1=max(p1, pra[i].back());
		pisz(i, max(i, czyt(1, 1, n1, i, p1)));
		//printf("%d %d\n", i, czyt(1, 1, n1, i, i));
	}
	rek(1, n);
	if (!czy)
	{
		printf("IMPOSSIBLE");
		return 0;
	}
	for (int i=0; i<in.size(); i++)
	{
		printf("%d ", in[i]);
	}
	return 0;
}
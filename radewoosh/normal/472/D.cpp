#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

struct pun
{
	int odl;
	int a;
	int b;
	pun()
	{
		odl=a=b=0;
	}
	pun(int aa, int bb, int oo)
	{
		a=aa;
		b=bb;
		odl=oo;
	}
};

bool operator < (pun a, pun b)
{
	return a.odl<b.odl;
}

int n;
int tab[2007][2007];
int now[2007][2007];
int oj[2007];
vector <int> graf[2007];
vector <pun> dos;

int find(int x)
{
	if (x!=oj[x])
	{
		oj[x]=find(oj[x]);
	}
	return oj[x];
}

void uni(int a, int b)
{
	if (find(a)!=find(b))
	{
		oj[find(a)]=b;
	}
}

void dfs(int v, int ojj, int odl, int sta)
{
	now[sta][v]=odl;
	for (int i=0; i<graf[v].size(); i++)
	{
		if (graf[v][i]!=ojj)
		{
			dfs(graf[v][i], v, odl+tab[v][graf[v][i]], sta);
		}
	}
}

int main()
{
	scanf("%d", &n);
	for (int i=1; i<=n; i++)
	{
		oj[i]=i;
		for (int j=1; j<=n; j++)
		{
			scanf("%d", &tab[i][j]);
		}
	}
	for (int i=1; i<=n; i++)
	{
		for (int j=1; j<=n; j++)
		{
			if (i==j)
			{
				if (tab[i][j])
				{
					printf("NO");
					return 0;
				}
			}
			else
			{
				if (tab[i][j]!=tab[j][i] || !tab[i][j])
				{
					printf("NO");
					return 0;
				}
			}
		}
	}
	for (int i=1; i<=n; i++)
	{
		for (int j=1; j<i; j++)
		{
			dos.push_back(pun(i, j, tab[i][j]));
		}
	}
	sort(dos.begin(), dos.end());
	for (int i=0; i<dos.size(); i++)
	{
		if (find(dos[i].a)!=find(dos[i].b))
		{
			uni(dos[i].a, dos[i].b);
			graf[dos[i].a].push_back(dos[i].b);
			graf[dos[i].b].push_back(dos[i].a);
		}
	}
	for (int i=1; i<=n; i++)
	{
		dfs(i, 0, 0, i);
	}
	for (int i=1; i<=n; i++)
	{
		for (int j=1; j<=n; j++)
		{
			if (now[i][j]!=tab[i][j])
			{
				printf("NO");
				return 0;
			}
		}
	}
	printf("YES");
	return 0;
}
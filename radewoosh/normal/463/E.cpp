#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int n, q;
int val[2000007];
vector <int> graf[2000007];
int oj[2000007];
vector <int> dal[2000007];
int p1, p2;
vector <int> dziel;
int wyn[2000007];
int sito[2000007];
int value;
int ile;
int pre[2000007];

void paczaj(int v)
{
	ile++;
	pre[v]=ile;
	for (int i=0; i<graf[v].size(); i++)
	{
		if (oj[v]!=graf[v][i])
		{
			oj[graf[v][i]]=v;
			paczaj(graf[v][i]);
		}
	}
}

void podz(int war)
{
	dziel.clear();
	int it=war;
	while(it>1)
	{
		dziel.push_back(sito[it]);
		it/=sito[it];
	}
}

void dfs(int v)
{
	podz(val[v]);
	for (int i=0; i<dziel.size(); i++)
	{
		if (!dal[dziel[i]].empty())
		{
			if (wyn[v]==-1 || pre[dal[dziel[i]].back()]>pre[wyn[v]])
			{
				wyn[v]=dal[dziel[i]].back();
			}
		}
	}
	for (int i=0; i<dziel.size(); i++)
	{
		dal[dziel[i]].push_back(v);
	}
	for (int i=0; i<graf[v].size(); i++)
	{
		if (oj[v]!=graf[v][i])
		{
			dfs(graf[v][i]);
		}
	}
	podz(val[v]);
	for (int i=0; i<dziel.size(); i++)
	{
		dal[dziel[i]].pop_back();
	}
}

void popraw()
{
	for (int i=1; i<=n; i++)
	{
		wyn[i]=-1;
	}
	dfs(1);
}

int main()
{
	scanf("%d%d", &n, &q);
	for (int i=1; i<=n; i++)
	{
		scanf("%d", &val[i]);
		value=max(value, val[i]);
	}
	value=2000003;
	for (int i=1; i<n; i++)
	{
		scanf("%d%d", &p1, &p2);
		graf[p1].push_back(p2);
		graf[p2].push_back(p1);
	}
	paczaj(1);
	for (int i=2; i<=value; i++)
	{
		if(!sito[i])
		{
			for (int j=i; j<=value; j+=i)
			{
				sito[j]=i;
			}
		}
	}
	popraw();
	for (int i=1; i<=q; i++)
	{
		scanf("%d", &p1);
		{
			if (p1==1)
			{
				scanf("%d", &p1);
				printf("%d\n", wyn[p1]);
			}
			else
			{
				scanf("%d%d", &p1, &p2);
				val[p1]=p2;
				popraw();
			}
		}
	}
	return 0;
}
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;

int n, k;
int per[1007][7];
int rank[1007][7];
vector <int> graf[1007];
vector <int> oj[1007];
bool bida;
int wyn;
queue <int> bfs;
int wcho[1007];
int v;
int dlu[1007];

int main()
{
	scanf("%d%d", &n, &k);
	for (int i=1; i<=k; i++)
	{
		for (int j=1; j<=n; j++)
		{
			scanf("%d", &per[j][i]);
			rank[per[j][i]][i]=j;
		}
	}
	for (int i=1; i<=n; i++)
	{
		for (int j=1; j<i; j++)
		{
			wyn=(rank[i][1]>rank[j][1]);
			bida=false;
			for (int h=2; h<=k; h++)
			{
				if ((rank[i][h]>rank[j][h])!=wyn)
				bida=true;
			}
			if (!bida)
			{
				if (wyn)
				{
					graf[j].push_back(i);
					oj[i].push_back(j);
				}
				else
				{
					graf[i].push_back(j);
					oj[j].push_back(i);
				}
			}
		}
	}
	for (int i=1; i<=n; i++)
	{
		for (int j=0; j<graf[i].size(); j++)
		{
			wcho[graf[i][j]]++;
		}
	}
	for (int i=1; i<=n; i++)
	{
		if (!wcho[i])
		{
			bfs.push(i);
		}
	}
	while(!bfs.empty())
	{
		v=bfs.front();
		bfs.pop();
		dlu[v]++;
		wyn=max(wyn, dlu[v]);
		for (int i=0; i<graf[v].size(); i++)
		{
			dlu[graf[v][i]]=max(dlu[graf[v][i]], dlu[v]);
			wcho[graf[v][i]]--;
			if (!wcho[graf[v][i]])
			bfs.push(graf[v][i]);
		}
	}
	printf("%d", wyn);
	return 0;
}
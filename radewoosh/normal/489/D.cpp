#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
vector <int> graf[3007];
long long wyn;
int p1, p2;
vector <int> wek;
long long ile[3007];
int v;

void czy()
{
	for (int i=1; i<=n; i++)
	ile[i]=0;
}

int main()
{
	scanf("%d%d", &n, &m);
	for (int i=1; i<=m; i++)
	{
		scanf("%d%d", &p1, &p2);
		graf[p1].push_back(p2);
	}
	for (int i=1; i<=n; i++)
	{
		czy();
		for (int j=0; j<graf[i].size(); j++)
		{
			v=graf[i][j];
			for (int k=0; k<graf[v].size(); k++)
			{
				ile[graf[v][k]]++;
			}
		}
		for (int j=1; j<=n; j++)
		{
			if (i==j)
			continue;
			wyn+=(ile[j]*(ile[j]-1))/2;
		}
	}
	printf("%lld", wyn);
	return 0;
}
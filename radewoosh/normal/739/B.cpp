#include <bits/stdc++.h>
using namespace std;

int n;

long long tab[1000007];

int oj[1000007];
vector <int> graf[1000007];
long long nad[1000007];
long long odl[1000007];

long long wyn[1000007];

vector <int> scie;

long long w;

void dfs(int v)
{
	if (v!=1)
	{
		if (nad[v]<=tab[v])
		{
			int bsa=0;
			int bsb=scie.size()-1;
			int bss;
			while(bsa<bsb)
			{
				bss=(bsa+bsb)/2;
				if (odl[v]-odl[scie[bss]]<=tab[v])
					bsb=bss;
				else
					bsa=bss+1;
			}
			wyn[v]++;
			wyn[scie[bsb]]--;
		}
	}
	scie.push_back(v);
	for (int i=0; i<graf[v].size(); i++)
	{
		odl[graf[v][i]]=odl[v]+nad[graf[v][i]];
		dfs(graf[v][i]);
		wyn[v]+=wyn[graf[v][i]];
	}
	scie.pop_back();
}

int main()
{
	scanf("%d", &n);
	for (int i=1; i<=n; i++)
		scanf("%lld", &tab[i]);
	for (int i=2; i<=n; i++)
	{
		scanf("%d%lld", &oj[i], &nad[i]);
		graf[oj[i]].push_back(i);
	}
	dfs(1);
	for (int i=1; i<=n; i++)
	{
		w=0;
		for (int j=0; j<graf[i].size(); j++)
			w+=wyn[graf[i][j]];
		printf("%lld ", w);
	}
	printf("\n");
	return 0;
}
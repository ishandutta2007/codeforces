#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int n, d;
int tab[2007];
vector <int> graf[2007];
int p1, p2;
int wyl[2007];
long long wyn;
long long mod=1000000007;
int licz;
int start;

long long dfs(int v, int oj)
{
	long long moz=1;
	if (tab[v]>licz || licz-tab[v]>d || (tab[v]==licz && v<start))
	return 1;
	for (int i=0; i<graf[v].size(); i++)
	{
		if (oj==graf[v][i])
		continue;
		moz*=dfs(graf[v][i], v);
		moz%=mod;
	}
	//printf("%d %lld\n", v, moz);
	return (moz+1)%mod;
}

int main()
{
	scanf("%d%d", &d, &n);
	for (int i=1; i<=n; i++)
	{
		scanf("%d", &tab[i]);
	}
	for (int i=1; i<n; i++)
	{
		scanf("%d%d", &p1, &p2);
		graf[p1].push_back(p2);
		graf[p2].push_back(p1);
	}
	for (int i=1; i<=n; i++)
	{
		if (!wyl[i])
		{
			//printf("%d\n", i);
			licz=tab[i];
			start=i;
			wyn+=dfs(i, i)-1;
			wyn%=mod;
			//printf("%lld\n", wyn);
		}
	}
	printf("%lld", wyn);
	return 0;
}
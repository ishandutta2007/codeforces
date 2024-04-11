#include <bits/stdc++.h>
using namespace std;

int q;

int l=1000000;

int sito[1000007];

long long mod=1000000007;
long long f[1000007];

int r[1000007][20];
int g[1000007][20];

int rodz[1000007];

vector <int> wek[1000007];

long long wyn;

int main()
{
	for (int i=2; i<=l; i++)
	{
		if (!sito[i])
		{
			for (int j=i; j<=l; j+=i)
			{
				f[j]++;
				sito[j]=i;
			}
		}
	}
	for (int i=1; i<=l; i++)
	{
		int ost=-1;
		int v=i;
		while(v>1)
		{
			if (sito[v]!=ost)
				wek[i].push_back(0);
			wek[i].back()++;
			ost=sito[v];
			v/=sito[v];
		}
	}
	r[0][0]=1;
	for (int i=1; i<=l; i++)
	{
		r[i][0]=1;
		for (int j=1; j<20; j++)
			r[i][j]=(r[i-1][j]+r[i][j-1])%mod;
	}
	for (int i=0; i<20; i++)
		g[0][i]=min(i, 1)+1;
	for (int i=1; i<=l; i++)
	{
		g[i][0]=1;
		for (int j=1; j<20; j++)
			g[i][j]=((long long)g[i][j-1]+r[i][j]+r[i][j-1])%mod;
	}
	scanf("%d", &q);
	for (int i=1; i<=q; i++)
	{
		int p1, p2;
		scanf("%d%d", &p1, &p2);
		wyn=1;
		for (int i=0; i<wek[p2].size(); i++)
			wyn=(wyn*g[p1][wek[p2][i]])%mod;
		printf("%lld\n", wyn);
	}
	return 0;
}
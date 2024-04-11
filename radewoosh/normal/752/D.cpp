#include <bits/stdc++.h>
using namespace std;

int n, k;

char wcz[1000007];
char wcz2[1000007];

long long h=100003;
long long mod1=1000000007;
long long mod2=1000000009;

long long p1[1000007];
long long p2[1000007];
long long t1[1000007];
long long t2[1000007];
long long w[1000007];
int pal[1000007];

int tak[1000007];

int dos[1000007];

long long wyn;

map < pair <long long,long long> , queue <int> > mapa;

long long mak;

bool mniej(int a, int b)
{
	return w[a]>w[b];
}

int main()
{
	scanf("%d%d", &n, &k);
	for (int i=1; i<=n; i++)
	{
		scanf("%s%lld", wcz+1, &w[i]);
		for (int j=1; j<=k; j++)
		{
			wcz2[j]=wcz[k+1-j];
			p1[i]=(p1[i]*h+wcz[j])%mod1;
			p2[i]=(p2[i]*h+wcz[j])%mod2;
		}
		for (int j=k; j; j--)
		{
			t1[i]=(t1[i]*h+wcz[j])%mod1;
			t2[i]=(t2[i]*h+wcz[j])%mod2;
		}
		pal[i]=1;
		for (int j=1; j<=k; j++)
			if (wcz2[j]!=wcz[j])
				pal[i]=0;
		dos[i]=i;
	}
	sort(dos+1, dos+1+n, mniej);
	for (int i=1; i<=n; i++)
	{
		int x=dos[i];
		if (!mapa[{p1[x], p2[x]}].empty() && w[x]+w[mapa[{p1[x], p2[x]}].front()]>=0)
		{
			int y=mapa[{p1[x], p2[x]}].front();
			mapa[{p1[x], p2[x]}].pop();
			wyn+=w[x]+w[y];
			tak[x]=1;
			tak[y]=1;
		}
		else
		{
			mapa[{t1[x], t2[x]}].push(x);
		}
	}
	for (int i=1; i<=n; i++)
	{
		if (!pal[i])
			continue;
		if (tak[i])
			mak=max(mak, -w[i]);
		else
			mak=max(mak, w[i]);
	}
	wyn+=mak;
	printf("%lld\n", wyn);
	return 0;
}
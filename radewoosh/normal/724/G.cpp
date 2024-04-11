#include <bits/stdc++.h>
using namespace std;

int n, m;

vector < pair <int,long long> > graf[1000007];

int d=60;
long long eli[70];
long long ilez[70];
long long ileb[70];
long long jed=1;

int bylo[1000007];
long long xo[1000007];

long long ilegz[70];
long long ilegb[70];

long long wyn;
long long mod=1000000007;

int naj(long long v)
{
	int ret=-1;
	while(v)
	{
		v/=2;
		ret++;
	}
	return ret;
}

void dodaj(long long v)
{
	for (int i=0; i<d; i++)
		if (v&(jed<<i))
			v^=eli[i];
	if (!v)
		return;
	int kt=naj(v);
	eli[kt]=v;
	for (int i=0; i<d; i++)
		if (i!=kt && (eli[i]&(jed<<kt)))
			eli[i]^=v;
}

void dfs(int v)
{
	for (int i=0; i<d; i++)
	{
		if (xo[v]&(jed<<i))
			ilegz[i]++;
		else
			ilegb[i]++;
	}
	bylo[v]=1;
	for (int i=0; i<graf[v].size(); i++)
	{
		if (bylo[graf[v][i].first])
		{
			dodaj(xo[v]^xo[graf[v][i].first]^graf[v][i].second);
		}
		else
		{
			xo[graf[v][i].first]=xo[v]^graf[v][i].second;
			dfs(graf[v][i].first);
		}
	}
}

void rob(int v)
{
	for (int i=0; i<d; i++)
	{
		eli[i]=0;
		ileb[i]=0;
		ilez[i]=0;
		ilegb[i]=0;
		ilegz[i]=0;
	}
	dfs(v);
	for (int i=0; i<d; i++)
	{
		int ma=0, niema=0;
		for (int j=0; j<d; j++)
		{
			if (!eli[j])
				continue;
			if (eli[j]&(jed<<i))
				ma++;
			else
				niema++;
		}
		if (!ma)
			ileb[i]=1;
		else
			ileb[i]=ilez[i]=(jed<<(ma-1));
		ileb[i]*=(jed<<niema);
		ilez[i]*=(jed<<niema);
		ileb[i]%=mod;
		ilez[i]%=mod;
	}
	for (int i=0; i<d; i++)
	{
		long long dwat=(ilegb[i]*(ilegb[i]-1))/2+(ilegz[i]*(ilegz[i]-1))/2;
		dwat%=mod;
		wyn+=((dwat*ilez[i])%mod)*((jed<<i)%mod);
		long long dwar=ilegb[i]*ilegz[i];
		dwar%=mod;
		wyn+=((dwar*ileb[i])%mod)*((jed<<i)%mod);
		wyn%=mod;
	}
}

int main()
{
	scanf("%d%d", &n, &m);
	for (int i=1; i<=m; i++)
	{
		int p1, p2;
		long long p3;
		scanf("%d%d%lld", &p1, &p2, &p3);
		graf[p1].push_back(make_pair(p2, p3));
		graf[p2].push_back(make_pair(p1, p3));
	}
	for (int i=1; i<=n; i++)
		if (!bylo[i])
			rob(i);
	printf("%lld\n", wyn);
	return 0;
}
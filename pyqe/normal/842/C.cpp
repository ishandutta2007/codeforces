#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,nn[200069],a[200069],pr[200069],sq[200069];
vector<long long> al[200069];
bitset<200069> vtd;
pair<long long,long long> sk[200069][20];

void dfs(long long x)
{
	long long i,sz=al[x].size(),k,l,w;
	
	vtd[x]=1;
	for(i=1;i<=nn[pr[x]];i++)
	{
		sk[x][i]=sk[pr[x]][i];
	}
	sk[x][nn[pr[x]]+1]={x,0};
	for(i=1;i<=nn[pr[x]]+1;i++)
	{
		k=sk[x][i].fr;
		w=__gcd(sk[x][i].sc,a[x]);
		nn[x]+=w!=sk[x][nn[x]].sc;
		sk[x][nn[x]]={k,w};
	}
	sk[x][nn[x]+1].sc=0;
	sq[x]=sk[x][1].sc;
	for(i=1;i<=nn[x];i++)
	{
		k=pr[sk[x][i].fr];
		sq[x]=max(sq[x],__gcd(sk[x][i+1].sc,sk[k][1].sc));
	}
	for(i=0;i<sz;i++)
	{
		l=al[x][i];
		if(!vtd[l])
		{
			pr[l]=x;
			dfs(l);
		}
	}
}

int main()
{
	long long i,k,l;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
	}
	for(i=0;i<n-1;i++)
	{
		scanf("%lld%lld",&k,&l);
		al[k].push_back(l);
		al[l].push_back(k);
	}
	dfs(1);
	for(i=1;i<=n;i++)
	{
		printf("%lld%c",sq[i]," \n"[i==n]);
	}
}
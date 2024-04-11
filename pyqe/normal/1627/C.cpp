#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,dg[100069],dh[100069],sq[100069];
vector<pair<long long,long long>> al[100069];
bitset<100069> vtd;

void dfs(long long x)
{
	long long i,sz=al[x].size(),l,p;
	
	vtd[x]=1;
	for(i=0;i<sz;i++)
	{
		l=al[x][i].fr;
		p=al[x][i].sc;
		if(!vtd[l])
		{
			dh[l]=dh[x]+1;
			dfs(l);
			sq[p]=dh[x]%2+2;
		}
	}
}

int main()
{
	long long t,rr,i,ii,k,l,e;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		for(i=1;i<=n;i++)
		{
			al[i].clear();
			dg[i]=0;
			vtd[i]=0;
		}
		for(i=1;i<=n-1;i++)
		{
			scanf("%lld%lld",&k,&l);
			for(ii=0;ii<2;ii++)
			{
				al[k].push_back({l,i});
				dg[k]++;
				swap(k,l);
			}
		}
		for(i=1;i<=n;i++)
		{
			if(dg[i]>2)
			{
				break;
			}
			if(dg[i]==1)
			{
				e=i;
			}
		}
		if(i<=n)
		{
			printf("-1\n");
			continue;
		}
		dh[e]=0;
		dfs(e);
		for(i=1;i<=n-1;i++)
		{
			printf("%lld%c",sq[i]," \n"[i==n-1]);
		}
	}
}
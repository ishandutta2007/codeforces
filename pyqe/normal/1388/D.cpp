#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,a[200069],pr[200069],dh[200069],sq[200069],zs=0;
vector<long long> al[200069];
priority_queue<pair<long long,long long>> pq;

void dfs(long long x)
{
	long long i,sz=al[x].size(),l;
	
	if(a[x]>=0)
	{
		pq.push({dh[x],x});
	}
	for(i=0;i<sz;i++)
	{
		l=al[x][i];
		dh[l]=dh[x]+1;
		dfs(l);
	}
}

int main()
{
	long long i,k,z=0;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
	}
	for(i=1;i<=n;i++)
	{
		scanf("%lld",pr+i);
		al[pr[i]].push_back(i);
	}
	for(i=1;i<=n;i++)
	{
		if(pr[i]==-1)
		{
			dfs(i);
		}
	}
	for(;!pq.empty();)
	{
		k=pq.top().sc;
		pq.pop();
		z+=a[k];
		zs++;
		sq[zs]=k;
		if(pr[k]!=-1)
		{
			a[pr[k]]+=a[k];
			if(a[pr[k]]>=0&&a[pr[k]]-a[k]<0)
			{
				pq.push({dh[pr[k]],pr[k]});
			}
		}
	}
	for(i=1;i<=n;i++)
	{
		if(a[i]<0)
		{
			pq.push({-dh[i],i});
		}
	}
	for(;!pq.empty();)
	{
		k=pq.top().sc;
		pq.pop();
		z+=a[k];
		zs++;
		sq[zs]=k;
	}
	printf("%lld\n",z);
	for(i=1;i<=n;i++)
	{
		printf("%lld%c",sq[i]," \n"[i==n]);
	}
}
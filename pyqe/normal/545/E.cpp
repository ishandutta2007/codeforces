#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,m,nr[300069],sq[300069],zs=0,inf=1e18;
vector<pair<long long,pair<long long,long long>>> al[300069];
priority_queue<pair<long long,long long>> pq;
pair<long long,long long> mx[300069];

int main()
{
	long long i,k,l,w,p,sz,ww,z=0;
	
	scanf("%lld%lld",&n,&m);
	for(i=1;i<=m;i++)
	{
		scanf("%lld%lld%lld",&k,&l,&w);
		al[k].push_back({l,{w,i}});
		al[l].push_back({k,{w,i}});
	}
	for(i=1;i<=n;i++)
	{
		nr[i]=inf;
	}
	scanf("%lld",&k);
	pq.push({0,k});
	nr[k]=0;
	for(;!pq.empty();)
	{
		w=-pq.top().fr;
		k=pq.top().sc;
		pq.pop();
		if(w>nr[k])
		{
			continue;
		}
		sz=al[k].size();
		for(i=0;i<sz;i++)
		{
			l=al[k][i].fr;
			ww=al[k][i].sc.fr;
			p=al[k][i].sc.sc;
			if(w+ww<nr[l])
			{
				pq.push({-w-ww,l});
				nr[l]=w+ww;
				mx[l].fr=inf;
			}
			if(w+ww==nr[l])
			{
				mx[l]=min(mx[l],{ww,p});
			}
		}
	}
	for(i=1;i<=n;i++)
	{
		z+=mx[i].fr;
		if(mx[i].sc)
		{
			zs++;
			sq[zs]=mx[i].sc;
		}
	}
	printf("%lld\n",z);
	for(i=1;i<=zs;i++)
	{
		printf("%lld%c",sq[i]," \n"[i==n]);
	}
}
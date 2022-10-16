#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,m,pr[100069],nr[100069],z=0;
vector<pair<long long,long long>> al[100069];
priority_queue<pair<long long,long long>> pq;
vector<long long> v;

int main()
{
	long long i,k,l,w,sz,ww;
	
	scanf("%lld%lld",&n,&m);
	for(i=0;i<m;i++)
	{
		scanf("%lld%lld%lld",&k,&l,&w);
		al[k].push_back({l,w});
		al[l].push_back({k,w});
	}
	for(i=1;i<=n;i++)
	{
		pr[i]=0;
		nr[i]=1e18;
	}
	pq.push({0,1});
	nr[1]=0;
	for(;!pq.empty();)
	{
		k=pq.top().sc;
		w=-pq.top().fr;
		pq.pop();
		if(w>nr[k])
		{
			continue;
		}
		sz=al[k].size();
		for(i=0;i<sz;i++)
		{
			l=al[k][i].fr;
			ww=al[k][i].sc;
			if(w+ww<nr[l])
			{
				pq.push({-w-ww,l});
				nr[l]=w+ww;
				pr[l]=k;
			}
		}
	}
	if(!pr[n])
	{
		printf("-1\n");
	}
	else
	{
		for(i=n;i;i=pr[i])
		{
			v.push_back(i);
			z++;
		}
		for(i=z-1;i>=0;i--)
		{
			printf("%lld%c",v[i]," \n"[i==0]);
		}
	}
}
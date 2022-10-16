#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,m,d,fq[100069],nr[100069];
vector<pair<long long,pair<long long,long long>>> al[100069];
priority_queue<pair<long long,long long>> pq;
bitset<100069> pr;

int main()
{
	long long i,k,l,w,e,sz,ww,z=0;
	
	scanf("%lld%lld%lld",&n,&m,&d);
	for(i=0;i<m;i++)
	{
		scanf("%lld%lld%lld",&k,&l,&w);
		al[k].push_back({l,{w,1}});
		al[l].push_back({k,{w,1}});
	}
	for(i=0;i<d;i++)
	{
		scanf("%lld%lld",&k,&w);
		fq[k]++;
		al[1].push_back({k,{w,0}});
		al[k].push_back({1,{w,0}});
	}
	for(i=1;i<=n;i++)
	{
		nr[i]=1e18;
	}
	pq.push({0,1});
	nr[1]=1;
	pr[1]=1;
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
			ww=al[k][i].sc.fr;
			e=al[k][i].sc.sc;
			if(w+ww<nr[l])
			{
				pq.push({-w-ww,l});
				nr[l]=w+ww;
				pr[l]=0;
			}
			if(w+ww==nr[l])
			{
				pr[l]=pr[l]|e;
			}
		}
	}
	for(i=1;i<=n;i++)
	{
		z+=fq[i]-!pr[i];
	}
	printf("%lld\n",z);
}
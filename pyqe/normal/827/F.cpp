#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,m,od[500069][2];
pair<long long,long long> rg[500069];
vector<pair<long long,pair<long long,long long>>> al[500069];
priority_queue<pair<long long,pair<long long,long long>>> pq;

int main()
{
	long long i,ii,k,l,w,sz,p,e,k2,l2,p2,k3,l3;
	
	scanf("%lld%lld",&n,&m);
	for(i=1;i<=m;i++)
	{
		scanf("%lld%lld%lld%lld",&k,&l,&k2,&l2);
		rg[i]={k2,l2};
		for(ii=0;ii<2;ii++)
		{
			al[k].push_back({k2,{l,i}});
			swap(k,l);
		}
	}
	for(i=1;i<=n;i++)
	{
		sort(al[i].begin(),al[i].end());
	}
	pq.push({0,{1,-1}});
	for(;!pq.empty();)
	{
		w=-pq.top().fr;
		k=pq.top().sc.fr;
		p=pq.top().sc.sc;
		pq.pop();
		if(k==n)
		{
			printf("%lld\n",w);
			return 0;
		}
		e=w%2;
		if(p==-1)
		{
			k2=w;
			l2=w;
		}
		else
		{
			l=al[k][p].sc.fr;
			p2=al[k][p].sc.sc;
			if(w+1<=rg[p2].sc)
			{
				pq.push({-w-1,{l,-1}});
			}
			k2=w;
			l2=(rg[p2].sc-e)/2*2+e;
		}
		sz=al[k].size();
		for(;od[k][e]<sz&&al[k][od[k][e]].fr<=l2;od[k][e]++)
		{
			p2=al[k][od[k][e]].sc.sc;
			k3=rg[p2].fr;
			l3=rg[p2].sc;
			if(l3<k2)
			{
				continue;
			}
			pq.push({-max(k2,(k3-e+1)/2*2+e),{k,od[k][e]}});
		}
	}
	printf("-1\n");
}
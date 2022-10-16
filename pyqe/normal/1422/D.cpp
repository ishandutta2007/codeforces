#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long ln,n,ys,xs,yf,xf,nr[100069],inf=1e18;
pair<long long,long long> a[100069],as[2][100069];
vector<pair<long long,long long>> al[100069];
priority_queue<pair<long long,long long>> pq;

int main()
{
	long long i,ii,k,l,w,sz,ww,z;
	
	scanf("%lld%lld%lld%lld%lld%lld",&ln,&n,&ys,&xs,&yf,&xf);
	for(i=1;i<=n;i++)
	{
		for(ii=0;ii<2;ii++)
		{
			scanf("%lld",&k);
			as[ii][i]={k,i};
			swap(k,l);
		}
		a[i]={k,l};
	}
	for(ii=0;ii<2;ii++)
	{
		sort(as[ii]+1,as[ii]+n+1);
		for(i=1;i<n;i++)
		{
			k=as[ii][i].sc;
			l=as[ii][i+1].sc;
			w=as[ii][i+1].fr-as[ii][i].fr;
			al[k].push_back({l,w});
			al[l].push_back({k,w});
		}
	}
	for(i=1;i<=n;i++)
	{
		nr[i]=min(abs(ys-a[i].fr),abs(xs-a[i].sc));
		pq.push({-nr[i],i});
	}
	z=abs(ys-yf)+abs(xs-xf);
	for(;!pq.empty();)
	{
		k=pq.top().sc;
		w=-pq.top().fr;
		pq.pop();
		if(w>nr[k])
		{
			continue;
		}
		z=min(z,w+abs(a[k].fr-yf)+abs(a[k].sc-xf));
		sz=al[k].size();
		for(i=0;i<sz;i++)
		{
			l=al[k][i].fr;
			ww=al[k][i].sc;
			if(w+ww<nr[l])
			{
				pq.push({-w-ww,l});
				nr[l]=w+ww;
			}
		}
	}
	printf("%lld\n",z);
}
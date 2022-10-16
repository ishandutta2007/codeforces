#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,m,aa[200069],a[200069],sl[200069];
priority_queue<pair<long long,long long>> pq;

int main()
{
	long long i,lh,rh,md,zz=-1,k,pz,c;
	
	scanf("%lld%lld",&n,&m);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",aa+i);
	}
	for(i=1;i<=n;i++)
	{
		scanf("%lld",sl+i);
	}
	for(lh=0,rh=2e12;lh<=rh;)
	{
		md=(lh+rh)/2;
		for(i=1;i<=n;i++)
		{
			a[i]=aa[i];
			k=a[i]/sl[i]+1;
			if(k<m)
			{
				pq.push({-k,i});
			}
		}
		for(c=1;!pq.empty();c++)
		{
			k=-pq.top().fr;
			pz=pq.top().sc;
			pq.pop();
			if(c>k)
			{
				c=-1;
				break;
			}
			a[pz]+=md;
			k=a[pz]/sl[pz]+1;
			if(k<m)
			{
				pq.push({-k,pz});
			}
		}
		for(;!pq.empty();pq.pop());
		if(c!=-1)
		{
			zz=md;
			rh=md-1;
		}
		else
		{
			lh=md+1;
		}
	}
	printf("%lld\n",zz);
}
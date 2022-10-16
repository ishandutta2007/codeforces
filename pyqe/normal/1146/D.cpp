#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,d1,d2,nr[100069],ft[100069];
priority_queue<pair<long long,long long>> pq;

long long sm(long long x,long long y)
{
	if(y<x)
	{
		return 0;
	}
	long long k;
	y-=x-1;
	k=(y-1)/d2+1;
	return k*(k+1)/2*d2-k*(k*d2-y);
}

int main()
{
	long long i,k,l,w,ws,ww,z;
	
	scanf("%lld%lld%lld",&n,&d1,&d2);
	z=n+1;
	for(i=1;i<=d2;i++)
	{
		nr[i]=1e18;
		ft[i]=1e18;
	}
	pq.push({-d1,(d1-1)%d2+1});
	nr[(d1-1)%d2+1]=d1;
	for(;!pq.empty();)
	{
		ws=-pq.top().fr;
		for(;!pq.empty();)
		{
			k=pq.top().sc;
			w=-pq.top().fr;
			if(w>ws)
			{
				break;
			}
			pq.pop();
			if(w>nr[k])
			{
				continue;
			}
			ft[k]=ws;
			ww=k+d1;
			l=(ww-1)%d2+1;
			if(ww<nr[l])
			{
				pq.push({-ww,l});
				nr[l]=ww;
			}
		}
	}
	for(i=1;i<=d2;i++)
	{
		z+=sm(i,n)-sm(i,min(ft[i]-1,n));
	}
	printf("%lld\n",z);
}
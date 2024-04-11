#include <bits/stdc++.h>

using namespace std;

long long n,m,d,sh=0;
priority_queue<long long> pq[2];

int main()
{
	long long i,ii,u,k,w,ti,ls=1,e,z=0;
	
	scanf("%lld%lld%lld",&n,&m,&d);
	for(i=0;i<m;i++)
	{
		scanf("%lld%lld%lld",&k,&w,&ti);
		z+=w;
		sh+=(ti-ls)*d;
		if(i)
		{
			z-=max(pq[0].top()-sh-k,0ll)+max(k+pq[1].top()-sh,0ll);
		}
		e=i&&k>pq[0].top()-sh;
		u=!e*2-1;
		for(ii=0;ii<2;ii++)
		{
			pq[e].push(k*u+sh);
		}
		k=(pq[e].top()-sh)*u;
		pq[!e].push(k*-u+sh);
		pq[e].pop();
		ls=ti;
	}
	printf("%lld\n",z);
}
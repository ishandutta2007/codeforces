#include <bits/stdc++.h>

using namespace std;

const long long inf=1e18;
long long n,m,ps[100069],sq[100069];

int main()
{
	long long t,rr,i,u,k,l,w,lz=0,p;
	
	scanf("%lld%lld%lld",&n,&m,&t);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&k);
		u=i%2*2-1;
		lz+=k*u;
	}
	for(i=1;i<=m;i++)
	{
		scanf("%lld",&k);
		u=i%2*2-1;
		ps[i]=ps[i-1]+k*u;
	}
	for(i=1;i<=m-n+1;i++)
	{
		u=i%2*2-1;
		sq[i]=(ps[i-1]-ps[i+n-1])*u;
	}
	sort(sq+1,sq+m-n+2);
	sq[0]=-inf;
	sq[m-n+2]=inf;
	for(rr=0;rr<=t;rr++)
	{
		if(rr)
		{
			scanf("%lld%lld%lld",&k,&l,&w);
			lz+=w*(l%2-(k-1)%2);
		}
		p=lower_bound(sq+1,sq+m-n+2,-lz)-sq;
		printf("%lld\n",min(sq[p]+lz,-lz-sq[p-1]));
	}
}
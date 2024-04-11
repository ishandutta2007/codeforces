#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,a[169],dh[169];

void rk(long long lh,long long rh,long long cdh)
{
	if(lh<=rh)
	{
		long long i,e;
		pair<long long,long long> mxe={0,-1};
		
		for(i=lh;i<=rh;i++)
		{
			mxe=max(mxe,{a[i],i});
		}
		e=mxe.sc;
		dh[e]=cdh;
		rk(lh,e-1,cdh+1);
		rk(e+1,rh,cdh+1);
	}
}

int main()
{
	long long t,rr,i;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		for(i=1;i<=n;i++)
		{
			scanf("%lld",a+i);
		}
		rk(1,n,0);
		for(i=1;i<=n;i++)
		{
			printf("%lld%c",dh[i]," \n"[i==n]);
		}
	}
}
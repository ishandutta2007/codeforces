#include <bits/stdc++.h>

using namespace std;

long long n,inf=1e18;

int main()
{
	long long t,rr,i,k,l,cr,tg,ti,lt,p,z;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		cr=0;
		ti=0;
		tg=0;
		lt=-inf;
		z=0;
		for(i=1;i<=n+1;i++)
		{
			if(i<=n)
			{
				scanf("%lld%lld",&k,&l);
			}
			else
			{
				k=inf;
				l=-inf;
			}
			if(abs(cr-tg)<=k-ti)
			{
				z+=lt>=min(cr,tg)&&lt<=max(cr,tg);
				cr=tg;
				tg=l;
			}
			else
			{
				p=cr+(k-ti)*((tg>cr)*2-1);
				z+=lt>=min(cr,p)&&lt<=max(cr,p);
				cr=p;
			}
			ti=k;
			lt=l;
		}
		printf("%lld\n",z);
	}
}
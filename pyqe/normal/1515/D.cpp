#include <bits/stdc++.h>

using namespace std;

long long n,d,d2,fq[200069];

int main()
{
	long long t,rr,i,ii,u,k,sm[2],c[2],e,z;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld%lld",&n,&d,&d2);
		for(i=1;i<=n;i++)
		{
			fq[i]=0;
		}
		for(i=1;i<=n;i++)
		{
			scanf("%lld",&k);
			u=!(i<=d)*2-1;
			fq[k]+=u;
		}
		for(ii=0;ii<2;ii++)
		{
			sm[ii]=0;
			c[ii]=0;
		}
		for(i=1;i<=n;i++)
		{
			e=fq[i]<0;
			sm[e]+=abs(fq[i]);
			c[e]+=abs(fq[i])%2;
		}
		z=0;
		k=min(c[0],c[1]);
		z+=k;
		for(ii=0;ii<2;ii++)
		{
			sm[ii]-=k;
			c[ii]-=k;
		}
		for(ii=0;ii<2;ii++)
		{
			k=min(c[ii],sm[!ii]);
			z+=k;
			sm[ii]-=k;
			c[ii]-=k;
			sm[!ii]-=k;
		}
		for(ii=0;ii<2;ii++)
		{
			z+=c[ii]/2;
		}
		z+=(sm[0]+sm[1])/2;
		printf("%lld\n",z);
	}
}
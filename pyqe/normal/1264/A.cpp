#include <bits/stdc++.h>

using namespace std;

long long n,fq[400069],ttl,z[3];

int main()
{
	long long t,rr,i,k,l,rh,ii;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&ttl);
		n=0;
		l=-1;
		for(i=1;i<=ttl;i++)
		{
			scanf("%lld",&k);
			if(k!=l)
			{
				n++;
				fq[n]=0;
			}
			fq[n]++;
			l=k;
		}
		for(k=0,rh=1;1;rh++)
		{
			k+=fq[rh];
			if(k>ttl/2)
			{
				break;
			}
		}
		z[0]=fq[1];
		for(ii=1;ii<3;ii++)
		{
			z[ii]=0;
		}
		for(ii=1,i=2;i<rh;i++)
		{
			z[ii]+=fq[i];
			if(ii==1&&z[ii]>z[0])
			{
				ii++;
			}
		}
		if(z[2]<=z[0])
		{
			printf("0 0 0\n");
		}
		else
		{
			for(ii=0;ii<3;ii++)
			{
				printf("%lld%c",z[ii]," \n"[ii==2]);
			}
		}
	}
}
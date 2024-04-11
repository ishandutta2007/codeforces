#include <bits/stdc++.h>

using namespace std;

long long n,sq[2069],zs;
bitset<2069> spc;

int main()
{
	long long t,rr,i,j,k,p,e,lh,rh,md,zz;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		spc.reset();
		for(i=1;i<n;i++)
		{
			printf("? 1 %lld\n%lld\n",n-i,i);
			for(j=i+1;j<=n;j++)
			{
				printf("%lld%c",j," \n"[j==n]);
			}
			fflush(stdout);
			scanf("%lld",&k);
			if(k)
			{
				break;
			}
		}
		spc[i]=1;
		p=i;
		e=abs(k)%2;
		for(zz=p,lh=1,rh=p-1;lh<=rh;)
		{
			md=(lh+rh)/2;
			printf("? 1 %lld\n%lld\n",md,p);
			for(i=1;i<=md;i++)
			{
				printf("%lld%c",i," \n"[i==md]);
			}
			fflush(stdout);
			scanf("%lld",&k);
			if(k)
			{
				zz=md;
				rh=md-1;
			}
			else
			{
				lh=md+1;
			}
		}
		spc[zz]=1;
		for(i=p+1;i<n;i++)
		{
			printf("? 1 1\n%lld\n%lld\n",p,i);
			fflush(stdout);
			scanf("%lld",&k);
			spc[i]=!!k;
			e^=!!k;
		}
		spc[n]=e;
		zs=0;
		for(i=1;i<=n;i++)
		{
			if(!spc[i])
			{
				zs++;
				sq[zs]=i;
			}
		}
		printf("! %lld",zs);
		for(i=1;i<=zs;i++)
		{
			printf(" %lld",sq[i]);
		}
		printf("\n");
		fflush(stdout);
	}
}
#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,m,fq[200069],mxa=2e5;

int main()
{
	long long i,j,k,lh,rh,md,zz=0,sm,c=0;
	
	scanf("%lld%lld",&n,&m);
	for(i=0;i<n;i++)
	{
		scanf("%lld",&k);
		fq[k]++;
	}
	for(lh=1,rh=n;lh<=rh;)
	{
		md=(lh+rh)/2;
		sm=0;
		for(i=1;i<=mxa;i++)
		{
			sm+=fq[i]/md;
		}
		if(sm>=m)
		{
			zz=md;
			lh=md+1;
		}
		else
		{
			rh=md-1;
		}
	}
	for(i=1;i<=mxa;i++)
	{
		for(j=0;j<fq[i]/zz;j++)
		{
			c++;
			if(c<=m)
			{
				printf("%lld%c",i," \n"[c==m]);
			}
		}
	}
}
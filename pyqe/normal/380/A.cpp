#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,nn=0,mxn=1e5,a[100069];
pair<long long,pair<long long,long long>> rg[100069];

int main()
{
	long long t,rr,i,j,ky,k,l,w,p,z;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld%lld",&ky,&k);
		if(ky==1)
		{
			nn++;
			if(nn<=mxn)
			{
				a[nn]=k;
			}
			rg[i]={nn,{1,k}};
		}
		else if(ky==2)
		{
			scanf("%lld",&l);
			for(j=1;j<=k*l&&nn+j<=mxn;j++)
			{
				a[nn+j]=a[(j-1)%k+1];
			}
			nn+=k*l;
			rg[i]={nn,{2,k}};
		}
	}
	scanf("%lld",&t);
	for(i=1,rr=0;rr<t;rr++)
	{
		scanf("%lld",&k);
		for(;rg[i].fr<k;i++);
		p=rg[i-1].fr;
		ky=rg[i].sc.fr;
		w=rg[i].sc.sc;
		if(ky==1)
		{
			z=w;
		}
		else if(ky==2)
		{
			z=a[(k-p-1)%w+1];
		}
		printf("%lld%c",z," \n"[rr==t-1]);
	}
}
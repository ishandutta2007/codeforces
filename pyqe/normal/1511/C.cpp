#include <bits/stdc++.h>

using namespace std;

const long long d=50;
long long n,pst[69],ps[300069];

int main()
{
	long long t,rr,i,k,z;
	
	scanf("%lld%lld",&n,&t);
	for(i=1;i<=d;i++)
	{
		pst[i]=n+1;
	}
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&k);
		pst[k]=min(pst[k],i);
		ps[i]=ps[i-1]+(i>pst[k]);
	}
	for(rr=1;rr<=t;rr++)
	{
		scanf("%lld",&k);
		z=ps[max(pst[k]-1,0ll)]+1;
		for(i=1;i<=d;i++)
		{
			z+=pst[i]<pst[k];
		}
		printf("%lld%c",z," \n"[rr==t]);
		pst[k]=-rr;
	}
}
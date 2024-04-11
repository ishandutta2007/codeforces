#include <bits/stdc++.h>

using namespace std;

long long n,a[200069],ls[200069],d[200069],dp[200069];

int main()
{
	long long t,rr,i,ky,k,l;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
	}
	scanf("%lld",&t);
	for(rr=1;rr<=t;rr++)
	{
		scanf("%lld%lld",&ky,&k);
		if(ky==1)
		{
			scanf("%lld",&l);
			a[k]=l;
			ls[k]=rr;
		}
		else if(ky==2)
		{
			d[rr]=k;
		}
	}
	for(i=t;i>=0;i--)
	{
		dp[i]=max(dp[i+1],d[i]);
	}
	for(i=1;i<=n;i++)
	{
		printf("%lld%c",max(a[i],dp[ls[i]])," \n"[i==n]);
	}
}
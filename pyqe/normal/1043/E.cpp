#include <bits/stdc++.h>

using namespace std;

long long n,m,a[300069],df[300069],as[300069],ps[300069],sq[300069];

int main()
{
	long long i,k,l,w,p,sm=0;
	
	scanf("%lld%lld",&n,&m);
	for(i=1;i<=n;i++)
	{
		scanf("%lld%lld",a+i,df+i);
		df[i]-=a[i];
		as[i]=df[i];
		sm+=a[i];
	}
	sort(as+1,as+n+1);
	for(i=1;i<=n;i++)
	{
		ps[i]=ps[i-1]+as[i];
	}
	for(i=1;i<=n;i++)
	{
		p=lower_bound(as+1,as+n+1,df[i])-as-1;
		sq[i]=a[i]*(n-2)+sm+ps[p]+df[i]*(n-1-p);
	}
	for(i=0;i<m;i++)
	{
		scanf("%lld%lld",&k,&l);
		w=a[k]+a[l]+min(df[k],df[l]);
		sq[k]-=w;
		sq[l]-=w;
	}
	for(i=1;i<=n;i++)
	{
		printf("%lld%c",sq[i]," \n"[i==n]);
	}
}
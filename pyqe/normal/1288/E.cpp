#include <bits/stdc++.h>

using namespace std;

long long n,m,fw[600069],fwp,mn[300069],mx[300069],pst[300069];

void ud(long long x,long long w)
{
	for(fwp=x;fwp<=n+m;fwp+=fwp&-fwp)
	{
		fw[fwp]+=w;
	}
}

long long qr(long long x)
{
	long long z=0;
	
	for(fwp=x;fwp;fwp-=fwp&-fwp)
	{
		z+=fw[fwp];
	}
	return z;
}

int main()
{
	long long i,k;
	
	scanf("%lld%lld",&n,&m);
	for(i=1;i<=n;i++)
	{
		mn[n+1-i]=n+1-i;
		mx[n+1-i]=n+1-i;
		pst[n+1-i]=i;
		ud(i,1);
	}
	for(i=1;i<=m;i++)
	{
		scanf("%lld",&k);
		mx[k]=max(mx[k],n-qr(pst[k])+1);
		mn[k]=1;
		ud(pst[k],-1);
		pst[k]=n+i;
		ud(n+i,1);
	}
	for(i=1;i<=n;i++)
	{
		mx[i]=max(mx[i],n-qr(pst[i])+1);
		printf("%lld %lld\n",mn[i],mx[i]);
	}
}
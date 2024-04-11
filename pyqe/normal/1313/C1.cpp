#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,nn=0,a[500069],dp[500069],sq[500069];
pair<long long,long long> sk[500069];

int main()
{
	long long i,ii,u,sm,mx,e,mn;
	pair<long long,long long> mxe={-1e18,-1};
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
	}
	for(ii=0;ii<2;ii++)
	{
		u=!ii*2-1;
		sm=0;
		nn=0;
		sk[0]={0,(n+1)*ii};
		for(i=1+(n-1)*ii;i!=(n+1)*!ii;i+=u)
		{
			for(;sk[nn].fr>=a[i];nn--)
			{
				sm+=(a[i]-sk[nn].fr)*abs(sk[nn].sc-sk[nn-1].sc);
			}
			nn++;
			sk[nn]={a[i],i};
			sm+=a[i];
			dp[i]+=sm;
		}
	}
	for(i=1;i<=n;i++)
	{
		dp[i]-=a[i];
		mxe=max(mxe,{dp[i],i});
	}
	mx=mxe.fr;
	e=mxe.sc;
	for(ii=0;ii<2;ii++)
	{
		u=!ii*2-1;
		mn=1e18;
		for(i=e;i&&i<=n;i+=u)
		{
			mn=min(mn,a[i]);
			sq[i]=mn;
		}
	}
	for(i=1;i<=n;i++)
	{
		printf("%lld%c",sq[i]," \n"[i==n]);
	}
}
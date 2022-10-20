//ANMHLIJKTJIY!
#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define INF 1000000000
#define LINF 1000000000000000000
#define mod 1000000007
#define F first
#define S second
#define ll long long
#define N 16
#define M 16400
using namespace std;
ll ksm(ll x,ll y)
{
	ll ret=1;
	while(y>0)
	{
		if(y&1)
		{
			ret=(ret*x)%mod;
		}
		x=(x*x)%mod;
		y>>=1;
	}
	return ret;
}
int n,a[N],posw[N][M],trs[M],wnmask[48200000];
ll dp[M],inv[2000010],ans=0;
int main(){
	ll i,j,mask,mask2,pw;
	inv[1]=1;
	for(i=2;i<2000010;i++)
	{
		inv[i]=((mod-mod/i)*inv[mod%i])%mod;
	}
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(mask=0;mask<(1<<n);mask++)
	{
		trs[mask]=0;
		pw=1;
		for(i=0;i<n;i++)
		{
			if(mask&(1<<i))
			{
				trs[mask]+=pw;
			}
			pw*=3;
		}
	}
	for(mask=0;mask<(1<<n);mask++)
	{
		for(i=0;i<n;i++)
		{
			pw=1;
			for(j=0;j<n;j++)
			{
				if(mask&(1<<j))
				{
					pw=(pw*((a[i]*inv[a[i]+a[j]])%mod))%mod;
				}
			}
			posw[i][mask]=pw;
		}
	}
	for(mask=0;mask<(1<<n);mask++)
	{
		for(mask2=((1<<n)-1)^mask;mask2>0;mask2=(mask2-1)&(((1<<n)-1)^mask))
		{
			pw=1;
			for(i=0;i<n;i++)
			{
				if(mask&(1<<i))
				{
					pw=(pw*posw[i][mask2])%mod;
				}
				wnmask[trs[mask2]+trs[mask]*2]=pw;
			}
		}
	}
	for(i=0;i<n;i++)
	{
		memset(dp,0,sizeof(dp));
		for(mask=0;mask<(1<<n);mask++)
		{
			if(mask&(1<<i))
			{
				dp[mask]=1;
				for(mask2=((mask-1)&mask);mask2>0;mask2=(mask2-1)&mask)
				{
					dp[mask]=(dp[mask]+mod-((dp[mask2]*wnmask[trs[mask^mask2]*2+trs[mask2]])%mod))%mod;
				}
			}
		}
		ans=(ans+dp[(1<<n)-1])%mod;
	}
	printf("%lld\n",ans);
	return 0;
}
//ANMHLIJKTJIY!
#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define INF 1000000000
#define LINF 1000000000000000000
#define mod 1000000007
#define F first
#define S second
#define ll long long
#define N 110
using namespace std;
ll fact[N],inv[N];
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
ll GetC(ll x,ll y){
	if(x<y||x<0||y<0)
	{
		return 0;
	}
	return (fact[x]*((inv[y]*inv[x-y])%mod))%mod;
}
ll n,m,k,dp[2][52][52][N],ans=0;
int main(){
	ll i,j,l,p,x;
	fact[0]=inv[0]=1;
	for(i=1;i<N;i++)
	{
		fact[i]=(fact[i-1]*i)%mod;
		inv[i]=ksm(fact[i],mod-2);
	}
	cin>>n>>m>>k;
	memset(dp,0,sizeof(dp));
	for(i=1;i*2<=n;i++)
	{
		dp[0][i][i][1]=1;
	}
	for(i=2;i<=min(m,n/2+1);i++)
	{
		for(j=1;j*2<=n;j++)
		{
			for(l=1;l*2<=n;l++)
			{
				for(p=1;p<=k;p++)
				{
					if(dp[i&1][j][l][p]==0)
					{
						continue;
					}
					ans=(ans+(m-i+1)*dp[i&1][j][l][p])%mod;
					for(x=1;(x+l)*2<=n;x++)
					{
						if(p*GetC(j+x-1,x)>k)
						{
							continue;
						}
						dp[(i&1)^1][x][l+x][p*GetC(j+x-1,x)]=(dp[(i&1)^1][x][l+x][p*GetC(j+x-1,x)]+dp[i&1][j][l][p]);
					}
				}
			}
		}
		memset(dp[i&1],0,sizeof(dp[i&1]));
	}
	cout<<ans<<endl;
	return 0;
}
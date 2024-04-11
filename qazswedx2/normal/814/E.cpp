#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int mod=1e9+7;
/*inline int addmod(int x)
{
	return x>=mod?x-mod:x;
}
inline int submod(int x)
{
	return x<0?x+mod:x;
}*/
int fpow(int x,int y)
{
	int ans=1;
	while(y)
	{
		if(y&1) ans=1ll*ans*x%mod;
		x=1ll*x*x%mod;
		y/=2;
	}
	return ans;
}
int n,m,a[100005],*f[605][605],fr[1005],dp[1005][1005],tmp[1005],inv2,pw[1005];
int buf[30000005],*bt=buf;
int main()
{
//	freopen("graph.in","r",stdin);
//	freopen("graph.out","w",stdout);
	scanf("%d",&n);
	fr[0]=1;
	pw[0]=1;
	inv2=fpow(2,mod-2);
	for(int i=1;i<=n;i++)
	{
		fr[i]=1ll*fr[i-1]*i%mod;
		pw[i]=1ll*pw[i-1]*inv2%mod;
	}
	m=min(n,600);
	for(int j=0;j<=m;j++)
		for(int i=0;i+j<=m;i++)
		{
			int mx=i/2+j+10;
		//	mx=m+1;
			f[i][j]=bt;
			bt+=mx;
	//		printf("i=%d,j=%d,bt=%lld\n",i,j,bt-buf);
			for(int k=0;k<mx;k++)
			{
				if(!k)
				{
					f[i][j][k]=pw[j];
					continue;
				}
				if(i)
				{
					f[i][j][k]=f[i-1][j][k];
					if(i>=2) f[i][j][k]=(f[i][j][k]+1ll*(i-1)*f[i-2][j][k-1])%mod;
					if(j) f[i][j][k]=(f[i][j][k]+1ll*j*f[i][j-1][k-1])%mod;
				}
				else
				{
					if(j) f[i][j][k]=1ll*f[i][j-1][k]*inv2%mod;
					if(j>=2) f[i][j][k]=(f[i][j][k]+1ll*(j-1)*f[i+1][j-2][k-1])%mod;
					if(j>=3&&k>=2)
						f[i][j][k]=(f[i][j][k]+1ll*(j-1)*(j-2)/2%mod*f[i+2][j-3][k-2])%mod;
				}
			//	printf("i=%d,j=%d,k=%d,f=%d\n",i,j,k,f[i][j][k]);
				if(!f[i][j][k]) break;
			}
		}
//	fprintf(stderr,"bt=%lld\n",bt-buf);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	dp[a[1]+1][2]=1;
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		int ct1=0,ct2=0;
		for(int j=i;j;j--)
		{
			if(a[j]==2) ct1++;
			else ct2++;
			if(dp[i][j])
			{
				if(i==n)
				{
					if(ct1%2==0)
						ans=(ans+1ll*dp[i][j]*f[ct1][ct2][ct1/2+ct2])%mod; 
				}
			//	fprintf(stderr,"i=%d,j=%d,dp=%d\n",i,j,dp[i][j]);
				int q=i+ct1+ct2*2;
				for(int k=max((q-n+1)/2,0),l=q-k*2;l>i;k++,l-=2)
				{
					if(k>ct1/2+ct2+3||!f[ct1][ct2][k]) break;
					dp[l][i+1]=(dp[l][i+1]+1ll*f[ct1][ct2][k]*dp[i][j]%mod*fr[l-i])%mod;
				}
			}
		}
	}
//	for(int i=1;i<=n;i++)
	//	ans=(1ll*ans+dp[n][i])%mod;
	printf("%d\n",ans);
	return 0;
}
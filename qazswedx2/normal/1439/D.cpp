#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int mod;
inline int addmod(int x)
{
	return x>=mod?x-mod:x;
}
inline int submod(int x)
{
	return x<0?x+mod:x;
}
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
struct pt
{
	int f,g;
	pt(int f=0,int g=0):f(f),g(g){}
};
pt operator+(const pt x,const pt y)
{
	return pt(addmod(x.f+y.f),addmod(x.g+y.g));
}
pt operator*(const pt x,const pt y)
{
	return pt(1ll*x.f*y.f%mod,addmod(1ll*x.f*y.g%mod+1ll*x.g*y.f%mod));
}
int n,m,pn=1e5,fr[100005],infr[100005],inv[100005];
pt dp[1005],up[1005][1005];
int F(int x)
{
	return 1ll*x*(x+1)/2%mod;
}
int main()
{
	scanf("%d%d%d",&n,&m,&mod);
	fr[0]=infr[0]=1;
	for(int i=1;i<=pn;i++)
	{
		fr[i]=1ll*i*fr[i-1]%mod;
		infr[i]=fpow(fr[i],mod-2);
		inv[i]=fpow(i,mod-2);
	}
	dp[0]=pt(1,0);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=i;j++)
		{
			pt nw=dp[j-1]*dp[i-j];
			nw.g=addmod(1ll*nw.g*(i+1)%mod+1ll*nw.f*addmod(F(j-1)+F(i-j))%mod);
			nw.g=1ll*nw.g*inv[i]%mod;
			nw.f=1ll*nw.f*(i+1)%mod*inv[i]%mod;
			dp[i]=dp[i]+nw;
		}
	//	printf("i=%d,dp=%lld,%lld\n",i,1ll*dp[i].f*fr[i]%mod,1ll*dp[i].g*fr[i]%mod);
	}
	up[0][0]=pt(1,0);
	for(int i=1;i<=n;i++)
		for(int j=0;j<=min(i,m);j++)
		{
			if(i==j) up[i][j]=dp[i];
			for(int k=0;k<=j&&k<i;k++)
				up[i][j]=up[i][j]+dp[k]*up[i-k-1][j-k];
		}
	int ans=1ll*up[n][m].g*fr[m]%mod;
	printf("%d\n",ans);
	return 0;
}
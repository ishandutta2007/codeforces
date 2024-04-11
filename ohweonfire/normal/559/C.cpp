#include<bits/stdc++.h>
#define ff first
#define ss second
#define mp make_pair
using namespace std;
typedef long long LL;
const int maxn=2005;
const LL mod=1000000007;
int h,w,n;
pair<int,int> p[maxn];
LL dp[maxn],fac[200005],invfac[200005];
LL power(LL x,LL y)
{
	LL ret=1;
	while(y!=0)
	{
		if(y&1)ret=ret*x%mod;
		x=x*x%mod;
		y>>=1;
	}
	return ret;
}
LL step(int xx,int yy)
{
	return (fac[xx+yy]*invfac[xx]%mod)*invfac[yy]%mod;
}
int main()
{
	scanf("%d%d%d",&h,&w,&n);
	for(int i=1;i<=n;i++)scanf("%d%d",&p[i].ff,&p[i].ss);
	fac[0]=invfac[0]=1;
	for(int i=1;i<=h+w;i++)
	{
		fac[i]=fac[i-1]*i%mod;
		invfac[i]=power(fac[i],mod-2);
	}
	n++;
	p[n]=mp(h,w);
	sort(p+1,p+n+1);
	for(int i=1;i<=n;i++)
	{
		dp[i]=step(p[i].ff-1,p[i].ss-1);
		for(int j=1;j<i;j++)if(p[i].ff>=p[j].ff&&p[i].ss>=p[j].ss)
			dp[i]=(dp[i]-dp[j]*step(p[i].ff-p[j].ff,p[i].ss-p[j].ss)%mod+mod)%mod;
	}
	printf("%I64d\n",dp[n]);
	return 0;
}
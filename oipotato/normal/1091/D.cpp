#include<cstdio>
using namespace std;
#define rep(i,n) for(int i=1;i<=n;i++)
const int MOD=998244353;
int ans,n,fac[1000010];
int mypow(int x,int n){int ans=1;for(;n;n>>=1,x=1ll*x*x%MOD)if(n&1)ans=1ll*ans*x%MOD;return ans;}
int main()
{
	scanf("%d",&n);
	fac[0]=1;
	rep(i,n)fac[i]=1ll*fac[i-1]*i%MOD;
	rep(i,n)ans=(ans-1ll*mypow(fac[i],MOD-2)*fac[n]%MOD+MOD)%MOD;
	ans=(ans+1ll*fac[n]*n+1)%MOD;
	printf("%d\n",ans);
	return 0;
}
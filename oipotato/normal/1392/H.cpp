#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#include<queue>
#include<vector>
using namespace std;
#define rep(i,n) for(int i=1;i<=n;i++)
#define pb push_back
#define mp make_pair
const int MOD=998244353;
const int N=(int)2e6+10;
int f[N],s[N],sx[N],sf[N],n,m,C,C1,C2,invC,fac[N<<1],inv[N<<1];
int mypow(int x,int n){int ans=1;for(;n;n>>=1,x=1ll*x*x%MOD)if(n&1)ans=1ll*ans*x%MOD;return ans;}
int main()
{
	scanf("%d%d",&n,&m);
	fac[0]=1;
	rep(i,n+m+1)fac[i]=1ll*fac[i-1]*i%MOD;
	inv[n+m+1]=mypow(fac[n+m+1],MOD-2);
	for(int i=n+m;i>=0;i--)inv[i]=1ll*inv[i+1]*(i+1)%MOD;
	s[0]=fac[m-1];
	rep(i,n)
	{
		s[i]=(s[i-1]+1ll*fac[m-1+i]*inv[i])%MOD;
		sx[i]=(sx[i-1]+1ll*fac[m-1+i]*inv[i-1])%MOD;
		C=1ll*fac[n-i]*m%MOD*fac[i]%MOD*inv[n+m]%MOD;
		C1=1ll*C*fac[n+m+1]%MOD*inv[m+i+1]%MOD*inv[n-i]%MOD;
		C2=1ll*C*fac[n+m]%MOD*inv[m+i]%MOD*inv[n-i]%MOD;
		invC=1ll*(m+i)*fac[i-1]%MOD*inv[i]%MOD;
		f[i]=(1ll*C1*s[i]%MOD*(i+1)%MOD-1ll*C1*sx[i]%MOD+MOD+1ll*C2*sf[i-1])%MOD;
		f[i]=1ll*f[i]*invC%MOD;
		sf[i]=(sf[i-1]+1ll*fac[m-1+i]*inv[i]%MOD*f[i])%MOD;
	}
	printf("%d\n",f[n]);
    return 0;
}
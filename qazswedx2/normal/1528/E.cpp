#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int mod=998244353;
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
int n,f[1000005],g[1000005],a[1000005],b[1000005],c[1000005],inv6,inv2;
int main()
{
	scanf("%d",&n);
	f[0]=g[0]=1;
	inv6=fpow(6,mod-2);
	inv2=fpow(2,mod-2);
	for(int i=1;i<=n;i++)
	{
		int nw=1,v=g[i-1];
		nw=addmod(nw+1ll*v*(v-1)%mod*(v-2)%mod*inv6%mod);
		nw=addmod(nw+1ll*v*(v-1)%mod);
		nw=addmod(nw+3ll*v%mod);
		nw=addmod(nw+1ll*v*(v-1)%mod*inv2%mod);
		f[i]=nw;
		nw=1;
		nw=addmod(nw+2ll*v%mod);
		nw=addmod(nw+1ll*v*(v-1)%mod*inv2%mod);
		g[i]=nw;
		nw=0;
		nw=addmod(nw+v);
		nw=addmod(nw+1ll*v*(v-1)%mod*inv2%mod);
		b[i]=nw;
	//	printf("i=%d,f=%d,g=%d\n",i,f[i],g[i]);
	}
	for(int i=1;i<=n;i++)
	{
		a[i]=submod(g[i]-g[i-1]);
		c[i]=submod(b[i]-b[i-1]);
	}
	int ans=(2ll*(f[n]-f[n-1])-1+mod)%mod;
	ans=(ans%mod+mod)%mod;
	for(int i=1;i<n;i++)
		ans=addmod(ans+1ll*submod(a[i]-1)*c[n-i-1]%mod);
	printf("%d\n",ans);
	return 0;
}
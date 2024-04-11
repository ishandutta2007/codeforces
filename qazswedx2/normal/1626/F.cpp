#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int mod=998244353;
int n,a[10000005],x,y,m,k,f[22][1000005],pw[105],pn=16*9*5*7*11*13;
int main()
{
	scanf("%d%d%d%d%d%d",&n,&a[1],&x,&y,&k,&m);
	pw[0]=1;
	for(int i=1;i<=k;i++)
		pw[i]=1ll*pw[i-1]*n%mod;
	for(int i=k;i>0;i--)
	{
		for(int j=0;j<pn;j++)
		{
			f[i][j]=(1ll*(n-1)*f[i+1][j]+(f[i+1][j-j%i]+1ll*j*pw[k-i]))%mod;
		//	if(j<=20) printf("i=%d,j=%d,f=%d,%d\n",i,j,f[i][j],f[i+1][j-j%i]);
		}
	}
	for(int i=2;i<=n;i++)
		a[i]=(1ll*a[i-1]*x+y)%m;
	int ans=0,mul=1ll*k*pw[k-1]%mod;
	for(int i=1;i<=n;i++)
	{
		ans=(ans+1ll*a[i]/pn*pn*mul)%mod;
		ans=(ans+f[1][a[i]%pn])%mod;
//		printf("i=%d,a=%d,ans=%d\n",i,a[i],ans);
	}
	printf("%d\n",ans);
	return 0;
}
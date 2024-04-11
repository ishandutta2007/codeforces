#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int mod=998244353;
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
int n,m,f[100005][25];
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			scanf("%d",&f[j][i]);
	int ans=0;
	for(int i=1;i<=m;i++)
	{
		sort(f[i]+1,f[i]+n+1);
		int mul=1;
		for(int j=1;j<=n;j++)
			mul=1ll*mul*(f[i][j]-j)%mod;
		ans=(ans+mul)%mod;
	}
	int mul=1;
	for(int i=1;i<=n;i++)
		mul=1ll*mul*i%mod;
	ans=1ll*ans*fpow(mul,mod-2)%mod;
	ans=(m-ans+mod)%mod;
	printf("%d\n",ans);
	return 0;
}
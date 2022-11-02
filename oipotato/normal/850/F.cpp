#include <cstdio>
#include <algorithm>
using namespace std;
const int MOD=1E9+7;
int f[100010],c[100010],ans,sum,maxnum,n;
int quick_pow(int x,int n)
{
	int tmp=x,tans=1;
	for(;n;n>>=1)
	{
		if(n&1)
			tans=1ll*tans*tmp%MOD;
		tmp=1ll*tmp*tmp%MOD;
	}
	return tans;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&c[i]);
		sum+=c[i];
		maxnum=max(maxnum,c[i]);
	}
	f[0]=0;
	f[1]=1ll*(sum-1)*(sum-1)%MOD*quick_pow(sum,MOD-2)%MOD;
	for(int i=1;i<maxnum;i++)
		f[i+1]=((((f[i]+f[i])%MOD-f[i-1])%MOD-1ll*(sum-1)*quick_pow(sum-i,MOD-2)%MOD)%MOD+MOD)%MOD;
	for(int i=1;i<=n;i++)
		ans=(ans+f[c[i]])%MOD;
	printf("%d\n",ans);
	return 0;
}
#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#include<cassert>
#include<set>
#include<map>
using namespace std;
#define pb push_back
#define mp make_pair
#define rep(i,n) for(int i=1;i<=n;i++)
typedef long long LL;
int f[250010],tmp[250010],fac[510],n,MOD,ans;
int main()
{
	scanf("%d%d",&n,&MOD);
	int now=0;
	f[0]=1;
	fac[0]=1;
	rep(i,n)fac[i]=1ll*fac[i-1]*(n-i+1)%MOD;
	rep(i,n)
	{
		if(i==1)continue;
		rep(j,2*now+i-1)(f[j]+=f[j-1])%=MOD;
		rep(j,min(i-1,now))ans=(ans+1ll*fac[n-i]*(f[2*now]-f[j+now]+MOD)%MOD*(i-j))%MOD;
		for(int j=0;j<=2*now+i-1;j++)tmp[j]=(f[j]-(j-i>=0?f[j-i]:0)+MOD)%MOD;
		for(int j=0;j<i-1;j++)f[j]=0;
		for(int j=0;j<=2*now+i-1;j++)f[j+i-1]=tmp[j];
		now+=i-1;
		rep(j,2*now)(f[j]+=f[j-1])%=MOD;
		for(int j=0;j<=2*now;j++)tmp[j]=(f[min(2*now,j+i-1)]-(j?f[j-1]:0)+MOD)%MOD;
		for(int j=0;j<=2*now;j++)f[j]=tmp[j];
	}
	printf("%d\n",ans);
    return 0;
}
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
const int MOD=1E9+7;
int fac[2000010],inv[2000010],x,y,n,ans,len;
int mypow(int x,int n)
{
	int ans=1;
	for(;n;n>>=1,x=1ll*x*x%MOD)
	{
		if(n&1)
		{
			ans=1ll*ans*x%MOD;
		}
	}
	return ans;
}
int C(int n,int m){return 1ll*fac[n]*inv[m]%MOD*inv[n-m]%MOD;}
int main()
{
	fac[0]=1;
	for(int i=1;i<=2000000;i++)
	{
		fac[i]=1ll*fac[i-1]*i%MOD;
	}
	inv[2000000]=mypow(fac[2000000],MOD-2);
	for(int i=1999999;i>=0;i--)
	{
		inv[i]=1ll*inv[i+1]*(i+1)%MOD;
	}
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&x,&y);
		ans=mypow(2,y-1);
		//printf("%d\n",ans);
		len=sqrt(x);
		for(int j=2;j<=len;j++)
		{
			if(x%j==0)
			{
				int cnt=0;
				for(;x%j==0;x/=j)
				{
					cnt++;
				}
				ans=1ll*ans*C(y+cnt-1,cnt)%MOD;
				//printf("%d %d %d\n",y+cnt-1,cnt,C(y+cnt-1,cnt));
			}
		}
		if(x>1)
		{
			ans=1ll*ans*y%MOD;
		}
		printf("%d\n",ans);
	}
	return 0;
}
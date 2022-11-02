#include<cstdio>
using namespace std;
int inv[100010],s[100010],num[100010],n,k,MOD,ans;
void work(int l,int r,int h)
{
	if(h<=1||l==r){num[r-l+1]++;return;}
	int mid=(l+r)>>1;
	work(l,mid,h-1);
	work(mid+1,r,h-1);
}
int basic(int x){return 1ll*x*(x-1)%MOD*inv[4]%MOD;}
int cal(int x,int y)
{
	int tans=0;
	for(int i=1;i<=x;i++)tans=(0ll+tans+s[i+y]-s[i]+MOD)%MOD;
	return (1ll*x*y%MOD*inv[2]-tans+MOD)%MOD;
}
int mypow(int x,int n){int tans=1;for(;n;n>>=1,x=1ll*x*x%MOD)if(n&1)tans=1ll*tans*x%MOD;return tans;}
int main()
{
	scanf("%d%d%d",&n,&k,&MOD);
	inv[4]=mypow(4,MOD-2);
	for(int i=1;i<=n;i++)inv[i]=mypow(i,MOD-2);
	for(int i=1;i<=n;i++)s[i]=(s[i-1]+inv[i])%MOD;
	work(1,n,k);
	for(int i=1;i<=n;i++)
	if(num[i])
	{
		ans=(ans+1ll*num[i]*basic(i))%MOD;
		ans=(ans+1ll*num[i]*(num[i]-1)%MOD*inv[2]%MOD*cal(i,i))%MOD;
		if(num[i+1])
		{
			ans=(ans+1ll*num[i+1]*basic(i+1))%MOD;
			ans=(ans+1ll*num[i+1]*(num[i+1]-1)%MOD*inv[2]%MOD*cal(i+1,i+1))%MOD;
			ans=(ans+1ll*num[i]*num[i+1]%MOD*cal(i,i+1))%MOD;
		}
		break;
	}
	printf("%d\n",ans);
	return 0;
}
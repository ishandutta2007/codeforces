#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const int mod=1e9+7;
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
int sd,bs;
int n,m,a[5000005],c[5000005],tmp[5000005];
int myrand()
{
	int las=sd;
	sd=(1ll*sd*bs+233)%mod;
	return las;
}
int main()
{
	scanf("%d%d",&n,&m);
	int las=0;
	for(int i=1;i<=m;i++)
	{
		int p,k;
		scanf("%d%d%d%d",&p,&k,&sd,&bs);
		for(int j=las+1;j<=p;j++)
		{
			c[j]=myrand()%2+1;
			a[j]=myrand()%k+1;
		}
		las=p;
	}
	memcpy(tmp,a,sizeof(tmp));
	ll sum=0,sum1=0;
	for(int i=1;i<=n;i++)
		if(c[i]==1) sum-=a[i];
		else sum+=a[i];
	if(sum<0)
	{
		for(int i=1;i<=n;i++)
			if(c[i]==1) c[i]=2;
			else c[i]=1;
	}
	for(int i=1;i<=n;i++)
		if(c[i]==1) sum1+=a[i];
	if(c[1]==2) a[1]--;
	sum=0;
	for(int i=1;;i=i%n+1)
	{
	//	printf("i=%d,sum=%lld,sum1=%lld\n",i,sum,sum1);
		if(sum1==0&&sum==0) break;
		if(c[i]==1)
		{
			sum1-=a[i];
			sum+=a[i];
			a[i]=0;
		}
		else
		{
			int q=min(sum,(ll)a[i]);
			a[i]-=q;
			sum-=q;
		}
	}
	int ans=1;
	for(int i=1;i<=n;i++)
	{
	//	printf("i=%d,a=%d,c=%d,tmp=%d\n",i,a[i],c[i],tmp[i]);
		ans=1ll*(((tmp[i]-a[i])^(1ll*i*i))+1)%mod*ans%mod;
	}
	printf("%d\n",ans);
	return 0;
}
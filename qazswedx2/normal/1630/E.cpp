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
int t,n,a[1000005],c[1000005],ct,infr[2000005],fr[2000005],inv[2000005],pn=2e6;
int phi[2000005],prime[2000005],p[2000005],pt;
bool cmp(const int x,const int y)
{
	return x>y;
}
void solve(int x,int &tans,int &tans2)
{
	if(n%x) return;
	int ans=fr[n/x],ans2;
	int nw=0,len=n/x;
	for(int i=1;i<=ct;i++)
	{
		if(c[i]%x) return;
		int v=c[i]/x;
		ans=1ll*ans*infr[v]%mod;
		nw=addmod(nw+1ll*c[i]*(len-v)%mod*inv[len-1]%mod);
	}
	ans=1ll*ans*phi[x]%mod;
	ans2=1ll*nw*ans%mod;
//	printf("x=%d,ans=%d,ans2=%d,nw=%lld\n",x,ans,ans2,1ll*nw*(len-1)%mod);
	tans=addmod(tans+ans);
	tans2=addmod(tans2+ans2);
}
int main()
{
	fr[0]=infr[0]=1;
	for(int i=1;i<=pn;i++)
		fr[i]=1ll*fr[i-1]*i%mod;
	infr[pn]=fpow(fr[pn],mod-2);
	for(int i=pn-1;i>0;i--)
		infr[i]=1ll*infr[i+1]*(i+1)%mod;
	for(int i=1;i<=pn;i++)
		inv[i]=1ll*infr[i]*fr[i-1]%mod;
	phi[1]=1;
	for(int i=2;i<=pn;i++)
	{
		if(!p[i]) prime[++pt]=i,phi[i]=i-1;
		for(int j=1;j<=pt&&i*prime[j]<=pn;j++)
		{
			p[i*prime[j]]=1;
			if(i%prime[j]==0)
			{
				phi[i*prime[j]]=phi[i]*prime[j];
				break; 
			}
			phi[i*prime[j]]=phi[i]*(prime[j]-1);
		}
	}
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n+1;i++)
			c[i]=0;
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]),c[a[i]]++;
		sort(c+1,c+n+1,cmp);
		ct=1;
		while(c[ct+1]) ct++;
		if(ct==1)
		{
			printf("1\n");
			continue;
		}
		int ans=0,ans2=0;
		for(int i=1;i<=c[ct];i++)
			solve(i,ans,ans2);
		ans2=1ll*ans2*fpow(ans,mod-2)%mod;
		printf("%d\n",ans2);
	}
	return 0;
}
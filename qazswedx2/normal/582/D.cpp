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
int p,k,at,f[4005][4005][2][2];
ll a[100005];
char s[100005];
void upd()
{
	for(int i=1;i<=at;i++)
	{
		a[i+1]+=a[i]/p;
		a[i]%=p;
	}
	while(a[at+1])
	{
		at++;
		a[at+1]+=a[at]/p;
		a[at]%=p;
	}
}
inline int F(int x)
{
	return 1ll*x*(x-1)/2%mod;
}
inline int G(int x)
{
	return submod(1ll*x*p%mod-F(x+1));
}
int dfs(int dep,int sum,int lim,int fl)
{
	if(dep==at+1) return fl==0&&sum>=k;
//	if(sum>k) return 0;
	if(f[dep][sum][lim][fl]!=-1) return f[dep][sum][lim][fl];
	int ans=0;
	if(!fl)
	{
		int mx=p;
		if(lim)
		{
			mx=a[dep];
			ans=(ans+1ll*dfs(dep+1,sum,lim,0)*(a[dep]+1))%mod;
			ans=(ans+1ll*dfs(dep+1,sum+1,lim,1)*a[dep])%mod;
		}
		ans=(ans+1ll*dfs(dep+1,sum,0,0)*F(mx+1))%mod;
		ans=(ans+1ll*dfs(dep+1,sum+1,0,1)*F(mx))%mod;
	}
	else
	{
		int mx=p;
		if(lim)
		{
			mx=a[dep];
			ans=(ans+1ll*dfs(dep+1,sum,lim,0)*(p-a[dep]-1))%mod;
			ans=(ans+1ll*dfs(dep+1,sum+1,lim,1)*(p-a[dep]))%mod;
	//		if(a[dep]) ans=(ans+1ll*dfs(dep+1,sum+1,0,1)*p)%mod;
		}
		ans=(ans+1ll*dfs(dep+1,sum,0,0)*G(mx))%mod;
		if(mx) ans=(ans+1ll*dfs(dep+1,sum+1,0,1)*(G(mx-1)+p))%mod;
	}
//	printf("dep=%d,sum=%d,lim=%d,fl=%d,ans=%d\n",dep,sum,lim,fl,ans); 
	f[dep][sum][lim][fl]=ans;
	return ans;
}
int main()
{
//	freopen("number.in","r",stdin);
//	freopen("number.out","w",stdout);
	memset(f,-1,sizeof(f));
	scanf("%d%d",&p,&k);
	a[1]=0;
	at=1;
	scanf("%s",s+1);
	for(int i=1;s[i];i++)
	{
		int c=s[i]-'0';
		for(int j=1;j<=at;j++)
			a[j]*=10;
		a[1]+=c;
		upd();
	}
	reverse(a+1,a+at+1);
/*	for(int i=1;i<=at;i++)
		printf("%lld ",a[i]);
	printf("\n");*/
	int ans=dfs(1,0,1,0);
	printf("%d\n",ans);
	return 0;
}
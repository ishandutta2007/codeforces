#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const int mod=998244353;
inline int addmod(int x)
{
	return x>=mod?x-mod:x;
}
inline int submod(int x)
{
	return x<0?x+mod:x;
}
int fpow(int x,ll y)
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
int n,a[100005],pn=1e5,mu[100005],p[100005],prime[100005],pt;
int pw[100005];
inline int F(int x,int y)
{
	if(!x) return 1;
	return addmod(1ll*y*fpow(2,x-1)%mod+fpow(2,x));
}
int solve(int ct,int cct,int sum,int sum2)
{
	if(ct<=1) return 0;
	return addmod(1ll*submod(1ll*sum*sum%mod-sum2)*F(ct-2,cct-2)%mod+
		   1ll*sum2*(cct-1)%mod*fpow(2,ct-2)%mod);
}
int main()
{
	pw[0]=1;
	mu[1]=1;
	for(int i=1;i<=pn;i++)
		pw[i]=2*pw[i-1]%mod;
	for(int i=2;i<=pn;i++)
	{
		if(!p[i]) prime[++pt]=i,mu[i]=-1;
		for(int j=1;j<=pt&&i*prime[j]<=pn;j++)
		{
			p[i*prime[j]]=1;
			if(i%prime[j]==0)
			{
				mu[i*prime[j]]=0;
				break;
			}
			mu[i*prime[j]]=-mu[i];
		}
	}
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		a[x]=y;
	}
	int ans=0;
	for(int i=1;i<=pn;i++)
		if(mu[i])
		{
			int sum=0,sum2=0;
			int ct=0,cct=0;
			for(int j=i;j<=pn;j+=i)
			{
				ct=ct+a[j];
				while(ct>mod+1000) ct-=(mod-1);
				cct=(cct+a[j])%mod;
				sum=addmod(sum+1ll*j*a[j]%mod);
				sum2=addmod(sum2+1ll*j*j%mod*a[j]%mod);
			}
			int q=solve(ct,cct,sum,sum2);
			//if(ct) printf("i=%d,q=%d,ct=%lld,sum=%d,sum2=%d\n",i,q,ct,sum,sum2);
			if(mu[i]==1) ans=addmod(ans+q);
			else if(mu[i]==-1) ans=submod(ans-q);
		}
	printf("%d\n",ans);
	return 0;
}
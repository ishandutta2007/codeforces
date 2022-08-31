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
int n,b,h,pw[15],ipw[15],f[15],g[15],mn[15],mx[15],a[15],fl,vis[105];
void dfs2(int dep,int p,int sum)
{
	//printf("dfs2:dep=%d,p=%d,sum=%d\n",dep,p,sum);
	if(dep==n)
	{
		int q=0;
		for(int i=1;i<=(1<<n);i++)
			if(!vis[i]) q+=i;
		if(q!=a[n]) return;
		for(int i=1;i<=(1<<n);i++)
			if(!vis[i]) vis[i]=g[n];
		fl=1;
		for(int i=1;i<=(1<<n);i++)
			printf("%d ",vis[i]);
		return;
	}
	int nwd=dep,nwp=p+f[dep],nws=sum;
	if(nwp>(1<<n)) nwd++,nwp=1,nws=a[dep+1]-mn[dep+1];
	int tmp=((1<<n)-p+1)/f[dep]-1;
	int l,r;
	l=p+max(0,(sum-tmp*(f[dep]-1)));
	r=p+min(f[dep]-1,sum);
//	printf("l=%d,r=%d,tmp=%d\n",l,r,tmp);
	for(int i=l;i<=r;i++)
		if(!vis[i]&&!vis[((i-1)^1)+1])
		{
			vis[i]=g[dep];
		//	printf("dfs:dep=%d,p=%d,sum=%d,i=%d,vis=%d\n",dep,p,sum,i,vis[i]);
			dfs2(nwd,nwp,nwp!=1?nws-(i-p):nws);
			if(fl) return;
			vis[i]=0;
		}
}
void dfs(int dep,int nw)
{
//	printf("dfs:dep=%d,nw=%d\n",dep,nw);
	if(!dep)
	{
		a[0]=1ll*submod(h-nw)*ipw[0]%mod;
		if(a[0]<mn[0]||a[0]>mx[0]) return;
	/*	for(int i=0;i<=n;i++)
			printf("%d ",a[i]);
		printf("\n");*/
		dfs2(0,1,a[0]-mn[0]);
		return;
	}
	for(int i=mn[dep];i<=mx[dep];i++)
	{
		a[dep]=i;
		dfs(dep-1,addmod(nw+1ll*i*pw[dep]%mod));
		if(fl) return;
	}
}
int main()
{
	scanf("%d%d%d",&n,&b,&h);
	pw[0]=1,pw[1]=b;
	f[0]=(1<<n),f[1]=(1<<n);
	g[0]=1,g[1]=2;
	for(int i=2;i<=n;i++)
	{
		pw[i]=1ll*pw[i-1]*pw[i-1]%mod;
		f[i]=f[i-1]/2;
		g[i]=(1<<(i-1))+1;
	}
	for(int i=0;i<=n;i++)
	{
		pw[i]=1ll*pw[i]*b%mod;
		ipw[i]=fpow(pw[i],mod-2);
	}
	for(int i=0;i<=n;i++)
	{
		for(int j=1;j<=(1<<n);j+=f[i])
		{
			mn[i]+=j;
			mx[i]+=j+f[i]-1;
		}
	}
//	for(int i=0;i<=n;i++)
	//	printf("i=%d,f=%d,g=%d,pw=%d,ipw=%d,mn=%d,mx=%d\n",i,f[i],g[i],pw[i],ipw[i],mn[i],mx[i]);
	dfs(n,0);
	if(!fl) printf("-1\n");
	return 0;
}
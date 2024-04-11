#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
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
int n,q,pn=1e6,m,pw[1000005],ipw[1000005],inv2;
int f[1000005][26],lg[1000005],sl,bt,g[1000005][2];
char str[1005],a[100005],s[1000005],b[1000005];
int solve(int dep,int len,int k)
{
/*	printf("solve:dep=%d,len=%d,k=%d,b=",dep,len,k);
	for(int i=1;i<=len;i++)
		printf("%c",b[i]);
	printf("\n");*/
	if(!len) return pw[k-dep+1];
	if(dep>k) return 0;
	if(len==1)
	{
		int u=b[1]-'a';
		int nw=submod(f[k][u]-f[dep-1][u]);
	//	printf("nw=%lld\n",1ll*nw*pw[k]%mod);
		return 1ll*nw*pw[k]%mod;
	}
	int fl0=1,fl1=1;
	for(int i=1;i<=len;i++)
	{
		if(b[i]!=a[dep])
		{
			if(i%2) fl1=0;
			else fl0=0;
		}
	}
	if(fl0&&fl1)
	{
		int fl=1,fl2=1,ans=0,v=dep+lg[len];
		for(int i=dep;i<v;i++)
		{
			if(i>n) fl=0;
			if(b[1]!=a[i]) fl=0;
		}
		if(!fl) return 0;
		if(v>n||b[1]!=a[v]) fl2=0;
	//	printf("dep=%d,len=%d,v=%d,fl=%d,%d,g=%d,%d\n",dep,len,v,fl,fl2,g[len][0],g[len][1]);
		ans=addmod(ans+1ll*fl*g[len][0]%mod*solve(v,1,k)%mod);
		ans=addmod(ans+1ll*fl2*g[len][1]%mod*solve(v+1,1,k)%mod);
		return ans;
	}
	if(fl1)
	{
		for(int i=1;i*2<=len;i++)
			b[i]=b[i*2];
		return solve(dep+1,len/2,k);
	}
	if(fl0)
	{
		for(int i=1;i*2-1<=len;i++)
			b[i]=b[i*2-1];
		return solve(dep+1,(len+1)/2,k);
	}
	return 0;
}
int main()
{
	lg[1]=0;
	for(int i=2;i<=pn;i++)
		lg[i]=lg[i/2]+1;
	pw[0]=ipw[0]=1;
	inv2=fpow(2,mod-2);
	for(int i=1;i<=pn;i++)
	{
		pw[i]=2*pw[i-1]%mod;
		ipw[i]=1ll*inv2*ipw[i-1]%mod;
	}
	g[1][0]=1;
	g[2][0]=2;
	g[3][0]=1,g[3][1]=2;
	for(int i=4;i<=pn;i++)
	{
		if(i<pn&&lg[i+1]!=lg[i])
		{
			g[i][0]=g[i/2][0];
			g[i][1]=addmod(g[i/2][1]+g[i-i/2][0]);
			continue;
		}
		g[i][0]=addmod(g[i/2][0]+g[i-i/2][0]);
		g[i][1]=addmod(g[i/2][1]+g[i-i/2][1]);
	}
//	for(int i=1;i<=30;i++)
//		printf("i=%d,g=%d,%d\n",i,g[i][0],g[i][1]);
	scanf("%d%d",&n,&q);
	scanf("%s%s",str,a+1);
	sl=strlen(str);
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<26;j++)
			f[i][j]=f[i-1][j];
		int u=a[i]-'a';
		f[i][u]=addmod(f[i][u]+ipw[i]);
	//	printf("i=%d,u=%d,f=%d\n",i,u,f[i][u]);
	}
	for(int i=1;i<=q;i++)
	{
		int k,len,ans=0;
		scanf("%d%s",&k,s+1);
		len=strlen(s+1);
		for(int j=0;j<=sl;j++)
		{
			bt=0;
			int fl=1;
			for(int l=1,ll=j;l<=len;l++,ll=(ll+1)%(sl+1))
			{
				if(ll==sl) b[++bt]=s[l];
				else if(str[ll]!=s[l])
				{
					fl=0;
					break;
				}
			}
			if(!fl) continue;
		//	printf("j=%d\n",j);
			ans=addmod(ans+solve(1,bt,k));
		}
		printf("%d\n",ans);
	}
	return 0;
}
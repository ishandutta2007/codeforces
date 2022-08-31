#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
int mod1=998244353,mod2=1e9+9;
inline int addmod(int x,int mod)
{
	return x>=mod?x-mod:x;
}
inline int submod(int x,int mod)
{
	return x<0?x+mod:x;
}
struct edge2
{
	int v,w;
	bool operator<(const edge2 x) const
	{
		return w<x.w;
	}
}e2[1505][1505];
struct edge
{
	int v,nxt;
}e[500005];
int pw1[100005],pw2[100005],pn=1e5,bs=12345;
struct pt
{
	int v1,v2,id;
	pt(int v1=0,int v2=0,int id=0):v1(v1),v2(v2),id(id){}
	bool operator<(const pt x) const
	{
		return v1==x.v1?v2<x.v2:v1<x.v1;
	}
	bool operator==(const pt x) const
	{
		return v1==x.v1&&v2==x.v2;
	}
	void getadd(int x)
	{
		v1=addmod(v1+pw1[x],mod1);
		v2=addmod(v2+pw2[x],mod2);
	}
}p[1505],tmp[1505];
int n,a[100005],f[100005],pt,h[100005],t,dp[3005][3005],sz[3005];
int tmp2[3005],mx[100005],mn[100005];
int find(int x)
{
	if(f[x]==x) return x;
	return f[x]=find(f[x]);
}
void link(int x,int y)
{
	x=find(x),y=find(y);
	if(x==y) return;
	f[x]=y;
}
void add(int u,int v)
{
	e[++t].v=v;
	e[t].nxt=h[u];
	h[u]=t;
}
void dfs(int u,int fa)
{
	dp[u][0]=1;
	sz[u]=1;
	for(int i=h[u];i;i=e[i].nxt)
	{
		int v=e[i].v;
		if(v==fa) continue;
		dfs(v,u);
		for(int j=0;j<=sz[u];j++)
			tmp2[j]=dp[u][j],dp[u][j]=0;
		for(int j=0;j<=sz[u];j++)
			for(int k=0;k<=sz[v];k++)
				dp[u][j+k]=addmod(dp[u][j+k]+1ll*tmp2[j]*dp[v][k]%mod1,mod1);
		sz[u]+=sz[v];
	}
	dp[u][0]=0;
	dp[u][1]=addmod(dp[u][1]+1,mod1);
}
int main()
{
	pw1[0]=pw2[0]=1;
	for(int i=1;i<=pn;i++)
	{
		pw1[i]=1ll*pw1[i-1]*bs%mod1;
		pw2[i]=1ll*pw2[i-1]*bs%mod2;
	}
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
		{
			scanf("%d",&e2[i][j].w);
			e2[i][j].v=j;
		}
	for(int i=1;i<=n;i++)
		sort(e2[i]+1,e2[i]+n+1),p[i].id=i;
	for(int i=1;i<=2*n;i++)
		f[i]=i;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			p[j].getadd(e2[j][i].v);
			mx[j]=e2[j][i].w;
			if(i<n) mn[j]=e2[j][i+1].w;
			else mn[j]=1e9;
			tmp[j]=p[j];
		}
		sort(tmp+1,tmp+n+1);
		for(int l=1,r;l<=n;l=r+1)
		{
			r=l;
			while(r<n&&tmp[l]==tmp[r+1]) r++;
			if(r-l+1==i)
			{
				int tmn=1e9,tmx=0;
				for(int j=l;j<=r;j++)
				{
					tmn=min(tmn,mn[tmp[j].id]);
					tmx=max(tmx,mx[tmp[j].id]);
				}
				if(tmx>tmn) continue;
				pt++;
				for(int j=l;j<=r;j++)
				{
					int u=tmp[j].id;
					if(a[u]&&find(a[u])!=find(pt))
					{
						link(a[u],pt);
						add(a[u],pt);
						add(pt,a[u]);
					}
					a[u]=pt;
				}
			}
		}
	}
	dfs(pt,0);
	for(int i=1;i<=n;i++)
		printf("%d ",dp[pt][i]);
	return 0;
}
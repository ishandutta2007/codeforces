#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
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
struct edge
{
	int v,x,y,nxt;
}e[2000005];
int T,n,prime[1000005],ptt,p[1000005],g[1000005],pn=1e6,h[500005],t,ct;
int dfn[1000005],sz[1000005],a[1000005];
struct pt
{
	int x,v;
	pt(int x=0,int v=0):x(x),v(v){}
	bool operator<(const pt p) const
	{
		return x==p.x?v>p.v:x<p.x;
	}
};
vector<pt> val[1000005];
void add(int u,int v,int x,int y)
{
	e[++t].v=v;
	e[t].x=x;
	e[t].y=y;
	e[t].nxt=h[u];
	h[u]=t;
}
void ins(int p,int x,int fl)
{
	while(x!=1)
	{
		int t=g[x],r=0;
		while(x%t==0) x/=t,r++;
		val[t].push_back(pt(p,fl*r));
	}
}
void dfs(int u,int fa)
{
	dfn[u]=++ct;
	sz[u]=1;
	for(int i=h[u];i;i=e[i].nxt)
	{
		int v=e[i].v,x=e[i].x,y=e[i].y;
		if(v==fa) continue;
		dfs(v,u);
		sz[u]+=sz[v];
		ins(dfn[v],y,1);
		ins(dfn[v],x,-1);
		ins(dfn[v]+sz[v],y,-1);
		ins(dfn[v]+sz[v],x,1);
	}
}
int main()
{
	for(int i=2;i<=pn;i++)
	{
		if(!p[i]) prime[++ptt]=i,g[i]=i;
		for(int j=1;j<=ptt&&i*prime[j]<=pn;j++)
		{
			g[i*prime[j]]=prime[j];
			p[i*prime[j]]=1;
			if(i%prime[j]==0) break;
		}
	}
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		t=ct=0;
		a[0]=1;
		for(int i=1;i<=n;i++)
		{
			h[i]=0;
			a[i]=1;
			val[i].clear();
		}
		for(int i=1;i<n;i++)
		{
			int u,v,x,y;
			scanf("%d%d%d%d",&u,&v,&x,&y);
			add(u,v,x,y);
			add(v,u,y,x);
		}
		dfs(1,0);
		for(int i=1;i<=n;i++)
			if(val[i].size())
			{
				int sz=val[i].size();
				sort(val[i].begin(),val[i].end());
				int nw=0,mn=0;
				for(int j=0;j<sz;j++)
				{
					nw+=val[i][j].v;
					mn=min(mn,nw);
				}
			//	printf("i=%d,nw=%d,mn=%d\n",i,nw,mn);
				int las=-1,inv=fpow(i,mod-2);
				a[0]=1ll*a[0]*fpow(i,-mn)%mod;
				for(int l=0,r;l<sz;l=r+1)
				{
					r=l;
					while(r+1<sz&&val[i][r+1].x==val[i][l].x) r++;
					nw=0;
					for(int j=l;j<=r;j++)
						nw+=val[i][j].v;
				///	printf("l=%d,r=%d,nw=%d,x=%d\n",l,r,nw,val[i][l].x);
					if(nw>0) a[val[i][l].x]=1ll*a[val[i][l].x]*fpow(i,nw)%mod;
					else a[val[i][l].x]=1ll*a[val[i][l].x]*fpow(inv,-nw)%mod;
				}
			}
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			a[i]=1ll*a[i]*a[i-1]%mod;
			ans=addmod(ans+a[i]);
		}
		printf("%d\n",ans);
	}
}
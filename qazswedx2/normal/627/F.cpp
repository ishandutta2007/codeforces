#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
struct edge
{
	int v,nxt;
}e[500005];
int n,k,a[200005],b[200005],h[200005],t,rt,d[200005],f[200005],ct,fl;
int st[200005],tp,q[200005],qt,dis[200005],vis[200005],srt;
void add(int u,int v)
{
	e[++t].v=v;
	e[t].nxt=h[u];
	h[u]=t;
}
void dfs1(int u,int fa,int dep)
{
	f[u]=fa;
	d[u]=dep;
	for(int i=h[u];i;i=e[i].nxt)
	{
		int v=e[i].v;
		if(v==fa) continue;
		dfs1(v,u,dep+1);
	}
}
void dfs3(int u,int fa)
{
	st[tp++]=u;
	//printf("dfs3:tp=%d,u=%d,fa=%d\n",tp,u,fa);
	for(int i=h[u];i;i=e[i].nxt)
	{
		int v=e[i].v;
		if(v==fa||a[v]==b[v]) continue;
		dfs3(v,u);
		return;
	}
}
void dfs2(int u,int fa)
{
	int q=0;
	for(int i=h[u];i;i=e[i].nxt)
	{
		int v=e[i].v;
		if(v==fa) continue;
		dfs2(v,u);
		if(fl>=2) return;
		if(a[v]!=b[v]) q++;
	}
	if(q&&a[u]==b[u])
	{
		if(q==1||q==2) fl++;
		if(q>=3) fl=2;
		if(fl>=2) return;
		srt=u;
		for(int i=h[u];i;i=e[i].nxt)
		{
			int v=e[i].v;
			if(v==fa||a[v]==b[v]) continue;
	//		printf("u=%d,v=%d\n",u,v);
			dfs3(v,u);
			if(q==2) reverse(st,st+tp);
		}
	}
}
void dfs4(int u,int fa)
{
	for(int i=h[u];i;i=e[i].nxt)
	{
		int v=e[i].v;
		if(vis[v]) continue;
		vis[v]=1;
		dis[v]=dis[u]+1;
		dfs4(v,u);
	}
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
		scanf("%d",&b[i]);
	for(int i=1;i<n;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		add(u,v);
		add(v,u);
	}
	for(int i=1;i<=n;i++)
		if(b[i]==0)
			rt=i;
	dfs1(rt,0,0);
	int u;
	for(int i=1;i<=n;i++)
		if(a[i]==0)
			u=i;
	int nw=u;
	while(nw!=rt)
	{
		q[qt++]=nw;
		swap(a[nw],a[f[nw]]);
		nw=f[nw];
	}
	q[qt++]=rt;
	for(int i=1;i<=n;i++)
		if(a[i]!=b[i])
			ct++;
	if(!ct)
	{
		printf("0 %d\n",d[u]);
		return 0;
	}
	dfs2(rt,0);
	//printf("fl=%d,tp=%d,ct=%d\n",fl,tp,ct);
	if(fl!=1||tp!=ct)
	{
		printf("-1\n");
		return 0;
	}
	for(int i=1;i<tp;i++)
		if(b[st[i]]==a[st[0]])
		{
			k=i;
			break;
		}
	for(int i=0;i<tp;i++)
		if(b[st[(i+k)%tp]]!=a[st[i]])
		{
			printf("-1\n");
			return 0;
		}
	if(d[st[0]]>=d[st[1]])
		printf("%d %d ",min(st[0],st[tp-1]),max(st[0],st[tp-1]));
	else printf("%d %d ",min(srt,st[tp-1]),max(srt,st[tp-1]));
	for(int i=0;i<qt;i++)
		dis[q[i]]=0,vis[q[i]]=1;
	for(int i=0;i<qt;i++)
		dfs4(q[i],0);
	int ffl=0;
	for(int i=0;i<tp;i++)
		if(dis[st[i]]==0)
			ffl=1;
	if(!ffl)
	{
		ll ans=d[u]+dis[srt]*2+1ll*min(k,tp-k)*(tp+1);
		printf("%lld\n",ans);
		return 0;
	}
/*	for(int i=0;i<tp;i++)
		printf("%d ",st[i]);
	printf("\n");
	printf("dis=%d,%d,k=%d\n",dis[st[tp-1]],d[st[tp-1]]-d[srt],k);*/
	k=tp-k;
	if(dis[st[tp-1]]<d[st[tp-1]]-d[srt])
	{
		int q=(d[st[tp-1]]-d[srt])-dis[st[tp-1]];
		ll ans=d[u]+min(1ll*k*(tp+1)-2*q,1ll*(tp-k)*(tp+1));
		printf("%lld\n",ans);
	}
	else
	{
		int q=(d[st[0]]-d[srt])-dis[st[0]];
		ll ans=d[u]+min(1ll*k*(tp+1),1ll*(tp-k)*(tp+1)-2*q);
		printf("%lld\n",ans);
	}
	return 0;
}
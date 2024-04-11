#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=3e5+5;

ll read()
{
	ll s=0;
	char c=getchar(),lc='+';
	while (c<'0'||'9'<c) lc=c,c=getchar();
	while ('0'<=c&&c<='9') s=s*10+c-'0',c=getchar();
	return lc=='-'?-s:s;
}
void write(ll x)
{
	if (x<0) putchar('-'),x=-x;
	if (x<10) putchar(x+'0');
	else write(x/10),putchar(x%10+'0');
}
void print(ll x,char c='\n')
{
	write(x);
	putchar(c);
}
struct edge
{
	ll to,id,nxt;
}e[N*2];
ll head[N],cnte=0;
void add_edge(ll u,ll v,ll w)
{
	e[++cnte].to=v;
	e[cnte].id=w;
	e[cnte].nxt=head[u];
	head[u]=cnte;
}
ll a[N],fa[N],n,m,x,sum=0;
ll q[N],t=0,st[N],top=0;
bool vis[N];
ll find(ll x)
{
	return fa[x]==x?x:fa[x]=find(fa[x]);
}
void dfs(ll now,ll father,ll id)
{
	if (vis[now]) return;
	vis[now]=1;
	for (ll i=head[now];i;i=e[i].nxt) dfs(e[i].to,now,e[i].id);
	if (!father) return;
	if (a[now]+a[father]>=x) q[++t]=id;
						else st[++top]=id;
	a[father]=a[now]+a[father]-x;
}

signed main(signed Recall,char *_902_[])
{
	(void)Recall,(void)_902_;
	n=read(),m=read(),x=read();
	for (ll i=1;i<=n;i++) sum+=a[i]=read();
	for (ll i=1;i<=n;i++) fa[i]=i;
	for (ll i=1;i<=m;i++)
	{
		ll u=read(),v=read();
		fa[find(u)]=find(v);
		add_edge(u,v,i);
		add_edge(v,u,i);
	}
	for (ll i=1;i<=n;i++) if (find(i)!=find(1)) return puts("NO"),0;
	if (sum<(n-1)*x) return puts("NO"),0;
	dfs(1,0,0);
	puts("YES");
	for (ll i=1;i<=t;i++) print(q[i]);
	while (top) print(st[top--]);
	
	return 0;
}